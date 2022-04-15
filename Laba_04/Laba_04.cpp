//#define _CRT_NONSTDC_NO_WARNINGS
//#include<stdio.h>
//#include<string>
//#include<iostream>
//#include <windows.h>
//
//using namespace std;
////���������� ���������
//typedef struct student {
//	int rno;
//	char name[20]; //���������� ����� ���������
//	char surname[20];
//	char second_name[20];
//	struct subject { //��������� ������ ��������
//		int scode;
//		char name[20];
//		int mark;
//	}sub[3]; //���������� ������� � ���������
//	int total;
//	float per;
//}student;
//
//void sort_on_screen() {
//	student* s, s1;
//	FILE* fp;
//	fp = fopen("mystudents1.txt", "r");
//	fseek(fp, 0, SEEK_END);
//	int n = ftell(fp) / sizeof(student);
//	int i, j;
//	rewind(fp);
//	s = (student*)calloc(n, sizeof(student));
//	for (i = 0; i < n; i++)
//		fread(&s[i], sizeof(student), 1, fp);
//
//	for (i = 0; i < n; i++) {
//		for (j = i + 1; j < n; j++) {
//			if (s[i].total < s[j].total) {
//				s1 = s[i];
//				s[i] = s[j];
//				s[j] = s1;
//			}
//		}
//	}
//
//
//	for (i = 0; i < n; i++) {
//		printf("\n%-5d%-20s%-20s%-20s", s[i].rno, s[i].name, s[i].surname, s[i].second_name);
//		for (j = 0; j < 3; j++) {
//			printf("%4d", s[i].sub[j].mark);
//		}
//		printf("%5d%7.2f", s[i].total, s[i].per);
//	}
//	fclose(fp);
//}
//
//void sort_in_file() {
//
//	student* s, s1;
//	FILE* fp;
//	fp = fopen("mystudents1.txt", "r");
//	fseek(fp, 0, SEEK_END);
//	int n = ftell(fp) / sizeof(student);
//	int i, j;
//	rewind(fp);
//	s = (student*)calloc(n, sizeof(student));
//	for (i = 0; i < n; i++)
//		fread(&s[i], sizeof(student), 1, fp);
//
//	fclose(fp);
//	for (i = 0; i < n; i++) {
//		for (j = i + 1; j < n; j++) {
//			if (s[i].total < s[j].total) {
//				s1 = s[i];
//				s[i] = s[j];
//				s[j] = s1;
//			}
//		}
//	}
//	for (i = 0; i < n; i++) {
//		printf("\n%-5d%-20s%-20s%-20s", s[i].rno, s[i].name, s[i].surname, s[i].second_name);
//		for (j = 0; j < 3; j++) {
//			printf("%4d", s[i].sub[j].mark);
//		}
//		printf("%5d%7.2f", s[i].total, s[i].per);
//	}
//
//	fp = fopen("mystudents1.txt", "w");
//
//	for (i = 0; i < n; i++) {
//		fwrite(&s[i], sizeof(student), 1, fp);
//	}
//
//	fclose(fp);
//}
//




# include <iostream>                    
# include <stdio.h>     
#include <stdlib.h>

# define str_len 30                               
# define size 30  
# define MAX 5
using namespace std;

int menu_select(void);
void list(void);
void enter(void);
void delete_(void);
int find_free(void);
void init_list(void);
void search(void);
struct Student
{
	char name[str_len];
	char surname[str_len];
	char department[5];
	int group;
	unsigned int id;
}list_of_student[MAX];

int main(void) {
	char choice;
	setlocale(LC_ALL, "Russian");
	init_list();
	for (;;) {
		choice = menu_select();
		switch (choice) {
		case 1: enter();
			break;
		case 2: delete_();
			break;
		case 3:list(); break;
		case 4:search(); break;
		case 5: exit(0);
		}
	}
}

void init_list(void)
{
	register int i;
	for (i = 0; i < MAX; i++) {
		list_of_student[i].name[0] = '\0';
	}
}

int menu_select(void) {
	char s[80];
	int c; 
	do {
	printf("1 ������� ���\n");
	printf("2 ������� ���\n");
	printf("3 �������� ������\n");
	printf("4 �����\n");
	printf("5 �����\n");
			printf("\n������� ����� ������� ������: \n");
			gets_s(s);

			c = atoi(s);

			if (c == 0) {
				gets_s(s);
				c = atoi(s);
			}
			//system("cls");
		} while (c < 0 || c > 4);
	return c; 
}

