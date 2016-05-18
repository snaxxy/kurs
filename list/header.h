#ifndef listH
#define listH 1

#include <iostream>

//элемент списка (структура)
struct item
{
	static int summ; //счетчик элементов
		
public:
	item *previous; //Указатель на предыдущий элемент
	double info; //Поле данных
	item *next; //Указатель на следующий элемент
};

item* operator+(item, item);

//прототип классов
class stack;
class queue;
class deck;

//Абстрактный базовый класс
class list : public item//Наследует структуру item
{
	//"Приватные" компоненты
	item *first_item = NULL; //Указатель на первый элемент
	item *last_item = NULL; //Указатель на последний элемент

public:
	//прототипы методов
	virtual void add(double data = NULL); 
	virtual void del() = 0; //виртуальная функция

	void display();
	void change(int key = NULL);
	void search(double key = NULL);
	void sort(double key = NULL);

	void oper(int, int);

	//друзья класса list, чтобы они видели "приватные" компоненты
	friend stack;
	friend queue;
	friend deck;
};

//прототип stack
class stack : virtual public list //Виртуально наследует абстрактный класс list
{
public:
	stack(double data = NULL); //Конструктор

	void del(); //Метод

	~stack(){} //Деструктор
};

//Класс, описывающий тип списка queue
class queue : virtual public list //Виртуально наследует абстрактный класс list
{
public:
	queue(double data = NULL); //Конструктор
	
	void del(); //Метод

	~queue(){} //Деструктор
};

//Класс, описывающий тип списка deck
class deck : public stack, public queue //Наследует классы stack и queue
{
public:
	deck(double data = NULL); //Конструктор

	//Методы
	void add(double data = NULL);
	void del();

	~deck(){} //Деструктор
};

#endif