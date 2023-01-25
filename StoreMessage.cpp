#include "StoreMessage.h"

StoreMessage::StoreMessage() : _msgs(new vector<msg>) {};
StoreMessage::~StoreMessage() {	delete _msgs; }

// ������� ������ ��������� ��� ����� "name"
void StoreMessage::showMsgTo(string name)
{
    if (!_msgs->empty()) {
        cout << string("\n������ ��������� ��� ������������ ").append(name).append(" :\n");
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == name) {
                cout << "From < " << (*_msgs)[i]._from << " > " << (*_msgs)[i]._mess << endl;
            }
        }
    }
}

// ������� ��������� ��� ����
void StoreMessage::showMessageAll() {
    if (!_msgs->empty()) {
        cout << "��������� ��� ����:\n";
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == "") cout << (*_msgs)[i]._mess << endl;
        }
    }
}

// ������ ��������� �� ��������
void StoreMessage::setMessage(string from, string to, string message) {
    _msgs->push_back(msg{ from, to, message });
}