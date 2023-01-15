
/* ����������� �����-���������. ��� ������ ����� ����������� �� ����. */

#pragma once
#include "IUser.h"

// ��������� ����
class IChat {
public:
	virtual ~IChat() {};
	virtual void Attach(IUser*) = 0;	// ��������� �����(������� � ������)
	virtual void Detach(IUser*) = 0;	// �������� �����(������� �� ������)
	virtual void Notify() = 0;			// ������� ��������� ���� ������ � ������
};
