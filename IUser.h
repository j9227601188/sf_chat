
/* ����������� �����-���������. ��� ������������ ����������� �� ����. */

#pragma once
#include <string>

// ��������� �����
class IUser {
public:
	virtual ~IUser() {};
	// ���� ����� ���������� � ������� ����� � ������
	virtual void Update(const std::string&) = 0;
};
