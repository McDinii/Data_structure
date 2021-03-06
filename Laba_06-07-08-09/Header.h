#pragma once
#include "laba.h"

using namespace Struct;

void Add(job* (&a), int& n) {
	job* b = new job[n + 1];

	string name, lastName, jobName, phone;
	float salary;
	int Id;

	cout << "name: ";
	cin >> name;
	cout << "\nlastName: ";
	cin >> lastName;
	cout << "\njobName: ";
	cin >> jobName;
	cout << "\nphone: ";
	cin >> phone;
	cout << "\nsalary: ";
	cin >> salary;
	cout << "\nid: ";
	cin >> Id;

	for (int i = 0; i < n; i++) {
		b[i].name = a[i].name;
		b[i].lastName = a[i].lastName;
		b[i].jobName = a[i].jobName;
		b[i].phone = a[i].phone;
		b[i].salary = a[i].salary;
		b[i].id = a[i].id;
	}

	b[n].name = name;
	b[n].lastName = lastName;
	b[n].jobName = jobName;
	b[n].phone = phone;
	b[n].salary = salary;
	b[n].id = Id;
	n++;

	a = new job[n];

	for (int i = 0; i < n; i++) {
		a[i].name = b[i].name;
		a[i].lastName = b[i].lastName;
		a[i].jobName = b[i].jobName;
		a[i].phone = b[i].phone;
		a[i].salary = b[i].salary;
		a[i].id = b[i].id;
	}

	delete[]b;
}

void Add(job* (&a), int& n, string name, string lastName, string jobName, string phone, float salary, int Id) {
	job* b = new job[n + 1];

	for (int i = 0; i < n; i++) {
		b[i].name = a[i].name;
		b[i].lastName = a[i].lastName;
		b[i].jobName = a[i].jobName;
		b[i].phone = a[i].phone;
		b[i].salary = a[i].salary;
		b[i].id = a[i].id;
	}

	b[n].name = name;
	b[n].lastName = lastName;
	b[n].jobName = jobName;
	b[n].phone = phone;
	b[n].salary = salary;
	b[n].id = Id;
	n++;

	a = new job[n];

	for (int i = 0; i < n; i++) {
		a[i].name = b[i].name;
		a[i].lastName = b[i].lastName;
		a[i].jobName = b[i].jobName;
		a[i].phone = b[i].phone;
		a[i].salary = b[i].salary;
		a[i].id = b[i].id;
	}

	delete[]b;
}

void Print(job* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << "name: " << arr[i].name << "\n"
			<< "lastName: " << arr[i].lastName << "\n"
			<< "jobName: " << arr[i].jobName << "\n"
			<< "phone: " << arr[i].phone << "\n"
			<< "salary: " << arr[i].salary << "\n"
			<< "id: " << arr[i].id << "\n\n";
	}
	system("pause");
}

void filePrint(job* (&a), int& n) {
	string fileName;
	fstream fs;
	int select;

	cout << "1)read from file\n"
		<< "2)Write to file\n";

	cin >> select;

	system("cls");
	cout << "file name: ";
	cin >> fileName;
	fs.open(fileName, fstream::in | fstream::out | fstream::app);

	if (fs.is_open()) {
		cout << "file is open\n";
	}
	else
	{
		cout << "an error occurred while opening the file\n";
	}

	system("pause");
	system("cls");
	if (select == 1) {
		while (!fs.eof())
		{
			string name, lastName, jobName, phone;
			float salary;
			int Id;
			fs >> name;
			if (name == "")break;
			fs >> lastName;
			fs >> jobName;
			fs >> phone;
			fs >> salary;
			fs >> Id;
			Add(a, n, name, lastName, jobName, phone, salary, Id);
		}
	}
	else if (select == 2) {
		for (int i = 0; i < n; i++) {
			fs << a[i].name << " " << a[i].lastName << " " << a[i].jobName << " " << a[i].phone << " " << a[i].salary << " " << a[i].id << "\n";
		}
	}
	else
	{
		cout << "there is no such item\n";
		system("pause");
	}

	fs.close();
}

void DeleteMasId(job* (&a), int& n) {
	int select;
	bool fg = false;
	cout << "Id: ";
	cin >> select;
	system("cls");

	for (int i = 0; i < n; i++) {
		if (a[i].id == select) {
			select = i;
			fg = true;
			break;
		}
	}

	if (!fg)return;

	job* b = new job[n - 1];

	int l = 0;
	for (int i = 0; i < n; i++) {
		if (i != select) {
			b[l].name = a[i].name;
			b[l].lastName = a[i].lastName;
			b[l].jobName = a[i].jobName;
			b[l].phone = a[i].phone;
			b[l].salary = a[i].salary;
			b[l].id = a[i].id;
			l++;
		}
	}

	n--;
	a = new job[n];

	for (int i = 0; i < n; i++) {
		a[i].name = b[i].name;
		a[i].lastName = b[i].lastName;
		a[i].jobName = b[i].jobName;
		a[i].phone = b[i].phone;
		a[i].salary = b[i].salary;
		a[i].id = b[i].id;
	}

	delete[]b;
}

