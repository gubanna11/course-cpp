#include "factory.h"
#include "product.h"

factory::factory() {
	size = 2;
	index = 0;
	depart = new product[size];
}

void factory::add(product data) {
	if (index < size) {
		depart[index++] = data;
	}
	else {
		product* p = new product[size * 2];
		for (int i = 0; i < index; i++)
		{
			p[i] = depart[i];
		}
		size *= 2;
		delete[]depart;
		depart = p;
		add(data);
	}
}

void factory::input() {
	system("cls");
	product temp;
	setDepart(temp);
	add(temp);
	system("pause");
}

void factory::show() {
	system("cls");
	if (index == 0)
		cout << "Список пустий!\n";
	else {
		for (int i = 0; i < index; i++)
		{
			depart[i].Print();
		}
	}
	cout << endl;
	system("pause");
}

void factory::save() {
	system("cls");
	ofstream fs("myFile.txt");
	if (index == 0)
		cout << "Список пустий!\n";
	else {
		for (int i = 0; i < index; i++)
		{
			fs << depart[i] << endl;
		}
		cout << "Дані збережені!\n";
	}
	fs.close();
	system("pause");
}

void factory::read() {
	system("cls");
	ifstream fs("myFile.txt");
	product t;
	if (!fs.is_open()) {
		cout << "Неможливо відкрити файл!\n";
	}
	else if (isempty(fs))
		cout << "Список пустий!\n";
	else {
		if (fs.is_open()) {
			index = 0;
			while (true)
			{
				fs >> t;
				if (fs.eof())
					break;
				add(t);
			}
			cout << "Дані зчитані!\n";
		}
	}
	fs.close();
	system("pause");
}

bool factory::isempty(istream& fs) {
	return fs.peek() == ifstream::traits_type::eof();
}

int factory::searchDepNum(int num) {
	for (int i = 0; i < index; i++)
	{
		if (depart[i].get_departmentNumber() == num)
			return i;
	}
	return -1;
}

void factory::delDepNum() {
	system("cls");

	int num;
	char str[10];

	while (true) {
		cout << "Введіть номер цеху, який бажаєте видалити >> ";
		cin >> str;
		double n = atof(str);
		if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
			cout << "Ви ввели некоректне значення!\n";
		}
		else break;
		cout << "Повторіть ввод:\n";
	}
	num = atoi(str);
	if (searchDepNum(num) == -1) cout << "Цеху з таким номером немає!\n";
	else {
		int temp = index, count = 0;
		while (searchDepNum(num) != -1) {
			count++;
			for (int i = searchDepNum(num); i < index; i++)
			{
				depart[i] = depart[i + 1];
				index--;
			}
		}
		index = temp - count;
		cout << "Цех №" << num << " видалено!\n";
	}
	system("pause");
}

int factory::datacmp(date d1, date d2) {
	if (d1.year > d2.year) return 1;

	if (d1.year < d2.year) return -1;

	if (d1.month > d2.month)  return 1;

	if (d1.month < d2.month) return -1;

	if (d1.day > d2.day) return 1;

	if (d1.day < d2.day) return -1;

	return 0;
}

void factory::sort_date() {
	for (int i = 0; i < index - 1; i++)
	{
		for (int j = 0; j < index - i - 1; j++)
		{
			if (datacmp(depart[j].getDate(), depart[j + 1].getDate()) <= 0)
				swap(depart[j], depart[j + 1]);
		}
	}
}

void factory::sort() {

	for (int i = 0; i < index; i++)
	{
		depart[i].sortName(depart[i]);
	}
	sort_date();
}

void factory::searchDepName() {
	system("cls");
	string name;
	cout << "Введіть назву продукту >> ";
	cin >> name;

	int amount = 0;
	for (int i = 0; i < index; i++)
	{
		int count = 0;
		for (int j = 0; j < depart[i].getSize(); j++)
		{
			if (name == depart[i].getNameProd(j))
				count++;
				
		}
		if (count > 0) {
			depart[i].Print();
			amount = count;
		}
	}
	if (amount == 0)
		cout << "Нічого не знайдено!\n";
	system("pause");
}

void factory::searchQuantity() {
	system("cls");
	int amount;
	cout << "Введіть кількість продукції >> ";
	char str[10];

	while (true) {
		cin >> str;
		double n = atof(str);
		if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
			cout << "Ви ввели некоректне значення кількості!\n";
		}
		else break;
		cout << "Повторіть ввод:\n";
		cout << "Кількість продукції >> ";
	}

	amount = atoi(str);

	int count = 0;
	int maxCount = count;
	for (int i = 0; i < index; i++)
	{
		count = 0;
		for (int j = 0; j < depart[i].getSize(); j++)
		{
			if (depart[i].getQuantityDay(j) >= amount)
				count++;
		}
		if (count > 0) {
			depart[i].Print();
			maxCount = count;
		}
	}
	if (maxCount == 0)
		cout << "Нічого не знайдено!\n";

	system("pause");
}

factory::~factory() {
	delete[] depart;
}

