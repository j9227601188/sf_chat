/*
	Паттерн Наблюдатель
Назначение: Создаёт механизм подписки, позволяющий одним объектам следить и
реагировать на события, происходящие в других объектах.
 */

#pragma once
#include <list>
#include "IChat.h"
#include "IUser.h"
#include "StoreUsers.h"
#include "StoreMessage.h"

using namespace std;

// чат рассылает
class Chat :public IChat {
	StoreUsers* _su;			// логин/пароль всех юзеров
	StoreMessage* _sm;			// все сообщения
	list <IUser* > user_list;	// список объектов юзеров выполнивших вход в этот чат
public:
	Chat() = default;
	Chat(StoreUsers*, StoreMessage*);
	virtual ~Chat();
	void Attach(IUser* user) override;
	void Detach(IUser* user) override;
	void Notify() override;
	//void Hello();
};