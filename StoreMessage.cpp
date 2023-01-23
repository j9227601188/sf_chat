#include "StoreMessage.h"

StoreMessage::StoreMessage() : _msgs(new vector<msg>) {};
StoreMessage::~StoreMessage() {	delete _msgs; }

// ������� ������ ��������� ��� ����� "name"
void StoreMessage::showMsgTo(string name)
{
    if (!_msgs->empty()) {
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == name) cout << (*_msgs)[i]._mess << endl;
        }
    } else cout << "� ���� ��� ���������" << endl;
    cout << string("��� ������ ��������� ��� ������������ ").append(name).append("\n");
}

// ������� ��������� ��� ����
void StoreMessage::showMessageAll() {
    if (!_msgs->empty()) {
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == "all") cout << (*_msgs)[i]._mess << endl;
        }
    }
    else cout << "� ���� ��� ���������" << endl;
}

// ������ ��������� �� ��������
void StoreMessage::setMessage(string message, string from, string to = "all") {
    _msgs->push_back(msg{ from, to, message });
}