void DeleteMasAll(job* (&a), int& n) {
	n = 0;
	a = new job[0];
}

void DeleteFileId() {
	int select;
	cout << "Id: ";
	cin >> select;
	system("cls");

	string FileName;
	cout << "FileName: ";
	cin >> FileName;

	fstream fs;
	fstream fs2;

	fs.open(FileName, fstream::in | fstream::out | fstream::app);
	fs2.open("wait.txt", fstream::out);
	fs2.close();
	fs2.open("wait.txt", fstream::in | fstream::out | fstream::app);

	int l = 0;

	while (!fs.eof())
	{
		string name, lastName, jobName, phone;
		float salary;
		int Id;
		fs >> name;
		if (name == "")break;
		fs >> lastName;
		fs >> jobName;
		fs >> phone;
		fs >> salary;
		fs >> Id;
		if (l != select) {
			fs2 << name << " " << lastName << " " << jobName << " " << phone << " " << salary << " " << Id << "\n";
		}
		l++;
	}

	char* z = new char[250];

	for (int i = 0; i < FileName.size(); i++) {
		z[i] = FileName[i];
	}
	z[FileName.size()] = '\0';

	fs2.close();
	fs.close();
	remove(z);
	rename("wait.txt", z);
}

void DeleteFileAll() {
	string FileName;
	cout << "FileName: ";
	cin >> FileName;
	fstream fs;
	fs.open(FileName, ios::out);
	fs.close();
}

void Delete(job* (&a), int& n) {
	int select;

	cout << "1)delete from array\n"
		<< "2)delete from file \n";
	cin >> select;

	system("cls");

	if (select == 1) {
		cout << "1)delete a specific element\n"
			<< "2)clear the entire array\n";
		cin >> select;

		system("cls");

		if (select == 1) {
			DeleteMasId(a, n);
		}
		else if (select == 2) {
			DeleteMasAll(a, n);
		}
	}
	else if (select == 2) {
		cout << "1)delete a specific element\n"
			<< "2)clear the entire file\n";
		cin >> select;

		system("cls");

		if (select == 1) {
			DeleteFileId();
		}
		else if (select == 2) {
			DeleteFileAll();
		}
	}
}

void Change(job* (&a), int n) {
	string name, lastName, jobName, phone;
	float salary;
	int Id;

	bool fg = false;
	cout << "Id: ";
	cin >> Id;
	system("cls");

	for (int i = 0; i < n; i++) {
		if (a[i].id == Id) {
			fg = true;
			cout << "name: ";
			cin >> name;
			cout << "\nlastName: ";
			cin >> lastName;
			cout << "\njobName: ";
			cin >> jobName;
			cout << "\nphone: ";
			cin >> phone;
			cout << "\nsalary: ";
			cin >> salary;
			cout << "\nid: ";
			cin >> Id;
			system("cls");

			a[i].name = name;
			a[i].lastName = lastName;
			a[i].jobName = jobName;
			a[i].phone = phone;
			a[i].salary = salary;
			a[i].id = Id;

			break;
		}
	}

	if (fg == true) {
		cout << "GOOD\n";
	}
	else {
		cout << "FAIL\n";
	}

	system("pause");
}

void SortName(job* (&a), int n) {//?????????? ?? ??????? ???? ??????????? ? ?????????? ? ??????
	int smallest_id;

	for (int i = 0; i < n; i++) {
		smallest_id = i;

		for (int j = i + 1; j < n; j++) {
			if (a[j].name < a[smallest_id].name)
				smallest_id = j;
		}

		swap(a[smallest_id], a[i]);
	}
}

void SortLastName(job* (&a), int n) {//??????? ?? ????????, ?????????? ????? ??????? ???????? ? ??????
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].lastName > a[j].lastName) {
				swap(a[i], a[j]);
			}
		}
	}
}

void SortPhone(job* (&a), int n) {//???? ????????, ???????? ??????????
	job key;
	int i = 0;

	for (int j = 1; j < n; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i].phone > key.phone) {
			a[i + 1] = a[i];
			i--;
			a[i + 1] = key;
		}
	}

}

