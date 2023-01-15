
#include <iostream>
#include "Chat.h"
#include "User.h"
using namespace std;

User::User(IChat* chat) : _chat(chat)
{
	_chat->Attach(this);				// ������� ���� � ������ ��������	
	_userID = ++_total_users;			// ������� ����������� �� 1, ����� �����������!!! _total_users - ��������� ����� ��������
	cout << "� ���������� ����� " << _userID << endl;
}

/* ���� ����� ����������� � �����������.��� ��� ������ �� Chat(��������� ��������� Message) �������� �������� ������ ������ User!!! */
// ����� ��������� � ��� ��� ��� ���� ������
void User::Update(const string& message_from_chat)	// 
{
	cout << "I`m user �" << _userID << " ������� ���������: " << message_from_chat << endl;
}

//��� ���� ������� ���� �� ������ �������� (����� �� ����, �������, ����� ���� � �������)
void User::RemoveFromList()
{
	_chat->Detach(this);
	cout << "����������� " << _userID << " ����� �� ������ ��������\n";
}

int User::_total_users = 0;	// ������������� ����������� ����������