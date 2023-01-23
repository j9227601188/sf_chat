/*
	Основные конструкции C++.
	Итоговое задание "Чат"
	Создайте чат со следующим функционалом:
		консольная программа;
		регистрация пользователей - логин, пароль, имя;
		вход в чат по логину/паролю;
		отправка сообщений конкретному пользователю;
		обмен сообщениями между всеми пользователями чата одновременно;
		Обязательным условием является использование классов.
*/

// TODO надо ещё:
// 1 класс для хранения сообщений;
// 2 класс сообщений;
// 3 класс Shared_ptr;
// 4 проверка пользовательского ввода - сделано;
// 5 класс для обработки исключений;
// 6 заменить vector на свой класс(и может быть list тоже заменить?)
// 7 абстрактный класс/интерфейс IStore и от него унаследовать все хранилища


// отслеживание утечек памяти(раскомментить следующую строчку)
#define _CRTDBG_MAP_ALLOC
#ifdef _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif  _CRTDBG_MAP_ALLOC


// библиотеки для работы программы
#include <iostream>
#include <string>
#include <locale>

#include "Chat.h"
#include "User.h"
#include "StoreUsers.h"
#include "StoreMessage.h"
#include "Utils.h"

using namespace std;

void Hello(Chat*, StoreUsers*);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru-RU");										// русский
#ifdef _CRTDBG_MAP_ALLOC
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// отслеживание утечек памяти
#endif  _CRTDBG_MAP_ALLOC

	StoreUsers* su1 = new StoreUsers;
	StoreMessage* sm1 = new StoreMessage;
	Chat* ch1 = new Chat(su1, sm1);
	Hello(ch1, su1);
	su1->showUsers();

	cout << "\n\nend main\n";

	delete su1;
	delete ch1;

	return 0;
}

// сюда пользователь попадает при запуске программы и при выходе из чата
void Hello(Chat* chat, StoreUsers* su) {

	string name;				// имя/логин пользователя
	string pass;				// пароль пользователя
	const size_t size{ 1024 };	// размер буфера пользовательского ввода
	char s[size]{};				// буфер пользовательского ввода

	while (true)
	{
		std::cout << "\tЧат.\n 1. Войти.\n 2. Зарегистрироваться.\n 3. Выйти из программы.\n";

		cin.getline(s, size);							// считывает до \n без \n !!!

		size_t counter = count(s);						// счётчик введённых символов
		if (counter == 1) {
			if (s[0] != '1' && s[0] != '2' && s[0] != '3') {
				s[0] = 0;
				cout << "\nChoose 1,2 or 3\n\n";
				continue;								// если это не 1, 2 или 3
			}
		} 
		else {
			for (size_t i = 0; i < 1024; ++i) s[i] = 0;
			cout << "\nChoose 1,2 or 3\n\n";
			continue;									// если введено больше одного символа
		}		

		switch (s[0])
		{
		case '1':
			do {
				cout << "\nВход в чат\nВведите имя(не более восьми символов, цифры и латиница): ";
			} while (!enter(&name));
			cout << "\nName: " << name;

			do {

			cout << "\nВведите пароль(не более восьми символов, цифры и латиница): ";
			} while (!enter(&pass));
			cout << "\nPassword: " << pass;

			if (su->checkLogin(name, pass)) {			// если существует(Store - класс хранилка с методами)
				new User(chat, name);
				// вход в чат после ввода логина и пароля здесь
				chat->Notify();
			}
			else cout << "\nНет такого пользователя.\n";
			name.clear();
			pass.clear();
			break;

		case '2':
			do {
				cout << "\nРегистрация пользователя:\nВведите имя(не более восьми символов, цифры и латиница): ";
			} while (!enter(&name));
			cout << "\nName: " << name;

			do {
				cout << "\nВведите пароль(не более восьми символов, цифры и латиница): ";
			} while (!enter(&pass));
			cout << "\nPassword: " << pass;

			if (su->checkName(name)) {					// если существует
				cout << "\nТакой пользователь уже есть";
				name.clear();
				pass.clear();
			}
			else {
				su->toStore(name, pass);				// сохраняем имя и пароль нового пользователя
				new User(chat, name);							// заносим юзера в список этого чата
				cout << "\nEnd registration\n";
				// вход в чат после регистрации здесь
				chat->Notify();
			}
			break;

		case '3':
			cout << "\nExit switch/case\n";
			return;

		default:
			cout << "\nChoose 1,2 or 3\n";
			break;
		}
	}
}