void merge(job merged[], int lenD, job L[], int lenL, job R[], int lenR) {
	int i = 0;
	int j = 0;
	while (i < lenL || j < lenR) {
		if (i < lenL && j < lenR) {
			if (L[i].salary <= R[j].salary) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i < lenL) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j < lenR) {
			merged[i + j] = R[j];
			j++;
		}
	}
}

void SortSalary(job* (&a), int n) {
	if (n > 1) {
		int middle = n / 2;
		int rem = n - middle;
		job* L = new job[middle];
		job* R = new job[rem];

		for (int i = 0; i < n; i++) {
			if (i < middle) {
				L[i] = a[i];
			}
			else {
				R[i - middle] = a[i];
			}
		}

		SortSalary(L, middle);
		SortSalary(R, rem);
		merge(a, n, L, middle, R, rem);
	}
}

void SortId(job* (&a), int left, int right) {
	int	l_hold = left, r_hold = right;
	job pivot = a[left];

	while (left < right)
	{
		while ((a[right].id >= pivot.id) && (left < right))
			right--;
		if (left != right)
		{
			a[left] = a[right];
			left++;
		}
		while ((a[left].id <= pivot.id) && (left < right))
			left++;
		if (left != right)
		{
			a[right] = a[left];
			right--;
		}
	}

	a[left] = pivot;
	pivot.id = left;
	left = l_hold;
	right = r_hold;

	if (left < pivot.id)
		SortId(a, left, pivot.id - 1);
	if (right > pivot.id)
		SortId(a, pivot.id + 1, right);
}

void Sort(job* (&a), int n) {
	int select;
	cout << "1)sort by name (selective)\n"
		<< "2)sort by Last Name(bubble)\n"
		<< "3)sort by phone number(insert)\n"
		<< "4)sort by salary(merge)\n"
		<< "5)sort by id(fast);\n";
	cin >> select;

	system("cls");

	if (select == 1) {
		SortName(a, n);
	}
	else if (select == 2) {
		SortLastName(a, n);
	}
	else if (select == 3) {
		SortPhone(a, n);
	}
	else if (select == 4) {
		SortSalary(a, n);
	}
	else if (select == 5) {
		SortId(a, 0, n - 1);
	}
}

void FindStr(job* (&a), int n) {
	string lastName;
	cout << "Search for a substring in a surname: ";
	cin >> lastName;
	system("cls");

	for (int i = 0; i < n; i++) {
		int l = a->lastName.size();
		int l2 = lastName.size();
		int fg = 0;
		string x = a[i].lastName;

		for (int j = 0; j < l; j++) {
			if (j + l2 > l + fg)break;
			if (lastName[fg] != x[j]) {
				fg = 0;
				continue;
			}
			fg++;
			if (fg == l2) {
				cout << "there was such an element: \n"
					<< "name: " << a[i].name << "\n"
					<< "lastName: " << a[i].lastName << "\n"
					<< "jobName: " << a[i].jobName << "\n"
					<< "phone: " << a[i].phone << "\n"
					<< "salary: " << a[i].salary << "\n"
					<< "id: " << a[i].id << "\n\n";
				break;
			}
		}
	}
	system("pause");
}

void FoundAlg(job* (&a), int n) {
	int select;
	cout << "1)interpolating salary search\n"
		<< "2)binary search by last name\n";
	cin >> select;
	system("cls");
	if (select == 1) {
		float find;
		cout << "salary: ";
		cin >> find;

		bool fg = false;
		int l = 0, r = n - 1, x = 0;

		while (l < r && !fg) {
			x = l + ((find - a[l].salary) * (l - r)) / (a[l].salary - a[r].salary);

			if (a[x].salary < find)
				l = x + 1;
			else if (a[x].salary > find)
				r = x - 1;
			else {
				l = x;
				fg = true;
			}
		}

		if (a[l].salary == find) {
			cout << "id of the element with this salary: " << a[l].id;
		}
		else if (a[r].salary == find) {
			cout << "id of the element with this salary: " << a[r].id;
		}
		else {
			cout << "there is no such element";
		}
		cout << endl;

		system("pause");

	}
	else if (select == 2) {
		string lastName;
		cout << "lastName: ";
		cin >> lastName;

		int l = 0, r = n - 1;

		while (l < r) {
			int mid = (r + l) / 2;

			if (a[mid].lastName > lastName)
				r = mid - 1;
			else if (a[mid].lastName < lastName)
				l = mid + 1;
			else {
				l = mid;
				r = mid;
			}

		}

		if (a[l].lastName == lastName) {
			cout << "id of an element with this last name: " << a[l].id;
		}
		else if (a[r].lastName == lastName) {
			cout << "id of an element with this last name: " << a[r].id;
		}
		else {
			cout << "there is no such element";
		}
		cout << endl;

		system("pause");

	}
}