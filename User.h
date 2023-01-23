#pragma once
#include <string>
#include "IChat.h"
#include "IUser.h"

// адресат получает
class User :public IUser {
private:
	IChat* _chat;				// в каком чате сейчас
	std::string _name;			// имя пользователя
public:
	User(IChat* chat, std::string name);
	virtual ~User();
	void Update(const std::string& message_from_subject) override;
	void RemoveFromList();
	std::string getUserName();
};