
/* 
	����� ���
*/

#include <iostream>
#include "Chat.h"
#include "User.h"
#include "StoreUsers.h"
#include "StoreMessage.h"
#include "Utils.h"

using namespace std;

Chat::Chat(StoreUsers* su, StoreMessage* sm) :_su(su), _sm(sm) {}

Chat::~Chat()
{
	//cout << "\n��� �����\n ";
	list<IUser* >::iterator iterator = user_list.begin();	// ������������� ������������� �� ������ ������ � ������
	if (user_list.empty()) return;							// ���� ������ ������, ������ ������� �� ����
	while (iterator != user_list.end())						// ���� �� ���� �������� � ������
	{
		delete (*iterator);									// ������� ���� ������ (�������� ���������� ~User)
		++iterator;
	}
}

// ������� ����� � ������ ��������
void Chat::Attach(IUser* user) { user_list.push_back(user); }

// ������� ����� �� ������ ��������
void Chat::Detach(IUser* user) { user_list.remove(user); }

// ���� ����� ����������� � ���� !!!
void Chat::Notify()
{
	_sm->showMessageAll();									// ������� ����� ����� ��������� ����
	list<IUser* >::iterator iterator = --user_list.end();	// ������������� ������������� �� ��������� ������ � ������
	string user = (*iterator)->getUserName();
	_sm->showMsgTo(user);									// ������� ����� ������ ���������

	cout << "\n� ������ \"����:\" ��������� ��� ���� ��������� ������. �������� ������ �����.\n \"exit\" ��� ������ �� ����.\n";
	const size_t size{ 1024 };		// ������ ������ ����������������� �����
	char buff[size]{};				// ����� ����������������� �����

	while (true) {
		cout << "����: ";
		cin.getline(buff, size);
		string to = string(buff);
		for (size_t i = 0; i < 1024; ++i) buff[i] = 0;		// ������� ������ �����

		cout << "< " << user << " > ";
		cin.getline(buff, size);
		string message = string(buff);
		for (size_t i = 0; i < 1024; ++i) buff[i] = 0;		// ������� ������ �����

		if (message == "exit" || message == "quit") break;	// ����� �� ����
		_sm->setMessage(user, to, message);					// ����� � ����
	}

	delete (*iterator);		// ������� ������������ �� ����	
	//cout << "Users in chat : " << user_list.size() << endl;
}

// �������� ��� ���� ���� ��� ����� � ���
bool Chat::UserInChat(string& name)
{
	list<IUser* >::iterator iterator = user_list.begin();	// ������������� ������������� �� ������ ������ � ������
	while (iterator != user_list.end())						// ���� �� ���� �������� � ������
	{
		if ((*iterator)->getUserName() == name) return true;// ���� ����� ���� � ���� ���� ������
		++iterator;
	}
	return false;
}

