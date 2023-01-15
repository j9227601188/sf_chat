/*
	������� �����������
����������: ������ �������� ��������, ����������� ����� �������� ������� �
����������� �� �������, ������������ � ������ ��������.
 */

#pragma once
#include <list>
#include "IChat.h"
#include "IUser.h"
using namespace std;

// ��� ���������
class Chat :public IChat {
	list <IUser* > user_list;	// ������ ������
public:
	Chat() = default;
	virtual ~Chat() {};
	void Attach(IUser* user) override;
	void Detach(IUser* user) override;
	void Notify() override;
};