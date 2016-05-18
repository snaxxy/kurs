#include <iostream>

#include "header.h"

using namespace std;

int item::summ = 0; //Счетчик числа элементов
void main()
{
	setlocale(LC_ALL, "russian"); //Локаль
	cout << "Списки\n\n";

	int control; //выбранный тип
	cout << "Выберите тип списка:\n1. Стек;\n2. Очередь;\n3. Дек.\n\nКоманда: ";
	cin >> control;

	stack arr_stack; //Создание объекта класса stack
	queue arr_queue; //Создание объекта класса queue
	deck arr_deck; //Создание объекта класса deck

	list *pointer = NULL; //пустой указатель на объект родителя
	
	//переназначение указателя
	if (control == 1)
	{
		pointer = &arr_stack; 
	}
	else if (control == 2)
	{
		pointer = &arr_queue;
	}
	else if (control == 3)
	{
		pointer = &arr_deck;
	}
	double (item::*ptr) = &item::info; //указатель на компонент структуры
	pointer->*ptr = 666; //значение нулевого элемента

	int(*funcPtr)(const char*); //Создание пустого указателя на функцию
	funcPtr = system; //Присвоение ему адреса указателя на функцию system


	int command = -1; //команда
	while (command != 0)
	{
		funcPtr("cls"); //Очистка экрана

		cout << "Список:\n";
		pointer->display(); //Вывод на экран списка
		cout << endl << endl;

		cout << "Выберите действие:\n0. Выход;\n1. Добавить элемент;\n2. Удалить элемент;\n3. Изменить данные;\n4. Поиск;\n5. Сортировка;\n6. Сложить два элемента и добавить в список.\n\nКоманда: ";
		cin >> command;

		char control_add = 'f'; //Куда вставлять символ. По умолчанию в начало
		
		//switch case для многих вариантов
		switch (command)
		{
		case 0: //выход из программы
			//Деструкторы
			arr_stack.~stack();
			arr_queue.~queue();
			arr_deck.~deck();
			return;

		case 1: //добавить элемент
			double data; //значение добавляемого элемента
			cout << "\nВведите значение элемента: ";
			cin >> data;

			if (control == 3) //Если дек, то спрашиваем, куда добавлять
			{
				cout << "\nВ начало (f) или в конец (l)?\nКоманда: ";
				cin >> control_add;
			}

			if (control_add == 'f') //в начало
			{
				pointer->list::add(data); //Вызов функции базового класса 
			}
			else if (control_add == 'l') //в конец
			{
				pointer->add(data); //Вызов функции в зависимости от типа списка
			}

			break;

		case 2: //удалить элемент
			pointer->del(); //функция удаления соответствующего класса

			break;

		case 3: //изменить данные
			int number; //Номер элемента
			cout << "\nВведите номер элемента: ";
			cin >> number;

			pointer->change(number); //Вызов функции замены соответствующего класса
			break;

		case 4: //поиск по данным
			double query; //Ключ поиска
			cout << "\nВведите ключевое слово: ";
			cin >> query;

			pointer->search(query); //Вызов функции поиска соответствующего класса
			break; 

		case 5: //сортировка
			double control_sort; //тип сортировки
			cout << "\nПо возрастанию (1) или по убыванию (2)?\nКоманда: ";
			cin >> control_sort;

			pointer->sort(control_sort); //Вызов функции сортировки соответствующего класса
			break;

		case 6: //сложить и добавить
			int key_1, key_2; //номера элементов
			cout << "\nВведите номера элементов:\n";
			cin >> key_1;
			cin >> key_2;

			pointer->oper(key_1, key_2); //вызов функции сложения соответствующего класса
			break;
		}

		cout << endl;
		funcPtr("pause"); //пауза через указатель
	}
}