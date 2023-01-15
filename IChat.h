
/* Абстрактный класс-интерфейс. Все классы чатов наследуются от него. */

#pragma once
#include "IUser.h"

// интерфейс чата
class IChat {
public:
	virtual ~IChat() {};
	virtual void Attach(IUser*) = 0;	// подписать юзера(занести в список)
	virtual void Detach(IUser*) = 0;	// отписать юзера(удалить из списка)
	virtual void Notify() = 0;			// послать сообщение всем юзерам в списке
};
