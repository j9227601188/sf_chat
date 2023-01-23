
#include <iostream>
#include "Chat.h"
#include "User.h"
using namespace std;

User::User(IChat* chat, string name) : _chat(chat), _name(name)
{
	_chat->Attach(this);				// ������� ���� � ������ ��������	
	cout << _name << " ����� � ���." << endl;
}

User::~User()
{
	cout << "����: " << _name << " �����.\n";
}

/* ���� ����� ����������� � �����������.��� ��� ������ �� Chat(��������� ��������� Message) �������� �������� ������ ������ User!!! */
// ����� ��������� � ��� ��� ��� ���� ������
void User::Update(const string& message_from_chat)	// 
{
	cout << "I`m user �" << _name << " ������� ���������: " << message_from_chat << endl;
}

//��� ���� ������� ���� �� ������ �������� (����� �� ����, �������, ����� ���� � �������)
void User::RemoveFromList()
{
	_chat->Detach(this);
	cout << "���� " << _name << " ����� �� ������ ��������\n";
}

std::string User::getUserName() { return _name; }
