
/* 
	Абстрактный класс-интерфейс пользователя. Все пользователи наследуются от него. 
*/

#pragma once
#include <string>
#include "IChat.h"

// интерфейс юзера
class IUser {
public:
	virtual ~IUser() {};
	virtual std::string getUserName() = 0;
};
