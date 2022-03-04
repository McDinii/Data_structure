#include <iostream>
#include <forward_list>     
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
void task1();
void task2();
int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	do
	{
		cout << endl;
		cout << "�������� ������� ������" << endl;
		cout << "1 - 15�� ������� 1 ������� " << endl;
		cout << "2 - ��� 1 ����" << endl;
		cout << "3 - 3 �������" << endl;
		cout << "4 - 4 �������" << endl;
		cout << "5 - 5 ������" << endl;
		cout << "0 - end" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: task1(); break;
		case 2: task2();

			break;
		case 3: /*var2();*/
			break;
		case 4:/* var5();*/
			break;
		case 5:  /*var8();*/ break;
		}
	} while (choice != 0);

   
}
void task1() {
	/* �������� ���������, � ������� �����
	������� ��� �������� ������������ ������ �
	�������� n �����, � ������� �� �����.*/


	setlocale(LC_ALL, "rus"); int choice1;
	forward_list<int> newlist = { 6, 2, 8, 4, 5 };
	cout << "1-�� ���� �������: " << newlist.front() << endl;
	// newlist.back() �� ��������, ��� ��� � ����������� ������ ��������
	//����� �������� ������ ������ � 1-��� ��������
	do {
		cout << "1-������� ��� �� ������ " << endl;
		cout << "2-�������� n ����� � ������� �� �����" << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 1:
			for (int n : newlist)
			{
				cout << n << "\t";
			}
			cout << endl;
			newlist.clear();
			break;
		case 2: int n, el;
			cout << "������� ��������� ������� � ������?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "������� �������� �������� �" << i + 1 << endl;
				cin >> el;
				newlist.push_front(el);
			}
			cout << "�������� ������" << endl;
			for (int k : newlist) {
				cout << k << "\t";
			}
			break;
		}
	} while (choice1 != 0);
}

	
# define str_len 25
int size = 3;
void enter_new();
void del();
void find(char Name[]);
void out();
void dop2();
typedef struct Exam
{
	char examName[str_len];
	char day[str_len];
	char month[str_len];
	char lastName[str_len];

} ex;
struct Exam list_of_student[3];
struct Exam bad;
FILE* f; FILE* f1; FILE* f2; errno_t err;
int current_size = 0; int choice;
void task2()
{
	//��������.�.�.�., ���� �����������, �������������, ������, ���������, 
	//������� ����.����� �� ���� �����������, �������, �������� 
	//�����, ������.��������� ����������� � ������� ������������
	char name[str_len];
	setlocale(LC_ALL, "Russian");
	cout << "�������:" << endl;
	cout << "1-��� �������� ������" << endl;
	cout << "2-��� ����� ����� ������" << endl;
	cout << "3-��� ������ �� ���������" << endl;
	cout << "4-��� ������ ������(��)" << endl;
	cout << "5-��� ������" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:
			cout << "������� ������� ��������" << endl;
			cin >> name;
			find(name);  break;
		case 4:  out();	break;
		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "���� ����������" << endl;
	ex buf = { ' ', ' ', ' ', ' ',' ' };
	if (!fopen_s(&f, "main.bin", "ab")) {
		if (current_size < 3)
		{
			cout << "������ ����� ";
			cout << current_size + 1;
			cout << endl << "�����   " << endl;
			cin >> buf.lastName;
			cout << "������������� " << endl;
			cin >> buf.day;
			cout << "��������  " << endl;
			cin >> buf.month;
			cout << "������  " << endl;
			cin >> buf.examName;
			fwrite(&buf, sizeof(buf), 1, f);
			current_size++;
		}

		else {
			cout << "������� ������������ ���-�� �����" << endl;
			cout << "��� ������?" << endl;
			cin >> choice;
		}
		fclose(f);
	}
	else {
		cout << "������ �������� �����";
		return;
	}

}
void del()
{
	ex buf;
	bool non = false;
	int chv2;
	char name[str_len];
	cout << "������� 1 - ��� �������� ���������� ������������ ������� \n 2 - ��� �������� ���� ����������\n";
	cin >> chv2;
	switch (chv2) {
	case 1: {
		cout << "\n ������� �������\n";
		cin >> name;
		errno_t err;
		err = fopen_s(&f, "main.bin", "rb");
		if (err != 0)
		{
			perror("������ �������� �����");
			return;
		}
		errno_t err1;
		err1 = fopen_s(&f1, "temp.bin", "ab");
		if (err1 != 0)
		{
			perror("������ �������� �����");
			return;
		}
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f)) {
			if (strcmp(name, buf.month) != 0) {
				fwrite(&buf, sizeof(buf), 1, f1);
				fread(&buf, sizeof(buf), 1, f);
			}
			else {
				fread(&buf, sizeof(buf), 1, f);
				non = true;
			}
		}
		if (non == false) {
			cout << "���������� �� �������" << endl;
		}
		else {
			current_size--;
		}
		fclose(f);
		fclose(f1);
		remove("main.bin");
		rename("temp.bin", "main.bin");
		break;

	}
	case 2: {
		errno_t err3, err4;
		err3 = fopen_s(&f, "main.bin", "rb");
		if (err3 != 0)
		{
			perror("������ �������� �����");
			return;
		}
		err4 = fopen_s(&f2, "temp2.bin", "ab");
		if (err4 != 0)
		{
			perror("������ �������� �����");
			return;
		}
		fclose(f);
		fclose(f2);
		remove("main.bin");
		rename("temp2.bin", "main.bin");
		fclose(f);
		fclose(f2);
		current_size = 0;
		break;
	}
	}

	cout << endl << "��� ������?" << endl;
	cin >> choice;

}
void find(char Name[])
{
	bool non = false;
	ex buf;
	if (!fopen_s(&f, "main.bin", "rb"))
	{
		cout << "\n�����       |   �������������|  �������� |  ������\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			if (strcmp(Name, buf.month) == 0) {
				non = true;
				cout << buf.lastName << "\t\t" << buf.day << "\t\t" << buf.month << "\t    " << buf.examName << endl;
				break;
			}
			else { fread(&buf, sizeof(buf), 1, f); }
		}
		if (non == false) {
			cout << "���������� �� �������" << endl;
		}

		fclose(f);
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}
	cout << endl << "��� ������?" << endl;
	cin >> choice;

}
void out()
{
	cout << endl;
	ex buf;
	if (!fopen_s(&f, "main.bin", "rb")) {
		cout << "\n�����       |   �������������|  �������� |  ������\n";
		fread(&buf, sizeof(buf), 1, f);
		current_size = 0;
		while (!feof(f))
		{
			cout << buf.lastName << "\t\t" << buf.day << "\t\t" << buf.month << "\t    " << buf.examName << endl;
			fread(&buf, sizeof(buf), 1, f);
			current_size++;
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}

	cout << endl << "��� ������?" << endl;
	cin >> choice;


}
