
#include <iostream>
#include "Chat.h"
#include "User.h"
using namespace std;

User::User(IChat* chat) : _chat(chat)
{
	_chat->Attach(this);				// заносим себя в список рассылки	
	_userID = ++_total_users;			// сначала увеличиваем на 1, потом присваиваем!!! _total_users - сохраняет новое значение
	cout << "Я получатель номер " << _userID << endl;
}

/* ЭТОТ МЕТОД ЦЕНТРАЛЬНЫЙ В НАБЛЮДАТЕЛЕ.При его вызове из Chat(получении сообщения Message) начинает работать логика класса User!!! */
// вывод сообщения в чат или ещё чего нибудь
void User::Update(const string& message_from_chat)	// 
{
	cout << "I`m user №" << _userID << " Получил сообщение: " << message_from_chat << endl;
}

//сам юзер убирает себя из списка рассылки (выход из чата, очистка, вывод меню в консоль)
void User::RemoveFromList()
{
	_chat->Detach(this);
	cout << "Наблюдатель " << _userID << " удалён из списка рассылки\n";
}

int User::_total_users = 0;	// инициализация статической переменной