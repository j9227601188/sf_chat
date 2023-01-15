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

// TODO надо ещё класс для хранения сообщений 


// отслеживание утечек памяти(раскомментить следующую строчку)
#define _CRTDBG_MAP_ALLOC
#ifdef _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <vector>
#include "Chat.h"
#include "User.h"

#endif  _CRTDBG_MAP_ALLOC


// библиотеки для работы программы
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru-RU");										// русский
#ifdef _CRTDBG_MAP_ALLOC
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// отслеживание утечек памяти
#endif  _CRTDBG_MAP_ALLOC

	Chat* ch1 = new Chat;
	User* user1 = new User(ch1);
	User* user2 = new User(ch1);
	User* user3 = new User(ch1);
	User* user4 = new User(ch1);

	ch1->Notify(/* здесь рассылаем сообщения */);

	delete ch1;
	delete user1;
	delete user2;
	delete user3;
	delete user4;

	cout << "\n\nend main\n";
	return 0;
}
