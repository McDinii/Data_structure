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
		cout << "Выберите вариант работы" << endl;
		cout << "1 - 15ый вариант 1 задание " << endl;
		cout << "2 - 15ый вариант 2 задание " << endl;
		cout << "3 - 3 задание" << endl;
		cout << "4 - 4 задание" << endl;
		cout << "5 - 5 задние" << endl;
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
	/* Написать программу, в которой нужно
	удалить все элементы односвязного списка и
	добавить n новых, с выводом на экран.*/


	setlocale(LC_ALL, "rus"); int choice1;
	forward_list<int> newlist = { 6, 2, 8, 4, 5 };
	cout << "1-ый член массива: " << newlist.front() << endl;
	// newlist.back() не работает, так как в односвязном списке напрямую
	//можно получить доступ только к 1-ому элементу
	do {
		cout << "1-Удалить все из списка " << endl;
		cout << "2-Добавить n новых и вывести на экран" << endl;
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
			cout << "Сколько элементов добавим в список?" << endl;
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Вводите значение элемента №" << i + 1 << endl;
				cin >> el;
				newlist.push_front(el);
			}
			cout << "Итоговый список" << endl;
			for (int k : newlist) {
				cout << k << "\t";
			}
			break;

		}
	} while (choice1 != 0);

	//auto iter = newlist.begin(); // итератор указывает на 1-ой элемент
	//newlist.emplace_after(iter, 15); // добавляем после 1-ого элемента
	//for (int n : newlist)
	//{
	//	cout << n << "\t";
	//}
}