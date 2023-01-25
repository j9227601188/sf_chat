
/* 
����� ������������ 
*/

#pragma once
#include <string>
#include "IChat.h"
#include "IUser.h"

class User :public IUser {

	IChat* _chat;						// � ����� ���� ������
	std::string _name;					// ��� ������������

public:
	User(IChat* chat, std::string name);
	virtual ~User();
	void RemoveFromList();				// ����� �� ����
	std::string getUserName() override;
};