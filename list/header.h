#ifndef listH
#define listH 1

#include <iostream>

//���������, ����������� ������� ������
struct item
{
	static int summ; //������� ���������
		
	item *previous; //��������� �� ���������� �������
	double info; //���� ������
	item *next; //��������� �� ��������� �������
};

//����������� ������� �����
class list : public item //��������� ��������� item
{
public:
	item *first_item = NULL; //��������� �� ������ �������
	item *last_item = NULL; //��������� �� ��������� �������

	//������
	virtual void add(double data = NULL); 
	virtual void del() = 0; //����������� �������

	void display();
	void change(int key = NULL);
	void search(double key = NULL);
	void sort(double key = NULL);
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