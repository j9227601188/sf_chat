
/* 
	����������� �����-��������� ������������. ��� ������������ ����������� �� ����. 
*/

#pragma once
#include <string>
#include "IChat.h"

// ��������� �����
class IUser {
public:
	virtual ~IUser() {};
	virtual std::string getUserName() = 0;
};
