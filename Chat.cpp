/* ����� ���
	������ ������ ������
	��������� ��������� 
*/
#include "Chat.h"
#include "User.h"

// ������� ����� � ������ ��������
void Chat::Attach(IUser* user) {
	user_list.push_back(user);
}

// ������� ����� �� ������ ��������
void Chat::Detach(IUser* user)
{
	user_list.remove(user);
}

// ���� ����� ����������� � ���� !!!. �������� ����� Update � ���� � ������ ��������
void Chat::Notify()
{
	/* ��� ����� ��� ������ ���� */
// ����� ��������� ���� ��������.
	list<IUser* >::iterator iterator = user_list.begin();	// ������������� ������������� �� ������ ������ � ������
	while (iterator != user_list.end())						// ���� �� ���� �������� � ������
	{
		(*iterator)->Update("Message to all users");		// ������ ������ user � �������� � �� ����� Update, ������� ���� ����� Message
		++iterator;
	}
}