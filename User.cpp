
#include <iostream>
#include "Chat.h"
#include "User.h"
using namespace std;

User::User(IChat* chat, string name) : _chat(chat), _name(name)
{
	_chat->Attach(this);				// заносим себя в список рассылки	
	cout << _name << " вошёл в чат." << endl;
}

User::~User()
{
	cout << "Юзер: " << _name << " удалён.\n";
}

/* ЭТОТ МЕТОД ЦЕНТРАЛЬНЫЙ В НАБЛЮДАТЕЛЕ.При его вызове из Chat(получении сообщения Message) начинает работать логика класса User!!! */
// вывод сообщения в чат или ещё чего нибудь
void User::Update(const string& message_from_chat)	// 
{
	cout << "I`m user №" << _name << " Получил сообщение: " << message_from_chat << endl;
}

//сам юзер убирает себя из списка рассылки (выход из чата, очистка, вывод меню в консоль)
void User::RemoveFromList()
{
	_chat->Detach(this);
	cout << "Юзер " << _name << " удалён из списка рассылки\n";
}

std::string User::getUserName() { return _name; }
