//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//
//int _stateMenu,reg,con;
//
//void StartMenu() {
//	cout << "Добро пожаловать в нашу ТЕлеКомпУ" << endl;
//	cout << "Вы уже были зарегистрированны у нас?(если да-выберите 'Продолжить')";
//	cout << ",если нет-выберите 'Регистрация'" << endl
//		<< "(1) Продолжить" << endl
//		<< "(2) Регистрация" << endl
//		<< "(0) Ошиблись компанией" << endl
//		<< "Ваш выбор: ";
//	cin >> _stateMenu;
//}
//void Regist() {
//	cout << "Добро пожаловать в нашу ТЕлеКомпУ" << endl;
//	cout << "Пройдите регистрацию(по нажатию открывается ввод информации)" << endl
//		<< "(1) Контактное лицо" << endl
//		<< "(2) Телефон" << endl
//		<< "(3) Банковские реквизиты" << endl
//		<< "(4) Закончить/Отменить регистрацию"<< endl
//		<< "Ваш выбор: ";
//	cin >> reg;
//}
//void Continue() {
//	
//	cout << "Здравствуйте" << endl;
//	cout << "Выберите куда и когда поместить вашу рекламу" << endl
//		<< "(1) Выбор даты" << endl
//		<< "(2) Выбор передачи" << endl
//		<< "(3) Ввод длительности рекламы" << endl
//		<< "После введения информации - жмите продолжить" << endl
//		<< "(4) Продолжить" << endl
//		<< "(5) Назад" << endl
//		<< "(0) Закончить/Отменить Заказ"<< endl
//		<< "Ваш выбор: ";
//	cin >> con;
//}
//void Info() {
//	cout << "Рекламная минута для вас будет стоить:" << endl
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
//					cout << "Дата записана" << endl<<endl;
//					Continue();
//					break;
//				case 2:
//					cout << endl;
//					cout << "Передача записана" << endl<<endl;
//					Continue();
//					break;
//				case 3:
//					cout << endl;
//					cout << "Длительность записана" << endl<<endl;
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
//					cout << "Неверно введен номер действия!" << endl;
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
//					cout << "Контактное лицо записано" << endl << endl;
//					Regist();
//					break;
//				case 2:
//					cout << endl;
//					cout << "Телефон записан" << endl << endl;
//					Regist();
//					break;
//				case 3:
//					cout << endl;
//					cout << "Реквизиты записаны" << endl << endl;
//					Regist();
//					break;
//				case 4:
//					StartMenu();
//					break;
//				default:
//					system("cls");
//					cout << "Неверно введен номер действия!" << endl;
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
//			cout << "Неверно введен номер действия!" << endl;
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
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << " \n Фамилия водителя: ";
		cin >> list_of_student[current_size].name;
		cout << "\n Год выпуска машины: ";
		cin >> list_of_student[current_size].year_of_birth;
		cout << "\n Марка машины: ";
		cin >> list_of_student[current_size].department;
		cout << "\n Номер гаража: ";
		cin >> list_of_student[current_size].group;
		cout << "\n Пробег: ";
		cin >> list_of_student[current_size].avg;
		current_size++;
		cout << endl;
	}
	else
		cout << "Введено максимальное кол–во строк";
	exit;
}

void del()
{
	int d;
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
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
	cout << "\nВведите номер строки" << endl; 	cin >> n;
	do
	{
		cout << "Введите: " << endl;
		cout << "1–для изменения фамилии водителя" << endl;
		cout << "2–для изменения года выпуска" << endl;
		cout << "3–для изменения марки" << endl;
		cout << "4–для изменения номера гаража" << endl;
		cout << "5–для изменения пробега" << endl;
		cout << "6–конец\n";
		cin >> per;
		switch (per)
		{
		case 1: cout << "Новая фамилия водителя";
			cin >> list_of_student[n - 1].name;   break;
		case 2: cout << "Новый год выпуска";
			cin >> list_of_student[n - 1].year_of_birth; break;
		case 3: cout << "Новая марка ";
			cin >> list_of_student[n - 1].department; break;
		case 4: cout << "Новый номер гаража ";
			cin >> list_of_student[n - 1].group; break;
		case 5: cout << "Новый пробег ";
			cin >> list_of_student[n - 1].avg; break;
		}
	} while (per != 6);
	exit;
}

void out()
{
	int sw, n;
	cout << "1–вывод 1 строки" << endl;
	cout << "2–вывод всех строк" << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Номер выводимой строки " << endl;   cin >> n;  cout << endl;
		cout << "Фамилия водителя";
		cout << list_of_student[n - 1].name << endl;
		cout << "Год выпуска ";
		cout << list_of_student[n - 1].year_of_birth << endl;
		cout << "Марка ";
		cout << list_of_student[n - 1].department << endl;
		cout << "Номер гаража ";
		cout << list_of_student[n - 1].group << endl;
		cout << "Пробег ";
		cout << list_of_student[n - 1].avg << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			cout << "Фамилия водителя ";
			cout << list_of_student[i].name << '\t';
			cout << "Год выпуска ";
			cout << list_of_student[i].year_of_birth << '\t';
			cout << "Марка ";
			cout << list_of_student[i].department << endl;
			cout << "Номер гаража ";
			cout << list_of_student[i].department << endl;
			cout << "Пробег ";
			cout << list_of_student[i].avg << endl;
		}
	}
	exit;
}

int main()
{
	int choice;
	setlocale(LC_CTYPE, "Russian");
	cout << "Данных нет" << endl;
	cout << "Введите:" << endl;
	do
	{
	
		cout << "1–для удаления записи" << endl;
		cout << "2–для ввода новой записи" << endl;
		cout << "3–для изменения записи" << endl;
		cout << "4–для вывода записи(ей)" << endl;
		cout << "5–для выхода" << endl;
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

