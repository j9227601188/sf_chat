#include "StoreMessage.h"

StoreMessage::StoreMessage() : _msgs(new vector<msg>) {};
StoreMessage::~StoreMessage() {	delete _msgs; }

// âûâåñòè ëè÷íûå ñîîáùåíèÿ äëÿ þçåðà "name"
void StoreMessage::showMsgTo(string name)
{
    if (!_msgs->empty()) {
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == name) cout << (*_msgs)[i]._mess << endl;
        }
    } else cout << "Â áàçå íåò ñîîáùåíèé" << endl;
    cout << string("Íåò ëè÷íûõ ñîîáùåíèé äëÿ ïîëüçîâàòåëÿ ").append(name).append("\n");
}

// âûâåñòè ñîîáùåíèÿ äëÿ âñåõ
void StoreMessage::showMessageAll() {
    if (!_msgs->empty()) {
        for (size_t i = 0; i < _msgs->size(); ++i) {
            if ((*_msgs)[i]._to == "all") cout << (*_msgs)[i]._mess << endl;
        }
    }
    else cout << "Â áàçå íåò ñîîáùåíèé" << endl;
}

// çàïèñü ñîîáùåíèé íà õðàíåíèå
void StoreMessage::setMessage(string message, string from, string to) {
    _msgs->push_back(msg{ from, to, message });
}
