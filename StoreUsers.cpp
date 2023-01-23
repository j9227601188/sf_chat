
/**/
#include <iostream>
#include "StoreUsers.h"

StoreUsers::StoreUsers() :_u(new vector<sUser>) {}

StoreUsers::~StoreUsers()
{
    delete _u;
}

// ������ ������ � ������ � �����.
// true - ���� ����� ���� �����/������ ���� � ����. 
bool StoreUsers::checkLogin(string name, string pass)
{
    if(_u->empty()) return false;
    for (size_t i = 0; i < _u->size(); ++i) {
        if ((*_u)[i]._name == name && (*_u)[i]._pass == pass) return true;
    }
    return false;
}

// �������� ������������ �����
// true - ���� ����� ��� ��� ����
bool StoreUsers::checkName(string name)
{
    if (_u->empty()) return false;
    for (size_t i = 0; i < _u->size(); ++i) {
        if ((*_u)[i]._name == name) return true;
    }
    return false;
}

// ������� ������ ����� � ����
void StoreUsers::toStore(string name, string pass)
{
    _u->push_back(sUser{name, pass});
}

// ������� ������ ���� ������ �� ����
void  StoreUsers::showUsers() {
    if (_u->empty()) { 
        cout << "������������������ ������������� ���";
        return; 
    }
    cout << "���������� ������������������ �������������: " << _u->size();
    for (size_t i = 0; i < _u->size(); ++i) {
        std::cout << "\n������������: " << (*_u)[i]._name << "\n������: " << (*_u)[i]._pass << "\n\n";
    }
}