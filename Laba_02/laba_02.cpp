//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//int _stateMenu,reg,con;
//
//void StartMenu() {
//	cout << "����� ���������� � ���� ���������" << endl;
//	cout << "�� ��� ���� ����������������� � ���?(���� ��-�������� '����������')";
//	cout << ",���� ���-�������� '�����������'" << endl
//		<< "(1) ����������" << endl
//		<< "(2) �����������" << endl
//		<< "(0) �������� ���������" << endl
//		<< "��� �����: ";
//	cin >> _stateMenu;
//}
//void Regist() {
//	cout << "����� ���������� � ���� ���������" << endl;
//	cout << "�������� �����������(�� ������� ����������� ���� ����������)" << endl
//		<< "(1) ���������� ����" << endl
//		<< "(2) �������" << endl
//		<< "(3) ���������� ���������" << endl
//		<< "(4) ���������/�������� �����������"<< endl
//		<< "��� �����: ";
//	cin >> reg;
//}
//void Continue() {
//	
//	cout << "������������" << endl;
//	cout << "�������� ���� � ����� ��������� ���� �������" << endl
//		<< "(1) ����� ����" << endl
//		<< "(2) ����� ��������" << endl
//		<< "(3) ���� ������������ �������" << endl
//		<< "����� �������� ���������� - ����� ����������" << endl
//		<< "(4) ����������" << endl
//		<< "(5) �����" << endl
//		<< "(0) ���������/�������� �����"<< endl
//		<< "��� �����: ";
//	cin >> con;
//}
//void Info() {
//	cout << "��������� ������ ��� ��� ����� ������:" << endl
//		<< "99999$"<<endl;
//}
///// <summary>
///// ////////////////////
///// </summary>
//void dop() {
//
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	StartMenu();
//	do {
//
//		switch (_stateMenu)
//		{
//		case 1:
//			Continue();
//			do  {
//
//				switch (con)
//				{
//				case 1:
//					cout << endl;
//					cout << "���� ��������" << endl<<endl;
//					Continue();
//					break;
//				case 2:
//					cout << endl;
//					cout << "�������� ��������" << endl<<endl;
//					Continue();
//					break;
//				case 3:
//					cout << endl;
//					cout << "������������ ��������" << endl<<endl;
//					Continue();
//					break;
//				case 4:
//					cout << endl;
//					Info();
//					return 0;
//				case 5:
//					StartMenu();
//					break;
//				case 6: 
//					dop();///////
//					break;
//				default:
//					system("cls");
//					cout << "������� ������ ����� ��������!" << endl;
//					system("pause");
//					system("cls");
//					StartMenu();
//					break;
//				}
//			} while (con != 5);
//			break;
//		case 2:
//			Regist();
//			do  {
//
//				switch (reg)
//				{
//				case 1:
//					cout << endl;
//					cout << "���������� ���� ��������" << endl << endl;
//					Regist();
//					break;
//				case 2:
//					cout << endl;
//					cout << "������� �������" << endl << endl;
//					Regist();
//					break;
//				case 3:
//					cout << endl;
//					cout << "��������� ��������" << endl << endl;
//					Regist();
//					break;
//				case 4:
//					StartMenu();
//					break;
//				default:
//					system("cls");
//					cout << "������� ������ ����� ��������!" << endl;
//					system("pause");
//					system("cls");
//					StartMenu();
//					break;
//
//				}
//
//			} while (reg != 4);
//		case 0:break;
//			break;
//		default:
//			system("cls");
//			cout << "������� ������ ����� ��������!" << endl;
//			system("pause");
//			system("cls");
//			StartMenu();
//			break;
//		}
//	} while (_stateMenu != 0);
//}
# include <iostream>                    
# define str_len 30                               
# define size 30  
using namespace std;



struct Student
{
	char name[str_len];
	int year_of_birth;
	char department[5];
	int group;
	int avg;
};

struct Student list_of_student[size];
struct Student bad;
int current_size = 0;

void enter_new()
{
	cout << "���� ����������" << endl;
	if (current_size < size)
	{
		cout << "������ ����� ";
		cout << current_size + 1;
		cout << endl << " \n ������� ��������: ";
		cin >> list_of_student[current_size].name;
		cout << "\n ��� ������� ������: ";
		cin >> list_of_student[current_size].year_of_birth;
		cout << "\n ����� ������: ";
		cin >> list_of_student[current_size].department;
		cout << "\n ����� ������: ";
		cin >> list_of_student[current_size].group;
		cout << "\n ������: ";
		cin >> list_of_student[current_size].avg;
		current_size++;
		cout << endl;
	}
	else
		cout << "������� ������������ ����� �����";
	exit;
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
	setlocale(LC_CTYPE, "Russian");
	cout << "������ ���" << endl;
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

