
/* Абстрактный класс-интерфейс. Все пользователи наследуются от него. */

#pragma once
#include <string>

// интерфейс юзера
class IUser {
public:
	virtual ~IUser() {};
	// этот метод вызывается у каждого юзера в списке
	virtual void Update(const std::string&) = 0;
};
