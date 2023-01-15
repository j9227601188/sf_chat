#pragma once
#include <string>
#include "IChat.h"
#include "IUser.h"

// ������� ��������
class User :public IUser {
	IChat* _chat;
	static int _total_users;	// ��� ���� ����� ��� ���� �������� User(User ID) 
	int _userID;				// ���������� ����� ����� �����������
public:
	User(IChat* chat);
	virtual ~User() {};
	void Update(const std::string& message_from_subject) override;
	void RemoveFromList();
};