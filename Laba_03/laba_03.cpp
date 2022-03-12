
#include <iostream>      
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
# define str_len 25
# define size 3  
using namespace std;
void enter_new(int *choice);
void del(int *choice);
void find(char Name[], int* choice);
void out(int* choice);
void enter_newD(int* choiceD);
void changeD(int* choiceD);
void delD(int* choiceD);
void outD(int* choiceD);
typedef struct Exam
{
	char examName[str_len];
	char day[str_len];
	char month[str_len];
	char lastName[str_len];

} ex;
struct Exam list_of_student[size];
struct Exam bad;
FILE* f; FILE* f1; FILE* f2; errno_t err;
int current_size = 0; 
int M_choice;
int choiceD;
int choice;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "�������� �������" << endl;
	cout << "1-�������� �������" << endl;
	cout << "2-��������������" << endl;
	cout << "3-���������" << endl;
	cin >> M_choice;
	do {
		switch (M_choice) {
		case 1:
			
			char name[str_len];
			setlocale(LC_ALL, "Russian");
			cout << "�������:" << endl;
			cout << "1-��� �������� ������" << endl;
			cout << "2-��� ����� ����� ������" << endl;
			cout << "3-��� ������ �� ���������" << endl;
			cout << "4-��� ������ ������(��)" << endl;
			cout << "6-��� �������� �����" << endl;
			cout << "5-��� ������" << endl;
			cin >> choice;
			do
			{
				switch (choice)
				{
				case 1:  del(&choice);	break;
				case 2:  enter_new(&choice);  break;
				case 3:
					cout << "������� �������" << endl;
					cin >> name;
					find(name, &choice);  break;
				case 4:  out(&choice);	break;
				case 6: char f[str_len];
					cout << "������� ��� ����� (� �����������) ��� ��� ��������" << endl;
					cin >> f;
					remove(f);
					cout << "���� " << f << " ������.\n��� ������ ? " << endl;
					cin >> choice;
					break;
				case 5: main(); break;
				}

			} while (choice != 0);
			break;
		case 2:
			setlocale(LC_CTYPE, "Russian");
			cout << "�������:" << endl;
			cout << "1���� �������� ������" << endl;
			cout << "2���� ����� ����� ������" << endl;
			cout << "3���� ��������� ������" << endl;
			cout << "4���� ������ ������(��)" << endl;
			cout << "5���� ������ �����" << endl;
			cout << "6���� �������� �����" << endl;
			cin >> choiceD;
			do
			{

				
				
				switch (choiceD)
				{
				case 1:  delD(&choiceD);	break;
				case 2:  enter_newD(&choiceD);  break;
				case 3:  changeD(&choiceD);  break;
				case 4:  outD(&choiceD);	break;
				case 5: main(); 	break;
				case 6: char fD[str_len];
					cout << "������� ��� ����� (� �����������) ��� ��� ��������" << endl;
					cin >> fD;
					remove(fD);
					cout << "���� " << fD << " ������.\n��� ������ ? " << endl;
					cin >> choice;
					break;
				}
			} while (choiceD != 0); 
			break;
		}
	} while (M_choice != 3);
}
void enter_new( int *choice)
{
	cout << "���� ����������" << endl;
	ex buf = { ' ', ' ', ' ', ' ',' ' };
	if (!fopen_s(&f, "main.bin", "ab")) {
		if (current_size < size)
		{
			cout << "������ ����� ";
			cout << current_size + 1;
			cout << endl << "������� " << endl;
			cin >> buf.lastName;
			cout << "���� �������� " << endl;
			cin >> buf.day;
			cout << "����� ��������  " << endl;
			cin >> buf.month;
			cout << "�������� ��������  " << endl;
			cin >> buf.examName;
			fwrite(&buf, sizeof(buf), 1, f);
			current_size++;
		}

		else {
			cout << "������ �������� � ���� main.bin" << endl;
			cout << "��� ������?" << endl;
			cin >> *choice;
		}
		fclose(f);
	}
	else {
		cout << "������ �������� �����";
		return;
	}

}
void del(int* choice)
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
			if (strcmp(name, buf.lastName) != 0) {
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
	cin >> *choice;

}
void find(char Name[],int* choice)
{
	bool non = false;
	ex buf;
	if (!fopen_s(&f, "main.bin", "rb"))
	{
		cout << "\n�������     |   �������     |   ����     |  �����\n";
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			if (strcmp(Name, buf.lastName) == 0) {
				non = true;
				cout << buf.lastName << "\t\t" << buf.examName << "\t\t" << buf.day << "\t    " << buf.month << endl;
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
	cin >> *choice;

}
void out(int* choice)
{
	cout << endl;
	ex buf;
	if (!fopen_s(&f, "main.bin", "rb")) {
		cout << "\n�������     |   �������     |   ����     |  �����\n";
		fread(&buf, sizeof(buf), 1, f);
		current_size = 0;
		while (!feof(f))
		{
			cout << buf.lastName << "\t\t" << buf.examName << "\t\t" << buf.day << "\t    " << buf.month << endl;
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
	cin >> *choice;


}                              

# define sizeD 3



struct Student
{
	char name[str_len];
	int year_of_birth;
	char department[5];
	int group;
	int avg;
};

struct Student list_of_studentD[sizeD];
struct Student badD;

int current_sizeD = 0;
FILE* fD; FILE* f1D; FILE* f2D; errno_t errD;

void enter_newD(int* choiceD)
{
	struct Student bufD = { ' ',' ', ' ',' ',' ' };
	cout << "���� ����������" << endl;
	if (!fopen_s(&fD, "mainD.bin", "ab")) {
		if (current_sizeD < sizeD)
		{
			cout << "������ ����� ";
			cout << current_sizeD + 1;
			cout << endl << " \n ������� ��������: ";
			cin >> bufD.name;
			cout << "\n ��� ������� ������: ";
			cin >> bufD.year_of_birth;
			cout << "\n ����� ������: ";
			cin >> bufD.department;
			cout << "\n ����� ������: ";
			cin >> bufD.group;
			cout << "\n ������: ";
			cin >> bufD.avg;
			fwrite(&bufD, sizeof(bufD), 1, fD);
			current_sizeD++;
			cout << endl;
		}
		else {
			cout << "������ �������� � ���� mainD.bin" << endl;
			cout << "��� ������?" << endl;
			cin >> *choiceD;
		}
		fclose(fD);
	}
	else {
		cout << "ERROR" << endl;
		return;
	}
	exit;
}

void delD(int* choiceD)
{
	struct Student bufD;
	bool non = false;
	int d;
	char nameD[str_len];
	
	cout << "������� �������\n";
	cin >> nameD;
	errno_t errD;
	errD = fopen_s(&fD, "mainD.bin", "rb");
	if (errD != 0)
	{
		perror("������ �������� �����");
		return;
	}
	errno_t err1D;
	err1D = fopen_s(&f1D, "tempD.bin", "ab");
	if (err1D != 0)
	{
		perror("������ �������� �����");
		return;
	}
	fread(&bufD, sizeof(bufD), 1, fD);
	while (!feof(fD)) {
		if (strcmp(nameD, bufD.name) != 0) {
			fwrite(&bufD, sizeof(bufD), 1, f1D);
			fread(&bufD, sizeof(bufD), 1, fD);
		}
		else {
			fread(&bufD, sizeof(bufD), 1, fD);
			non = true;
		}
	}
	if (non == false) {
		cout << "���������� �� �������" << endl;
	}
	else {
		current_sizeD--;
	}
	fclose(fD);
	fclose(f1D);
	remove("mainD.bin");
	rename("tempD.bin", "mainD.bin");
	cout << endl << "��� ������?" << endl;
	cin >> *choiceD;
}

void changeD(int* choiceD)
{
	int n, per;
	cout << "\n������� ����� ������" << endl; 	cin >> n;
	do
	{
		cout << "�������: " << endl;
		cout << "1���� ��������� ������� ��������" << endl;
		cout << "2���� ��������� ���� �������" << endl;
		cout << "3���� ��������� �����" << endl;
		cout << "4���� ��������� ������ ������" << endl;
		cout << "5���� ��������� �������" << endl;
		cout << "6������\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "����� ������� ��������";
			cin >> list_of_studentD[n - 1].name;   break;
		case 2: cout << "����� ��� �������";
			cin >> list_of_studentD[n - 1].year_of_birth; break;
		case 3: cout << "����� ����� ";
			cin >> list_of_studentD[n - 1].department; break;
		case 4: cout << "����� ����� ������ ";
			cin >> list_of_studentD[n - 1].group; break;
		case 5: cout << "����� ������ ";
			cin >> list_of_studentD[n - 1].avg; break;
		}
	} while (per != 6);
	exit;
}

void outD(int* choiceD)
{
	struct Student bufD;
	if (!fopen_s(&fD, "mainD.bin", "rb")) {
		cout << "\n������� ��������   |   ��� �������     |  �����     |  ����� ������ | ������\n";
		fread(&bufD, sizeof(bufD), 1, fD);
		while (!feof(fD))
		{
			cout << bufD.name << "\t\t" << bufD.year_of_birth << "\t\t" << bufD.department << "\t    " << bufD.group << "\t    " << bufD.avg << endl;
			fread(&bufD, sizeof(bufD), 1, fD);
			current_sizeD++;
		}
		cout << endl;
			fclose(fD);
		
		
		
	}
	else
	{
		cout << "������ �������� �����";
		return;
	}

	cout << endl << "��� ������?" << endl;
	cin >> *choiceD;
}











