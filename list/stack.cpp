#include <iostream>

#include "header.h"

using namespace std;

//�����������
stack::stack(double data)
{
	previous = NULL;
	info = data;
	next = NULL;
}

//������� �������� �������� �� ������
void stack::del()
{
	if (first_item) //�������� �� ������������� ������
	{
		if (first_item->next) this->next = first_item->next; //�������� �� ������������� ������� �������� � ���������� ��������� ������� �� ��������� ������� ����� �������
		else this->next = NULL; //���������� ��������� ������� �� ��������� ������� NULL

		//delete first_item;
		first_item = this->next; //���������� ��������� �� ������ ������� ����� ������ �������

		summ--; //���������� �������� ��������� �� ����
	}
	else cout << "������ ����.\n";
}

/*
stack::~stack()
{
	return;
	
	delete[] first_item;
	delete[] last_item;

	return;

	item *temp = last_item->previous;

	for (int i = 1; i <= summ; i++)
	{
		temp->next->next = NULL;
		temp->next->previous = NULL;

		temp = temp->previous;
	}
}
*/