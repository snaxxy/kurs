#ifndef listH
#define listH 1

#include <iostream>

//���������, ����������� ������� ������
struct item
{
	static int summ; //������� ���������
		
public:
	item *previous; //��������� �� ���������� �������
	double info; //���� ������
	item *next; //��������� �� ��������� �������
};

item* operator+(item, item);

//������� ��������� ������
class stack;
class turn;
class deck;

//����������� ������� �����
class list : public item//��������� ��������� item
{
	//"���������" ����������
	item *first_item = NULL; //��������� �� ������ �������
	item *last_item = NULL; //��������� �� ��������� �������

public:
	//������
	virtual void add(double data = NULL); 
	virtual void del() = 0; //����������� �������

	void display();
	void change(int key = NULL);
	void search(double key = NULL);
	void sort(double key = NULL);

	void oper(int, int);

	//��������� ������ ������ list, ����� ��� ������ "���������" ����������
	friend stack;
	friend turn;
	friend deck;
};

//�����, ����������� ��� ������ stack
class stack : virtual public list //���������� ��������� ����������� ����� list
{
public:
	stack(double data = NULL); //�����������

	void del(); //�����

	~stack(){} //����������
};

//�����, ����������� ��� ������ turn
class turn : virtual public list //���������� ��������� ����������� ����� list
{
public:
	turn(double data = NULL); //�����������
	
	void del(); //�����

	~turn(){} //����������
};

//�����, ����������� ��� ������ deck
class deck : public stack, public turn //��������� ������ stack � turn
{
public:
	deck(double data = NULL); //�����������

	//������
	void add(double data = NULL);
	void del();

	~deck(){} //����������
};

#endif