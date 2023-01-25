
#include <iostream>
#include "Chat.h"
#include "User.h"
using namespace std;

User::User(IChat* chat, string name) : _chat(chat), _name(name)
{
	_chat->Attach(this);				// заносим себ€ в список участников чата	
	cout << "\n< " << _name << " > вошЄл в чат." << "\n\n";
}

User::~User()
{
	RemoveFromList();
	cout << "\n< " << _name << " > вышЄл из чата." << "\n\n";
}

// удаление из списка(list) участников чата, выход из чата
void User::RemoveFromList()
{
	_chat->Detach(this);
	//cout << "ёзер " << _name << " удалЄн из списка.\n";
}

std::string User::getUserName() { return _name; }