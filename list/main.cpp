#include <iostream>

#include "header.h"

using namespace std;

int item::summ = 0; //������������ �������� � ����

void main()
{
	setlocale(LC_ALL, "russian"); //���������� ��������� � ���������

	cout << "������ '�������'.\n\n";
		//��������! ��������� �� �������� �� '������'.\n\n";

	int control; //����������, �������� ����� ���� ������
	cout << "�������� ��� ������:\n1. ����;\n2. �������;\n3. ���.\n\n�������: ";
	cin >> control;

	stack arr_stack; //�������� ������� ������ stack
	turn arr_turn; //�������� ������� ������ turn
	deck arr_deck; //�������� ������� ������ deck

	list *pointer = NULL; //�������� � ������������� NULL-�� ��������� �������� ������
	
	//���������� ��������� ����� ������������ �������
	if (control == 1)
	{
		pointer = &arr_stack; 
	}
	else if (control == 2)
	{
		pointer = &arr_turn;
	}
	else if (control == 3)
	{
		pointer = &arr_deck;
	}
	double (item::*ptr) = &item::info; //�������� � ������������� ��������� �� ��������� info ��������� item
	pointer->*ptr = 666; //���������� �������� �������� �������� ������ 

	int(*ptr_fun)(const char*); //�������� ��������� �� �������...
	ptr_fun = system; //...� ��� ������������� �������� system

	//������ �������� ������������ �������
	int command = -1; //����������, �������� ����� �������
	while (command != 0)
	{
		ptr_fun("cls"); //������� ������

		cout << "������:\n";
		pointer->display(); //����� �� ����� ������
		cout << endl << endl;

		//��������� �������
		cout << "�������� ��������:\n0. �����;\n1. �������� �������;\n2. ������� �������;\n3. �������� ������;\n4. �����;\n5. ����������;\n6. ������� ��� �������� � �������� � ������.\n\n�������: ";
		cin >> command;

		char control_add = 'f'; //����������, �����������, ���� ��������� ������. ��-���������, � ������
		
		//�������������
		switch (command)
		{
		case 0: //�����
			//�����������
			arr_stack.~stack();
			arr_turn.~turn();
			arr_deck.~deck();
			return;

		case 1: //����������
			double data; //����������, �������� ������, ������� ����� �������� � ����� �������
			cout << "\n������� �������� ��������: ";
			cin >> data;

			if (control == 3) //���� ������ ���� deck, �� ����������, ���� ���������
			{
				cout << "\n� ������ (f) ��� � ����� (l)?\n�������: ";
				cin >> control_add;
			}

			if (control_add == 'f') //���������� � ������
			{
				pointer->list::add(data); //����� ������� ������ �� ������ list
			}
			else if (control_add == 'l') //���������� � �����
			{
				pointer->add(data); //����� ������� � ����������� �� ���� ������
			}

			break;

		case 2: //�������� ��������
			pointer->del(); //����� ������� ��������

			break;

		case 3: //��������� ������, ���������� � �������� ������
			int number; //����������, �������� ����� ��������
			cout << "\n������� ����� ��������: ";
			cin >> number;

			pointer->change(number); //����� ������� ������
			break;

		case 4: //����� �������� �� ������
			double key; //����������, �������� �������� ������ ������
			cout << "\n������� �������� �����: ";
			cin >> key;

			pointer->search(key); //����� ������� ������
			break; 

		case 5: //����������
			double control_sort; //����������, �������� �������, ��� ����������� ������
			cout << "\n�� ����������� (1) ��� �� �������� (2)?\n�������: ";
			cin >> control_sort;

			pointer->sort(control_sort); //����� ������� ����������
			break;

		case 6:
			int key_1, key_2;
			cout << "\n������� ������ ��������:\n";
			cin >> key_1;
			cin >> key_2;

			pointer->oper(key_1, key_2);
			break;
		}

		cout << endl;
		ptr_fun("pause"); //����� ������ ���������, �� ������� ����� �������
	}
}