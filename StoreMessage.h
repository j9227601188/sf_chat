/*
����� ��� �������� ���������. ����� ������ ���� ����� DB ����������.
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
		string _from;	// �� ����
		string _to;		// ����/��� ��� "all" - ��� ����
		string _mess;	// ���������
	};

	vector<msg>* _msgs;	// ������ �������� msg

public:
	StoreMessage();
	~StoreMessage();

	void showMsgTo(string name);	// ������ ��������� ��� ����� �����
	void showMessageAll();			// ��������� ��� ����
	void setMessage(string message, string from, string to = "all");	// ������ ��������� � ��������. ���� �� ������� ����, �� ����
};

