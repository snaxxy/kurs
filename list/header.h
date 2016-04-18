#ifndef listH
#define listH 1

#include <iostream>

//Структура, описывающая элемент списка
struct item
{
	static int summ; //Счётчик элементов
		
	item *previous; //Указатель на предыдущий элемент
	double info; //Поле данных
	item *next; //Указатель на следующий элемент
};

//Абстрактный базовый класс
class list : public item //Наследует структуру item
{
public:
	item *first_item = NULL; //Указатель на первый элемент
	item *last_item = NULL; //Указатель на последний элемент

	//Методы
	virtual void add(double data = NULL); 
	virtual void del() = 0; //Виртуальная функция

	void display();
	void change(int key = NULL);
	void search(double key = NULL);
	void sort(double key = NULL);
};

//Класс, описывающий тип списка stack
class stack : virtual public list //Виртуально наследует абстрактный класс list
{
public:
	stack(double data = NULL); //Конструктор

	void del(); //Метод

	~stack(){} //Деструктор
};

//Класс, описывающий тип списка turn
class turn : virtual public list //Виртуально наследует абстрактный класс list
{
public:
	turn(double data = NULL); //Конструктор
	
	void del(); //Метод

	~turn(){} //Деструктор
};

//Класс, описывающий тип списка deck
class deck : public stack, public turn //Наследует классы stack и turn
{
public:
	deck(double data = NULL); //Конструктор

	//Методы
	void add(double data = NULL);
	void del();

	~deck(){} //Деструктор
};

#endif