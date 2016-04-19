#include <iostream>
#include "locale.h"
#include "header.h"

using namespace std;
int item::summ = 0; //Установление счётчика в ноль

void main()
{
	setlocale(LC_ALL, "RUS"); //Добавление кириллицы в кодировку
	cout << "Проект 'Списки'.\n\n";
		//ВНИМАНИЕ! Программа не защищена от 'дурака'.\n\n";

	int control; //Переменная, хранящая номер типа списка
	cout << "Выберите тип списка:\n1. Стек;\n2. Очередь;\n3. Дек.\n\nКоманда: ";
	cin >> control;

	stack arr_stack; //Создание объекта класса stack
	queue arr_queue; //Создание объекта класса queue
	deck arr_deck; //Создание объекта класса deck

	list *pointer = NULL; //Создание и инициализация NULL-ом указателя базового класса
	
	//Присвоение указателю адрес необходимого объекта
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

	//Начало основной интерфейсной функции
	int command = -1; //Переменная, хранящая номер команды
	while (command != 0)
	{
		system("cls"); //Очистка экрана

		cout << "Список:\n";
		pointer->display(); //Вывод на экран списка
		cout << endl << endl;

		//Получение команды
		cout << "Выберите действие:\n0. Выход;\n1. Добавить элемент;\n2. Удалить элемент;\n3. Изменить данные;\n4. Поиск;\n5. Сортировка.\n\nКоманда: ";
		cin >> command;

		char control_add = 'f'; //Переменная, указывающая, куда вставлять символ. По умолчанию, в начало
		
		//Переключатель
		switch (command)
		{
		case 0: //Выход
			//Деструкторы
			arr_stack.~stack();
			arr_queue.~queue();
			arr_deck.~deck();
			return;

		case 1: //Добавление
			double data; //Переменная, хранящая данные, которые нужно добавить в новый элемент
			cout << "\nВведите значение элемента: ";
			cin >> data;

			if (control == 3) //Если список типа deck, то спрашиваем, куда добавлять
			{
				cout << "\nВ начало (f) или в конец (l)?\nКоманда: ";
				cin >> control_add;
			}
			if (control_add == 'f') //Добавление в начало
			{
				pointer->list::add(data); //Вызов функции всегда из класса list
			}
			else if (control_add == 'l') //Добавление в конец
			{
				pointer->add(data); //Вызов функции в зависимости от типа списка
			}
			break;

		case 2: //Удаление элемента
			pointer->del(); //Вызов функции удаления

			break;

		case 3: //Изменение данных, хранящихся в элементе списка
			int number; //Переменная, хранящая номер элемента
			cout << "\nВведите номер элемента: ";
			cin >> number;

			pointer->change(number); //Вызов функции замены
			break;

		case 4: //Поиск элемента по данным
			double key; //Переменная, хранящая ключевые данные поиска
			cout << "\nВведите ключевое слово: ";
			cin >> key;

			pointer->search(key); //Вызов функции поиска
			break; 

		case 5: //Сортировка
			double control_sort; //Переменная, хранящая команду, как сортировать список
			cout << "\nПо возрастанию (1) или по убыванию (2)?\nКоманда: ";
			cin >> control_sort;

			pointer->sort(control_sort); //Вызов функции сортировки
			break;
		}

		cout << endl;
		int(*p)(const char*);
		p = system;
		p("pause"); //Пауза работы программы, до нажатия любой клавиши
	}
}