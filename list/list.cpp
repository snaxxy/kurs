#include <iostream>

#include "header.h"

using namespace std;

//������� ������ �� ����� ������
void list::display()
{
	if (next != NULL) //�������� �� ������������� ������
	{
		item *temp = next; //���������� � ������������� ������ �������� ���������� ���������
		
		while (temp->next != NULL) //�������� �� ������������� ���������� ��������
		{
			cout << temp->info << ", "; //����� �� ����� ����������, ������� �������� � ��������
			temp = temp->next; //���������� ��������� ����� ���������� ��������
		} 
		cout << temp->info << '.'; //����� �� ����� ����������, ������� �������� � ��������� ��������
	}
	else cout << "������ ����.";
}

//������� ���������� �������� � ������ ������
void list::add(double data)
{
	item *temp = new item; //��������� ������ ������ ��������
	summ++; //���������� �������� �� ����

	if (summ > 1) //�������� �� ��, ��� ���������� ��������� ������ ������
	{
		first_item->previous = temp; //�������� ������� �������� ����� ������, ��� �����������
		temp->next = first_item; //�������� ������ �������� ����� �������, ��� ����������
	}
	else
	{
		temp->next = NULL; //���������� ��������� ������ �������� �� ��������� NULL
		last_item = temp; //���������� ��������� �� ��������� ������� ����� ������
	}

	this->next = temp; //���������� ��������� ������� �� ��������� ������� ����� ������
	first_item = temp; //���������� ��������� �� ������ ������� ����� ������

	temp->previous = this; //�������� ������� �������� ����� �������, ��� �����������
	temp->info = data; //���������� ���� ���������� ������ �������� ���������� ������
}

//������� ������ ������
void list::change(int key)
{
	item *temp = first_item; //���������� � ������������� ������� ������� �������� ���������� ���������

	for (int i = 1; temp != NULL; i++) //������ ����� ������ �� ����� ������� �������� �� ������
	{
		if (i == key)
		{
			double data;
			cout << "\n������� ����� �������� ��������: ";
			cin >> data;

			temp->info = data; //���������� ����� ������
		}
		temp = temp->next; //���������� ���������� ��������� ������ �� ��������� �������
	}
}

//������� ������ ��������
void list::search(double key)
{
	if (key && first_item) //�������� �� ������������� "�����" � ������
	{
		item *temp = first_item; //���������� � ������������� ������� ������� �������� ���������� ���������
		int i = 0, j;

		cout << "������� (������ ��������� � ������): ";
		for (j = 1; temp != NULL; j++) //������ ����� ������ �� ����� ������� �������� �� "�����"
		{			
			if (temp->info == key)
			{
				if (i > 0) cout << ", ";

				i++; //������� ���������
				cout << j; //����� ������ �������� �� �����
			}
			temp = temp->next; //���������� ���������� ��������� ������ �� ��������� �������
		}

		if (i == 0) //���� ������� ����� ����
		{
			cout << "������ �� �������.\n";
			return;
		}

		//����� �� ����� ������� ��������� � ����������� �� �����
		cout << ".\n����� " << i << " �����������";
		if (i % 10 == 1 && i != 11)
		{
			cout << "�.\n";
		}
		else if ((i % 10 == 2 || i % 10 == 3 || i % 10 == 4) && (i != 12 || i != 13 || i != 14))
		{
			cout << "�.\n";
		}
		else
		{
			cout << "�.\n";
		}
	}
	else cout << "����������� ���� �������� �����, ���� ������.\n";
}

//������� ���������� ������ (������)
void list::sort(double key)
{
	int summ_temp = summ, swap; //���������� ����������� ����������
	item *A = NULL, *B = NULL; //���������� � ������������� NULL-�� ���� ��������� ����������
	
	if (summ <= 1) //�������� �� ��, ��� ������ ������� �� ������� ���� ���������
	{
		cout << "������ ������������.\n";
		return;
	}

	//����������
	do
	{	
		//�������� �� ��� ���������� � ������� ��������� �������
		if (key == 1) //�� �����������
		{
			A = this;
			B = this->next;
		}
		else if (key == 2) //�� ��������
		{
			A = NULL;
			B = last_item;
		}

		summ_temp--;
		swap = 0;
		for (int i = 0; i < summ_temp; i++)
		{
			//�������� �� ��� ���������� � ������� ��������� ������� �������
			if (key == 1) //�� �����������
			{
				A = B;
				B = B->next;
			}
			else if (key == 2) //�� ��������
			{
				A = B;
				B = B->previous;
			}
			
			if (A->info > B->info) //������ ������, ���� ����������
			{
				std::swap(A->info, B->info);
				swap++;
			}
		}
	} while (swap != 0);

	cout << "������ ������������.\n";
}