/* ����� ���
	������ ������ ������
	��������� ��������� 
*/
#include <iostream>
#include "Chat.h"
#include "User.h"
#include "StoreUsers.h"
#include "StoreMessage.h"

Chat::Chat(StoreUsers* su, StoreMessage* sm) :_su(su), _sm(sm) {}

Chat::~Chat()
{
	cout << "\n��� �����\n ";
	list<IUser* >::iterator iterator = user_list.begin();	// ������������� ������������� �� ������ ������ � ������
	if (user_list.empty()) return;							// ���� ������ ������
	while (iterator != user_list.end())						// ���� �� ���� �������� � ������
	{
		delete (*iterator);									// ������� ���� ������ (�������� ���������� ~User)
		++iterator;
	}

}

// ������� ����� � ������ ��������
void Chat::Attach(IUser* user) {
	user_list.push_back(user);
}

// ������� ����� �� ������ ��������
void Chat::Detach(IUser* user)
{
	user_list.remove(user);
}

// ���� ����� ����������� � ���� !!!. �������� ����� Update � ���� �������� � ������
void Chat::Notify()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n�� ����� � ���\n";
	//_sm->showMessage();		// ������� ����� ��� ��������� ���� � ������
	//cin.getline()
	/* ��� ����� ��� ������ ����!!! ���� �������� ���� ����� ����� � ���!!!*/
// ����� ��������� ���� ��������. ���� ������� ��������� �� �������� � ���� ������ ���������. (��� �������: �� Update ������ User �������� ��������� �� ��������)
	list<IUser* >::iterator iterator = user_list.begin();	// ������������� ������������� �� ������ ������ � ������
	while (iterator != user_list.end())						// ���� �� ���� �������� � ������
	{
		(*iterator)->Update("Message to all users");		// ������ ������ user � �������� � �� ����� Update, ������� ���� ����� Message
		++iterator;
	}
}

