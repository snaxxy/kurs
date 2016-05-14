#include <iostream>

#include "header.h"

using namespace std;

//Конструктор
stack::stack(double data)
{
	previous = NULL;
	info = data;
	next = NULL;
}

//Функция удаления элемента из списка
void stack::del()
{
	if (first_item) //Проверка на существование списка
	{
		if (first_item->next) this->next = first_item->next; //Проверка на существование второго элемента и присвоение указателю объекта на следующий элемент адрес первого
		else this->next = NULL; //Присвоение указателю объекта на следующий элемент NULL

		//delete first_item;
		first_item = this->next; //Присвоение указателю на первый элемент адрес нового первого

		summ--; //Уменьшение счётчика элементов на один
	}
	else cout << "Список пуст.\n";
}

