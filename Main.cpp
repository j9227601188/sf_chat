/*
	�������� ����������� C++.
	�������� ������� "���"
	�������� ��� �� ��������� ������������:
		���������� ���������;
		����������� ������������� - �����, ������, ���;
		���� � ��� �� ������/������;
		�������� ��������� ����������� ������������;
		����� ����������� ����� ����� �������������� ���� ������������;
		������������ �������� �������� ������������� �������.
*/

// TODO ���� ���:
// 1 ����� ��� �������� ���������;
// 2 ����� ���������;
// 3 ����� Shared_ptr;
// 4 �������� ����������������� ����� - �������;
// 5 ����� ��� ��������� ����������;
// 6 �������� vector �� ���� �����(� ����� ���� list ���� ��������?)
// 7 ����������� �����/��������� IStore � �� ���� ������������ ��� ���������


// ������������ ������ ������(������������� ��������� �������)
#define _CRTDBG_MAP_ALLOC
#ifdef _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif  _CRTDBG_MAP_ALLOC


// ���������� ��� ������ ���������
#include <iostream>
#include <string>
#include <locale>

#include "Chat.h"
#include "User.h"
#include "StoreUsers.h"
#include "StoreMessage.h"
#include "Utils.h"

using namespace std;

void Hello(Chat*, StoreUsers*);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru-RU");										// �������
#ifdef _CRTDBG_MAP_ALLOC
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);	// ������������ ������ ������
#endif  _CRTDBG_MAP_ALLOC

	StoreUsers* su1 = new StoreUsers;
	StoreMessage* sm1 = new StoreMessage;
	Chat* ch1 = new Chat(su1, sm1);
	Hello(ch1, su1);
	su1->showUsers();

	cout << "\n\nend main\n";

	delete su1;
	delete ch1;

	return 0;
}

// ���� ������������ �������� ��� ������� ��������� � ��� ������ �� ����
void Hello(Chat* chat, StoreUsers* su) {

	string name;				// ���/����� ������������
	string pass;				// ������ ������������
	const size_t size{ 1024 };	// ������ ������ ����������������� �����
	char s[size]{};				// ����� ����������������� �����

	while (true)
	{
		std::cout << "\t���.\n 1. �����.\n 2. ������������������.\n 3. ����� �� ���������.\n";

		cin.getline(s, size);							// ��������� �� \n ��� \n !!!

		size_t counter = count(s);						// ������� �������� ��������
		if (counter == 1) {
			if (s[0] != '1' && s[0] != '2' && s[0] != '3') {
				s[0] = 0;
				cout << "\nChoose 1,2 or 3\n\n";
				continue;								// ���� ��� �� 1, 2 ��� 3
			}
		} 
		else {
			for (size_t i = 0; i < 1024; ++i) s[i] = 0;
			cout << "\nChoose 1,2 or 3\n\n";
			continue;									// ���� ������� ������ ������ �������
		}		

		switch (s[0])
		{
		case '1':
			do {
				cout << "\n���� � ���\n������� ���(�� ����� ������ ��������, ����� � ��������): ";
			} while (!enter(&name));
			cout << "\nName: " << name;

			do {

			cout << "\n������� ������(�� ����� ������ ��������, ����� � ��������): ";
			} while (!enter(&pass));
			cout << "\nPassword: " << pass;

			if (su->checkLogin(name, pass)) {			// ���� ����������(Store - ����� �������� � ��������)
				new User(chat, name);
				// ���� � ��� ����� ����� ������ � ������ �����
				chat->Notify();
			}
			else cout << "\n��� ������ ������������.\n";
			name.clear();
			pass.clear();
			break;

		case '2':
			do {
				cout << "\n����������� ������������:\n������� ���(�� ����� ������ ��������, ����� � ��������): ";
			} while (!enter(&name));
			cout << "\nName: " << name;

			do {
				cout << "\n������� ������(�� ����� ������ ��������, ����� � ��������): ";
			} while (!enter(&pass));
			cout << "\nPassword: " << pass;

			if (su->checkName(name)) {					// ���� ����������
				cout << "\n����� ������������ ��� ����";
				name.clear();
				pass.clear();
			}
			else {
				su->toStore(name, pass);				// ��������� ��� � ������ ������ ������������
				new User(chat, name);							// ������� ����� � ������ ����� ����
				cout << "\nEnd registration\n";
				// ���� � ��� ����� ����������� �����
				chat->Notify();
			}
			break;

		case '3':
			cout << "\nExit switch/case\n";
			return;

		default:
			cout << "\nChoose 1,2 or 3\n";
			break;
		}
	}
}
