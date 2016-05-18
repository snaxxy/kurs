﻿#include <iostream>

#include "header.h"

//Конструктор
deck::deck(double data)
{
	previous = NULL;
	info = data;
	next = NULL;
}

//Функция добавления элемента в конец списка
void deck::add(double data)
{
	item *temp = new item; //Выделение памяти новому элементу
	summ++; //Увеличение счётчика на один

	if (summ > 1) //Проверка на то, что количество элементов больше одного
	{
		last_item->next = temp; //Указание последнему элементу адрес нового, как следующего
		temp->previous = last_item; //Указание новому элементу адрес последнего, как предыдущего
	}
	else
	{
		first_item = temp; //Присвоение указателю на первый элемент адрес нового
	
		this->next = temp; //Указание объекту адрес нового, как следующего
		temp->previous = this; //Указание новому элементу адрес объекта, как предыдущего
	}

	last_item = temp; //Присвоение указателю на последний элемент адрес нового
	temp->info = data; //Присвоение полю информации нового элемента полученных данных
	temp->next = NULL; //Присвоение указателю нового элемента на следующий NULL
}

//Функция удаления элемента из списка
void deck::del()
{
	char control; //Переменная, хранящая команду, где удалять элемент
	std::cout << "\nУдалить первый (f) или последний (l) элемент?\nКоманда: ";
	std::cin >> control;

	if (last_item && control == 'l') //Проверка на существование последнего элемента и того, что удалять нужно в конце
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
	}
	else if (last_item && control == 'f') //Проверка на существование последнего элемента и того, что удалять нужно в начале
	{
		if (first_item->next) this->next = first_item->next; //Проверка на существование второго элемента и присвоение указателю объекта на следующий элемент адрес первого
		else this->next = NULL; //Присвоение указателю объекта на следующий элемент NULL

		//delete first_item;
		first_item = this->next; //Присвоение указателю на первый элемент адрес нового первого
	}
	else //Иначе вывод на экран, что список пуст
	{
		std::cout << "Список пуст.\n";
		return;
	}
	summ--; //Уменьшение счётчика элементов на один
}