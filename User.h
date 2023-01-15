#pragma once
#include <string>
#include "IChat.h"
#include "IUser.h"

// адресат получает
class User :public IUser {
	IChat* _chat;
	static int _total_users;	// это поле общее для всех объектов User(User ID) 
	int _userID;				// порядковый номер этого наблюдателя
public:
	User(IChat* chat);
	virtual ~User() {};
	void Update(const std::string& message_from_subject) override;
	void RemoveFromList();
};