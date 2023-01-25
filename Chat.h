/*
	����� ���
*/

#pragma once
#include <list>
#include "IChat.h"
#include "IUser.h"
#include "StoreUsers.h"
#include "StoreMessage.h"

using namespace std;

class Chat :public IChat {

	StoreUsers* _su;			// DB �����/������ ���� ������
	StoreMessage* _sm;			// DB ��� ���������
	list <IUser* > user_list;	// ������ ������ ����������� ���� � ���� ���

public:
	Chat() = default;
	Chat(StoreUsers*, StoreMessage*);
	virtual ~Chat();
	void Attach(IUser* user) override;	// �������� � ���
	void Detach(IUser* user) override;	// ������ �� ����
	void Notify() override;				// �������� ���� ����� ���������
	bool UserInChat(string& name);		// ��������, ��� ������������ ��� � ����
};