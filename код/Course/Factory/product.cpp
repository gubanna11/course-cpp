#include "product.h"
#include "factory.h"

//конструктор за замовчуванням
product::product() {}

//конструктор з параметрами
product::product(int departmentNumber, int size) {
    set_departmentNumber(departmentNumber);
    set_sizeProduct(size);
}

//встановити номер цеху
void product::set_departmentNumber(int departmentNumber) {
    this->departmentNumber = departmentNumber;
}

//встановити розмір масиву
void product::set_sizeProduct(int size) {
    this->productName = new string[size];
    this->quantityDay = new int[size];
    this->size = size;
}


//інформація про продукт (кількість видів, кіль-ть за добу
void product::set_product(int size) {
    for (int i = 0; i < size; i++)
    {
        char str[10];

        cout << "Введіть назву виробу №"<< i + 1 << " >> ";
        cin >> productName[i];

        cout << "Кількість, виготовлена за добу >> ";
        while (true) {
            cin >> str;
            double n = atof(str);
            if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
                cout << "Ви ввели некоректне значення кількості!\n";
            }
            else break;
            cout << "Повторіть ввод:\n";
            cout << "Кількість, виготовлена за добу >> ";
        }
        quantityDay[i] = atoi(str);
    }
}

//встановити дату
void product::set_date(int day, int month, int year) {
    this->data.day = day;
    this->data.month = month;
    this->data.year = year;
}

//отримати номер цеху
int product::get_departmentNumber() {
    return departmentNumber;
}

int product::getSize() {
    return size;
}

date product::getDate() {
    return this->data;
}

//перевірка на валідність дати
void product::data_print(date& d) {

    if (d.day < 10)
        cout << "0" << d.day << ".";
    else cout << d.day << ".";

    if (d.month < 10)
        cout << "0" << d.month << ".";
    else cout << d.month << ".";

    cout << d.year;

}

//вивести на екран дані
void product::Print() {
    cout << "Номер цеха: " << departmentNumber;
    cout << left << setw(15) << "\nПродукція " << "Виготовлено за добу\n";
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(14) << productName[i] << quantityDay[i] << endl;
    }

    cout << "\nДата: ";
    data_print(data);
    cout << endl << endl << "---------------------------------\n" << endl;
}

istream& operator>>(istream& in, date& d) {
    in >> d.day >> d.month >> d.year;
    return in;
}

ostream& operator <<(ostream& out, const date& d) {
    if (d.day < 10)
        out << "0" << d.day << " ";
    else out << d.day << " ";

    if (d.month < 10)
        out << "0" << d.month << " ";
    else out << d.month << " ";

    out << d.year;

    return out;
}

ostream& operator <<(ostream& out, const product& p) {
    out << p.departmentNumber << " " << p.size << " ";
    for (int i = 0; i < p.size; i++)
    {
        out << p.productName[i] << " " << p.quantityDay[i] << " ";
    }
    out << p.data;
    return out;
}

istream& operator>>(istream& in, product& p) {
    in >> p.departmentNumber >> p.size;
    p.set_sizeProduct(p.size);
    for (int i = 0; i < p.size; i++)
    {
        in >> p.productName[i] >> p.quantityDay[i];
    }
    in >> p.data;
    return in;
}


string product::getNameProd(int i) {
    return productName[i];
}

int product::getQuantityDay(int i) {
    return quantityDay[i];
}

void setDepart(product& p) {
    cout << "Номер цеха >> ";

    char str[10];
    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
            cout << "Ви ввели некоректне значення номера!\n";
        }
        else break;
        cout << "Повторіть ввод:\n";
        cout << "Номер цеха >> ";
    }

    p.departmentNumber = atoi(str);

    cout << "Кіль-ть видів продукції >> ";

    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
            cout << "Ви ввели некоректне значення кількості!\n";
        }
        else break;
        cout << "Повторіть ввод:\n";
        cout << "Кіль-ть видів продукції >> ";
    }
    p.size = atoi(str);

    p = product(p.departmentNumber, p.size);

    p.set_product(p.size);

    cout << "Введіть дату заповнення:\n";
    again:
    cout << "День: ";
    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n) || atoi(str) > 31) {
            cout << "Такого дня не існує!\n";
        }
        else break;
        cout << "Повторіть ввод:\n";
        cout << "День: ";
    }

    p.data.day = atoi(str);

    cout << "Місяць: ";
    while (true) {
        cin >> str;
        double n = atof(str);
        if (p.data.day >= 30 && atoi(str) == 2) {
            cout << "Такого дня у лютому немає!\n";
            goto again;
        }
        else if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n) || atoi(str) > 12) {
            cout << "Такого місяця не існує!\n";
        }
        else break;
        cout << "Повторіть ввод:\n";
        cout << "Місяць: ";
    }
    p.data.month = atoi(str);

    cout << "Рік: ";
    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n) || (atoi(str) >= 100 && atoi(str) <= 1900 || (atoi(str) >= 2022) )) {
            cout << "Некоректне значення року!\n";
        }
        else break;
        cout << "Повторіть ввод:\n";
        cout << "Рік: ";
    }
    p.data.year = atoi(str);

    if (p.data.year >= 0 && p.data.year <= 21)
        p.data.year += 2000;
    else if (p.data.year > 21 && p.data.year <= 99)
        p.data.year += 1900;

    p.set_date(p.data.day, p.data.month, p.data.year);
}

void product::sortName(product& p) {
    int i, j;

    string pN; int qD;

    for (i = 1; i < p.size; i++) {
        pN = p.productName[i];
        qD = p.quantityDay[i];

        for (j = i - 1; j >= 0 && p.productName[j] > pN; j--) {
            p.productName[j + 1] = p.productName[j];
            p.quantityDay[j + 1] = p.quantityDay[j];
        }

        p.productName[j + 1] = pN;
        p.quantityDay[j + 1] = qD;
    }
}

//деструктор
product::~product() {
}