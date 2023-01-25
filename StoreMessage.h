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
		string _from;		// �� ����
		string _to;			// ����
		string _mess;		// ���������
	};

	vector<msg>* _msgs;		// ������ �������� ���������

public:
	StoreMessage();
	~StoreMessage();

	void showMsgTo(string name);				// ������ ��������� ��� ����� �����
	void showMessageAll();						// ��������� ��� ����
	void setMessage(string, string, string);	// ������ ��������� � ��������. ���� �� ������� ����, �� ����
};

