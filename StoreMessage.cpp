#include "StoreMessage.h"

StoreMessage::StoreMessage() : _msgs(new vector<msg>) {};
StoreMessage::~StoreMessage() {	delete _msgs; }

// вывести личные сообщения для юзера "name"
void StoreMessage::showMsgTo(string name)
{
    if (!_msgs->empty()) {
        cout << string("\nЛичные сообщения для пользователя ").append(name).append(" :\n");
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == name) {
                cout << "From < " << (*_msgs)[i]._from << " > " << (*_msgs)[i]._mess << endl;
            }
        }
    }
}

// вывести сообщения для всех
void StoreMessage::showMessageAll() {
    if (!_msgs->empty()) {
        cout << "Сообщения для всех:\n";
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == "") cout << (*_msgs)[i]._mess << endl;
        }
    }
}

// запись сообщений на хранение
void StoreMessage::setMessage(string from, string to, string message) {
    _msgs->push_back(msg{ from, to, message });
}