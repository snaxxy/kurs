#include <iostream>

#include "header.h"

//�����������
turn::turn(double data)
{
	previous = NULL;
	info = data;
	next = NULL;
}

//������� �������� �������� �� ������
void turn::del()
{
	if (last_item) //�������� �� ������������� ���������� ��������
	{
		item *temp = last_item->previous; //���������� � ������������� ������� �������������� �������� ���������� ���������

		if (last_item->previous == this) //�������� �� ��, ��� ������������� ������� �� �������� ��������
		{
			this->next = NULL; //���������� ��������� ������� �� ��������� ������� NULL
		}
		else
		{
			last_item = temp; //���������� ��������� �� ��������� ������� ����� ����������
			last_item->next = NULL; //���������� ��������� ���������� �������� �� ��������� NULL
		}
		//delete last_item;

		summ--; //���������� �������� ��������� �� ����
	}
	else std::cout << "������ ����.\n";
}