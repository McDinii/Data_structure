//Преподаватели.Фамилия преподавателя,
//название экзамена, дата экзамена.Выбор по фамилии.

//#include <iostream>      
//#include <fstream>
//#include <string>
//#include <stdio.h>
//#include <vector>
//#include <sstream>
//#include <algorithm>
//# define str_len 25
//# define size3 3  
//using namespace std;
//void enter_new();
//void del();
//void find(char Name[]);
//void out();
//void dop2();
//typedef struct Exam
//{
//	char examName[str_len];
//	char day[str_len];
//	char month[str_len];
//	char lastName[str_len];
//
//} ex;
//struct Exam list_of_student[size3];
//struct Exam bad;
//FILE* f; FILE* f1; FILE* f2; errno_t err;
//int current_size = 0; int choice;
//int main()
//{
//	char name[str_len];
//	setlocale(LC_ALL, "Russian");
//	cout << "Введите:" << endl;
//	cout << "1-для удаления записи" << endl;
//	cout << "2-для ввода новой записи" << endl;
//	cout << "3-для поиска по структуре" << endl;
//	cout << "4-для вывода записи(ей)" << endl;
//	cout << "6-для допа№2"<< endl;
//	cout << "5-для выхода" << endl;
//	cin >> choice;
//	do
//	{
//		switch (choice)
//		{
//		case 1:  del();	break;
//		case 2:  enter_new();  break;
//		case 3:  
//			cout << "Введите фамилию" << endl;
//			cin >> name;
//			find(name);  break;
//		case 4:  out();	break;
//		case 6:  dop2;	break;
//		}
//	} while (choice != 5);
//}
//void enter_new()
//{
//	cout << "Ввод информации" << endl;
//	ex buf = { ' ', ' ', ' ', ' ',' '};
//	if (!fopen_s(&f, "main.bin", "ab")) {
//			if (current_size < size3)
//			{	cout << "Строка номер ";
//				cout << current_size + 1;
//				cout << endl << "Фамилия " << endl;
//				cin >> buf.lastName;
//				cout << "День экзамена " << endl;
//				cin >> buf.day;
//				cout << "Месяц экзамена  " << endl;
//				cin >> buf.month;
//				cout << "Название экзамена  " << endl;
//				cin >> buf.examName;
//				fwrite(&buf, sizeof(buf), 1, f);
//				current_size++;
//			}
//
//		else {
//			cout << "Введено максимальное кол-во строк" << endl;
//			cout << "Что дальше?" << endl;
//			cin >> choice;
//		}
//		fclose(f);
//	}
//	else {
//		cout << "Ошибка открытия файла";
//		return;
//	}
//	
//}
//void del()
//{
//	ex buf;
//	bool non = false;
//	int chv2;
//	char name[str_len];
//	cout << "Введите 1 - для удаления информации определенной фамилии \n 2 - для удаления всей информации\n";
//	cin >> chv2;
//	switch (chv2) {
//	case 1: {
//		cout << "\n Введите фамилию\n";
//		cin >> name;
//		errno_t err;
//		err = fopen_s(&f, "main.bin", "rb");
//		if (err != 0)
//		{
//			perror("ошибка открытия файла");
//			return;
//		}
//		errno_t err1;
//		err1 = fopen_s(&f1, "temp.bin", "ab");
//		if (err1 != 0)
//		{
//			perror("ошибка открытия файла");
//			return;
//		}
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f)) {
//			if (strcmp(name, buf.lastName) != 0) {
//				fwrite(&buf, sizeof(buf), 1, f1);
//				fread(&buf, sizeof(buf), 1, f);
//			}
//			else {
//				fread(&buf, sizeof(buf), 1, f);
//				non = true;
//			}
//		}
//		if (non == false) {
//			cout << "Информации не найдено" << endl;
//		}
//		else {
//			current_size--;
//		}
//		fclose(f);
//		fclose(f1);
//		remove("main.bin");
//		rename("temp.bin", "main.bin");
//		break;
//
//	}
//	case 2: {
//		errno_t err3, err4;
//		err3 = fopen_s(&f, "main.bin", "rb");
//		if (err3 != 0)
//		{
//			perror("ошибка открытия файла");
//			return;
//		}
//		err4 = fopen_s(&f2, "temp2.bin", "ab");
//		if (err4 != 0)
//		{
//			perror("ошибка открытия файла");
//			return;
//		}
//		fclose(f);
//		fclose(f2);
//		remove("main.bin");
//		rename("temp2.bin", "main.bin");
//		fclose(f);
//		fclose(f2);
//		current_size = 0;
//		break;
//	}
//	}
//
//	cout << endl << "Что дальше?" << endl;
//	cin >> choice;
//
//}
//void find(char Name[])
//{
//	bool non = false;
//	ex buf;
//	if (!fopen_s(&f, "main.bin", "rb")) 
//	{
//		cout << "\nФамилия     |   Экзамен     |   День     |  Месяц\n";
//		fread(&buf, sizeof(buf), 1, f);
//		while (!feof(f))
//		{
//			if (strcmp(Name, buf.lastName) == 0) {
//				non = true;
//				cout << buf.lastName << "\t\t" << buf.examName << "\t\t" << buf.day << "\t    " << buf.month << endl;
//				break;
//			}
//			else { fread(&buf, sizeof(buf), 1, f); }
//		}
//		if (non == false) {
//			cout << "Информации не найдено" << endl;
//		}
//	
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//	cout << endl << "Что дальше?" << endl;
//	cin >> choice;
//	
//}
//void out()
//{
//	cout << endl;
//	ex buf;
//	if (!fopen_s(&f, "main.bin", "rb")) {
//		cout << "\nФамилия     |   Экзамен     |   День     |  Месяц\n";
//		fread(&buf, sizeof(buf), 1, f);
//		current_size = 0;
//		while (!feof(f))
//		{
//			cout << buf.lastName << "\t\t" << buf.examName << "\t\t" << buf.day << "\t    " << buf.month << endl;
//			fread(&buf, sizeof(buf), 1, f);
//			current_size++;
//		}
//		cout << endl;
//		fclose(f);
//	}
//	else
//	{
//		cout << "Ошибка открытия файла";
//		return;
//	}
//
//	cout << endl << "Что дальше?" << endl;
//	cin >> choice;
//
//	
//}
//struct Camp {
//	string CampName;
//	string CampPlace;
//	string CampType;
//	int voucher;
//};
//
//bool comp1(Camp lhs, Camp rhs)
//{
//	return lhs.CampName < rhs.CampName;
//}
//
//bool comp(Camp lhs, Camp rhs)
//{
//	return lhs.CampType < rhs.CampType;
//}
//
//void showInfo(Camp* lagger, int SIZE) {
//	sort(lagger, lagger + SIZE, comp);
//	int index1 = 0;
//	int index2 = 0;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		if (lagger[i].CampType == lagger[i + 1].CampType)
//		{
//			index1 = i;
//			break;
//		}
//	}
//
//	for (int i = SIZE; i > 0; i--)
//	{
//		if (lagger[i].CampType == lagger[i - 1].CampType)
//		{
//			index2 = i;
//			break;
//		}
//	}
//
//	sort(lagger + index1, lagger + index2 + 1, comp1);
//
//
//	for (int i = 0; i < SIZE; ++i) {
//		cout << "Название лагеря: " << lagger[i].CampName << "\t";
//		cout << "Место лагеря: " << lagger[i].CampPlace << "\t";
//		cout << "Профиль лечения: " << lagger[i].CampType << "\t\t";
//		cout << "Количество путевок: " << lagger[i].voucher << "\t" << endl;
//		cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
//	}
//
//}
//
//void ifileCamp(Camp* lagger, int SIZE)
//{
//
//	ifstream fin("lagggerInfo.txt");
//
//	if (!fin.is_open()) {
//		cout << "Не удаётся открыть файл для чтения " << endl;
//		exit(EXIT_FAILURE);
//	}
//
//	vector<string> fileinfo;
//	string line, word;
//	stringstream x;
//	for (int i = 0; i < SIZE; ++i) {
//		fin >> lagger[i].voucher;
//		getline(fin, line);
//		x << line;
//		while (x >> word)
//		{
//			fileinfo.push_back(word);
//		}
//		for (int k = 0; k < fileinfo.size(); k++)
//		{
//			if (k == 0) { lagger[i].CampName = fileinfo[k]; }
//			if (k == 1) { lagger[i].CampPlace = fileinfo[k]; }
//			if (k == 2) { lagger[i].CampType = fileinfo[k]; }
//		}
//		x.clear();
//		line.clear();
//		word.clear();
//		fileinfo.clear();
//	}
//	cout << "\nИнформация считана из файла lagggerInfo.txt\n\n";
//}
//
//void dop3()
//{
//
//	setlocale(LC_CTYPE, "ru");
//	const int SIZE = 5;
//	Camp lager[SIZE];
//	short choose;
//	do {
//		cout << "Выберите, что сделать:\n1 — вывести информацию из файла;\n2 — вывести в консоль информацию о путёвках;\n3 — выход\n";
//		cin >> choose;
//		switch (choose)
//		{
//		case 1: ifileCamp(lager, SIZE); break;
//		case 2: showInfo(lager, SIZE); break;
//		case 3: exit(0); break;
//		}
//	} while (choose != 3);
//}
//
//


#include <iostream>      
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <algorithm>
# define str_len 25
# define size3 3  
using namespace std;
void enter_new();
void del();
void find(char Name[]);
void out();
void card();
typedef struct Exam
{
	char examName[str_len];
	char day[str_len];
	char month[str_len];
	char lastName[str_len];

} ex;
struct Exam list_of_student[size3];
struct Exam bad;
FILE* f; FILE* f1; FILE* f2; errno_t err;
int current_size = 0; int choice;
int main()
{
	char name[str_len];
	setlocale(LC_ALL, "Russian");
	cout << "Введите:" << endl;
	cout << "1-для удаления записи" << endl;
	cout << "2-для ввода новой записи" << endl;
	cout << "3-для поиска по структуре" << endl;
	cout << "4-для вывода записи(ей)" << endl;
	cout << "6-для допа№2" << endl;
	cout << "5-для выхода" << endl;
	cin >> choice;
	do
	{
		switch (choice)
		{
		case 1:  del();	break;
		case 2:  enter_new();  break;
		case 3:
			cout << "Введите поле \"Член\" " << endl;
			cin >> name;
			find(name);  break;
		case 4:  out();	break;
		case 6:  card();	break;
		}
	} while (choice != 5);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	ex buf = { ' ', ' ', ' ', ' ',' ' };
	if (!fopen_s(&f, "main2.bin", "ab")) {
		if (current_size < size3)
		{
			cout << "Строка номер ";
			cout << current_size + 1;
			cout << endl << "Член " << endl;
			cin >> buf.lastName;
			cout << "День рождения " << endl;
			cin >> buf.day;
			cout << "Имя  " << endl;
			cin >>
			list_of_student[current_size].month;
			cout << "Место рождения  " << endl;
			cin >> buf.examName;
			fwrite(&buf, sizeof(buf), 1, f);
			current_size++;
		}

		else {
			cout << "Введено максимальное кол-во строк" << endl;
			cout << "Что дальше?" << endl;
			cin >> choice;
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
		return;
	}

}
void del()
{
	ex buf;
	bool non = false;
	int chv2;
	char name[str_len];
	cout << "Введите 1 - для удаления информации определенного члена \n 2 - для удаления всей информации\n";
	cin >> chv2;
	switch (chv2) {
	case 1: {
		cout << "\n Введите Члена\n";
		cin >> name;
		errno_t err;
		err = fopen_s(&f, "main2.bin", "rb");
		if (err != 0)
		{
			perror("ошибка открытия файла");
			return;
		}
		errno_t err1;
		err1 = fopen_s(&f1, "temp3.bin", "ab");
		if (err1 != 0)
		{
			perror("ошибка открытия файла");
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
			cout << "Информации не найдено" << endl;
		}
		else {
			current_size--;
		}
		fclose(f);
		fclose(f1);
		remove("main2.bin");
		rename("temp3.bin", "main2.bin");
		break;

	}
	case 2: {
		errno_t err3, err4;
		err3 = fopen_s(&f, "main2.bin", "rb");
		if (err3 != 0)
		{
			perror("ошибка открытия файла");
			return;
		}
		err4 = fopen_s(&f2, "temp3.bin", "ab");
		if (err4 != 0)
		{
			perror("ошибка открытия файла");
			return;
		}
		fclose(f);
		fclose(f2);
		remove("main2.bin");
		rename("temp3.bin", "main2.bin");
		fclose(f);
		fclose(f2);
		current_size = 0;
		break;
	}
	}

	cout << endl << "Что дальше?" << endl;
	cin >> choice;

}
void find(char Name[])
{
	bool non = false;
	ex buf;
	if (!fopen_s(&f, "main2.bin", "rb"))
	{
		cout << "\nЧлен     |   Место рождения     |   День рождения     |  Имя\n";
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
			cout << "Информации не найдено" << endl;
		}

		fclose(f);
	}
	else
	{
		cout << "Ошибка открытия файла";
		return;
	}
	cout << endl << "Что дальше?" << endl;
	cin >> choice;

}
void out()
{
	cout << endl;
	ex buf;
	if (!fopen_s(&f, "main2.bin", "rb")) {
		cout << "\nЧлен     |   Место рождения     |   День рождения     |  Имя\n";
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
		cout << "Ошибка открытия файла";
		return;
	}

	cout << endl << "Что дальше?" << endl;
	cin >> choice;


}

void card() {
		cout << "___________________________" << endl;
		cout << "*Happy birthday, dear " << list_of_student[0].month; cout << "*\n";
		cout << "*your " << list_of_student[1].month << ", " << list_of_student[2].month; cout  << '\t' << " *\n";
		cout << "___________________________" << endl;
		cout << endl;
		cout << "___________________________" << endl;
		cout << "*Happy birthday, dear " << list_of_student[1].month; cout << "*\n";
		cout << "*your " << list_of_student[0].month << ", " << list_of_student[2].month; cout  << '\t' << " *\n";
		cout << "___________________________" << endl;
		cout << endl;
		cout << "___________________________" << endl;
		cout << "*Happy birthday, dear " << list_of_student[2].month; cout << "*\n";
		cout << "*your " << list_of_student[1].month << ", " << list_of_student[0].month; cout  << '\t' << " *\n";
		cout << "___________________________" << endl;
		cout << endl;
		
		
		cout << endl << "Что дальше?" << endl;
		cin >> choice;
}