void enter(void)
{
	int slot;
	int s;

	slot = find_free();
	if (slot == -1) {
		printf("\n������ ��������\n");
		
		return;
	}
	printf("������� �������� �����: ");
	gets_s(list_of_student[slot].name);

	printf("������� ������ �����: ");
	cin >> list_of_student[slot].surname;
	printf("������� ������������: ");
	cin >> list_of_student[slot].department;

	printf("������� ��� ������� : ");
	cin >> (list_of_student[slot].group);
	
	printf("������� ID ����� : ");
	cin >> list_of_student[slot].id;
	//= strtoul(s, '\0', 10);
	
}
int find_free(void) {
	register int t;
	for (t = 0; list_of_student[t].name[0] && t < MAX; t++);
	if (t == MAX) return -1; 
	return t;
}

void delete_(void) {
	register int slot;
	char s[80];

	printf("������� � ������()");
	gets_s(s);
	slot = atoi(s);
	if (slot >= 0 && slot < MAX)
		list_of_student[slot].name[0] = '\0';
}

void list(void){
	register int t;

	for (t = 0; t < MAX; ++t) {
		if (list_of_student[t].name[0]) {
			printf("%s\n", list_of_student[t].name);
			printf("%s\n", list_of_student[t].surname);
			printf("%s\n", list_of_student[t].department);
			printf("%d\n", list_of_student[t].group);
			printf("%lu\n\n", list_of_student[t].id);
		}
	}
	printf("\n\n");

	}
void search() {
	int k; 
	cout << "Ur student id(XXXX)" << endl;
	cin >> k; 

	for (int t = 0; t  < MAX; t ++) {
		if (list_of_student[t].id == k ) {
			printf("%s\n", list_of_student[t].name);
			printf("%s\n", list_of_student[t].surname);
			printf("%s\n", list_of_student[t].department);
			printf("%d\n", list_of_student[t].group);
			printf("%lu\n\n", list_of_student[t].id);
		}
	}
}
void searchMAX() {
	int arr[MAX];
	for (int t = 0; t < MAX; t++) {
		arr[t] = list_of_student[t].group;
	}
	int max = arr[0];
	for (int i = 0; i < MAX; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	for (int t = 0; t < MAX; t++) {
		
			printf("%s\n", list_of_student[t].name);
			printf("%s\n", list_of_student[t].surname);
			printf("%s\n", list_of_student[t].department);
			printf("%d\n", list_of_student[t].group);
			printf("%lu\n\n", list_of_student[t].id);
	}
	cout << " ������  ������ ��� �������" << max << endl;

}
void del()
{
	int d;
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������ 99)" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_student[de1] = list_of_student[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 99)
		for (int i = 0; i < size; i++)
			list_of_student[i] = bad;
	exit;
}

void change()
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
			cin >> list_of_student[n - 1].name;   break;
		case 2: cout << "����� ��� �������";
			cin >> list_of_student[n - 1].year_of_birth; break;
		case 3: cout << "����� ����� ";
			cin >> list_of_student[n - 1].department; break;
		case 4: cout << "����� ����� ������ ";
			cin >> list_of_student[n - 1].group; break;
		case 5: cout << "����� ������ ";
			cin >> list_of_student[n - 1].avg; break;
		}
	} while (per != 6);
	exit;
}

void out()
{
	int sw, n;
	cout << "1������ 1 ������" << endl;
	cout << "2������ ���� �����" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "����� ��������� ������ " << endl;   cin >> n;  cout << endl;
		cout << "������� ��������";
		cout << list_of_student[n - 1].name << endl;
		cout << "��� ������� ";
		cout << list_of_student[n - 1].year_of_birth << endl;
		cout << "����� ";
		cout << list_of_student[n - 1].department << endl;
		cout << "����� ������ ";
		cout << list_of_student[n - 1].group << endl;
		cout << "������ ";
		cout << list_of_student[n - 1].avg << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "������� �������� ";
			cout << list_of_student[i].name << '\t';
			cout << "��� ������� ";
			cout << list_of_student[i].year_of_birth << '\t';
			cout << "����� ";
			cout << list_of_student[i].department << endl;
			cout << "����� ������ ";
			cout << list_of_student[i].department << endl;
			cout << "������ ";
			cout << list_of_student[i].avg << endl;
		}
	}
	exit;
}

int main()
{
	int choice;
	init_list();
	setlocale(LC_CTYPE, "Russian");
	cout << "�������:" << endl;
	do
	{

		cout << "1���� �������� ������" << endl;
		cout << "2���� ����� ����� ������" << endl;
		cout << "3���� ��������� ������" << endl;
		cout << "4���� ������ ������(��)" << endl;
		cout << "5���� ������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:  change();  break;
		case 4:  out();	break;
		}
	} while (choice != 5);
}

