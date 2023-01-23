#include "StoreMessage.h"

StoreMessage::StoreMessage() : _msgs(new vector<msg>) {};
StoreMessage::~StoreMessage() {	delete _msgs; }

// вывести личные сообщени€ дл€ юзера "name"
void StoreMessage::showMsgTo(string name)
{
    if (!_msgs->empty()) {
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == name) cout << (*_msgs)[i]._mess << endl;
        }
    } else cout << "¬ базе нет сообщений" << endl;
    cout << string("Ќет личных сообщений дл€ пользовател€ ").append(name).append("\n");
}

// вывести сообщени€ дл€ всех
void StoreMessage::showMessageAll() {
    if (!_msgs->empty()) {
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == "all") cout << (*_msgs)[i]._mess << endl;
        }
    }
    else cout << "¬ базе нет сообщений" << endl;
}

// запись сообщений на хранение
void StoreMessage::setMessage(string message, string from, string to = "all") {
    _msgs->push_back(msg{ from, to, message });
}