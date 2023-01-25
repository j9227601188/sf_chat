/*
Класс для хранения сообщений. Потом вместо него можно DB прикрутить.
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "User.h"

using namespace std;

class StoreMessage
{
	struct msg {
		string _from;		// от кого
		string _to;			// кому
		string _mess;		// сообщение
	};

	vector<msg>* _msgs;		// массив структур сообщение

public:
	StoreMessage();
	~StoreMessage();

	void showMsgTo(string name);				// личные сообщения для этого юзера
	void showMessageAll();						// сообщения для всех
	void setMessage(string, string, string);	// запись сообщения в хранилку. если не указано кому, то всем
};

