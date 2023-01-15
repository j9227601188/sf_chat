/* класс чат
	хранит список юзеров
	рассылает сообщени€ 
*/
#include "Chat.h"
#include "User.h"

// заносим юзера в список рассылки
void Chat::Attach(IUser* user) {
	user_list.push_back(user);
}

// убираем юзера из списка рассылки
void Chat::Detach(IUser* user)
{
	user_list.remove(user);
}

// Ё“ќ“ ћ≈“ќƒ ÷≈Ќ“–јЋ№Ќџ… ¬ „ј“≈ !!!. вызываем метод Update у всех в списке рассылки
void Chat::Notify()
{
	/* “”“ Ѕ”ƒ≈“ ¬—я Ћќ√» ј „ј“ј */
//  ј »≈ —ќќЅў≈Ќ»я  ќћ” ѕќ—џЋј“№.
	list<IUser* >::iterator iterator = user_list.begin();	// перечислитель устанавливаем на первый объект в списке
	while (iterator != user_list.end())						// цикл по всем объектам в списке
	{
		(*iterator)->Update("Message to all users");		// достаЄм объект user и вызываем в нЄм метод Update, передаЄм туда класс Message
		++iterator;
	}
}