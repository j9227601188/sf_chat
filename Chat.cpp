/* класс чат
	хранит список юзеров
	рассылает сообщения 
*/
#include <iostream>
#include "Chat.h"
#include "User.h"
#include "StoreUsers.h"
#include "StoreMessage.h"

Chat::Chat(StoreUsers* su, StoreMessage* sm) :_su(su), _sm(sm) {}

Chat::~Chat()
{
	cout << "\nЧат удалён\n ";
	list<IUser* >::iterator iterator = user_list.begin();	// перечислитель устанавливаем на первый объект в списке
	if (user_list.empty()) return;							// если список пустой
	while (iterator != user_list.end())						// цикл по всем объектам в списке
	{
		delete (*iterator);									// удаляем всех юзеров (вызываем деструктор ~User)
		++iterator;
	}

}

// заносим юзера в список рассылки
void Chat::Attach(IUser* user) {
	user_list.push_back(user);
}

// убираем юзера из списка рассылки
void Chat::Detach(IUser* user)
{
	user_list.remove(user);
}

// ЭТОТ МЕТОД ЦЕНТРАЛЬНЫЙ В ЧАТЕ !!!. вызываем метод Update у всех объектов в списке
void Chat::Notify()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nВы вошли в чат\n";
	//_sm->showMessage();		// вывести юзеру все сообщения чата и личные
	//cin.getline()
	/* ТУТ БУДЕТ ВСЯ ЛОГИКА ЧАТА!!! сюда попадает юзер после входа в чат!!!*/
// КАКИЕ СООБЩЕНИЯ КОМУ ПОСЫЛАТЬ. Надо вывести сообщения из хранения и плюс личные сообщения. (как вариант: по Update объект User забирает сообщения из хранилки)
	list<IUser* >::iterator iterator = user_list.begin();	// перечислитель устанавливаем на первый объект в списке
	while (iterator != user_list.end())						// цикл по всем объектам в списке
	{
		(*iterator)->Update("Message to all users");		// достаём объект user и вызываем в нём метод Update, передаём туда класс Message
		++iterator;
	}
}

