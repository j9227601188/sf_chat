/* 
	����� ��� �������� ��� ���/������. ����� ������ ���� ����� DB ����������. 
*/

#pragma once
#include <vector>
#include <string>

using namespace std;

class StoreUsers
{
	struct sUser {
		string _name;
		string _pass;
	};

	vector<sUser>* _u;

public:
	StoreUsers();
	~StoreUsers();
	bool checkLogin(string name, string pass);	// ����
	bool checkName(string& name);				// �����������(�������� ������������ �����)
	void toStore(string name, string pass);		// ������� ����� � ����
	void showUsers();							// ������� ���� ������ � ���� � �������
};

