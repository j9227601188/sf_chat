/*
	Паттерн Наблюдатель
Назначение: Создаёт механизм подписки, позволяющий одним объектам следить и
реагировать на события, происходящие в других объектах.
 */

#pragma once
#include <list>
#include "IChat.h"
#include "IUser.h"
using namespace std;

// чат рассылает
class Chat :public IChat {
	list <IUser* > user_list;	// список юзеров
public:
	Chat() = default;
	virtual ~Chat() {};
	void Attach(IUser* user) override;
	void Detach(IUser* user) override;
	void Notify() override;
};