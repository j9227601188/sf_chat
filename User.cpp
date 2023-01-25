
#include <iostream>
#include "Chat.h"
#include "User.h"
using namespace std;

User::User(IChat* chat, string name) : _chat(chat), _name(name)
{
	_chat->Attach(this);				// ������� ���� � ������ ���������� ����	
	cout << "\n< " << _name << " > ����� � ���." << "\n\n";
}

User::~User()
{
	RemoveFromList();
	cout << "\n< " << _name << " > ����� �� ����." << "\n\n";
}

// �������� �� ������(list) ���������� ����, ����� �� ����
void User::RemoveFromList()
{
	_chat->Detach(this);
	//cout << "���� " << _name << " ����� �� ������.\n";
}

std::string User::getUserName() { return _name; }