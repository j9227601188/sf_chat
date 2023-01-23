
/**/
#include <iostream>
#include "StoreUsers.h"

StoreUsers::StoreUsers() :_u(new vector<sUser>) {}

StoreUsers::~StoreUsers()
{
    delete _u;
}

// сверка логина и парол€ с базой.
// true - если така€ пара логин/пароль есть в базе. 
bool StoreUsers::checkLogin(string name, string pass)
{
    if(_u->empty()) return false;
    for (size_t i = 0; i < _u->size(); ++i) {
        if ((*_u)[i]._name == name && (*_u)[i]._pass == pass) return true;
    }
    return false;
}

// проверка уникальности имени
// true - если такое им€ уже есть
bool StoreUsers::checkName(string name)
{
    if (_u->empty()) return false;
    for (size_t i = 0; i < _u->size(); ++i) {
        if ((*_u)[i]._name == name) return true;
    }
    return false;
}

// занести нового юзера в базу
void StoreUsers::toStore(string name, string pass)
{
    _u->push_back(sUser{name, pass});
}

// вывести данные всех юзеров из базы
void  StoreUsers::showUsers() {
    if (_u->empty()) { 
        cout << "«арегистрированных пользователей нет";
        return; 
    }
    cout << " оличество зарегистрированных пользователей: " << _u->size();
    for (size_t i = 0; i < _u->size(); ++i) {
        std::cout << "\nѕользователь: " << (*_u)[i]._name << "\nѕароль: " << (*_u)[i]._pass << "\n\n";
    }
}