#include <iostream>
#include <forward_list>

using namespace std;
void task1();
int main()
{
	setlocale(LC_ALL, "rus");
	int choice;
	do
	{
		cout << endl;
		cout << "�������� ������� ������" << endl;
		cout << "1 - 15�� ������� 1 ������� " << endl;
		cout << "2 - 15�� ������� 2 ������� " << endl;
		cout << "3 - 3 �������" << endl;
		cout << "4 - 4 �������" << endl;
		cout << "5 - 5 ������" << endl;
		cout << "0 - end" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1: task1(); break;
		case 2: /*task2();*/

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

	//auto iter = newlist.begin(); // �������� ��������� �� 1-�� �������
	//newlist.emplace_after(iter, 15); // ��������� ����� 1-��� ��������
	//for (int n : newlist)
	//{
	//	cout << n << "\t";
	//}
}