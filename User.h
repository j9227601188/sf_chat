#pragma once
#include <string>
#include "IChat.h"
#include "IUser.h"

// ������� ��������
class User :public IUser {
private:
	IChat* _chat;				// � ����� ���� ������
	std::string _name;			// ��� ������������
public:
	User(IChat* chat, std::string name);
	virtual ~User();
	void Update(const std::string& message_from_subject) override;
	void RemoveFromList();
	std::string getUserName();
};