#include <iostream>

#include "header.h"

//Конструктор
turn::turn(double data)
{
	previous = NULL;
	info = data;
	next = NULL;
}

//Функция удаления элемента из списка
void turn::del()
{
	if (last_item) //Проверка на существование последнего элемента
	{
		item *temp = last_item->previous; //Объявление и инициализация адресом предпоследнего элемента временного указателя

		if (last_item->previous == this) //Проверка на то, что предпоследний элемент не является объектом
		{
			this->next = NULL; //Присвоение указателю объекта на следующий элемент NULL
		}
		else
		{
			last_item = temp; //Присвоение указателю на последний элемент адрес временного
			last_item->next = NULL; //Присвоение указателю последнего элемента на следующий NULL
		}
		//delete last_item;

		summ--; //Уменьшение счётчика элементов на один
	}
	else std::cout << "Список пуст.\n";
}