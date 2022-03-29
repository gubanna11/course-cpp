#include "product.h"
#include "factory.h"

//����������� �� �������������
product::product() {}

//����������� � �����������
product::product(int departmentNumber, int size) {
    set_departmentNumber(departmentNumber);
    set_sizeProduct(size);
}

//���������� ����� ����
void product::set_departmentNumber(int departmentNumber) {
    this->departmentNumber = departmentNumber;
}

//���������� ����� ������
void product::set_sizeProduct(int size) {
    this->productName = new string[size];
    this->quantityDay = new int[size];
    this->size = size;
}


//���������� ��� ������� (������� ����, ���-�� �� ����
void product::set_product(int size) {
    for (int i = 0; i < size; i++)
    {
        char str[10];

        cout << "������ ����� ������ �"<< i + 1 << " >> ";
        cin >> productName[i];

        cout << "ʳ������, ����������� �� ���� >> ";
        while (true) {
            cin >> str;
            double n = atof(str);
            if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
                cout << "�� ����� ���������� �������� �������!\n";
            }
            else break;
            cout << "�������� ����:\n";
            cout << "ʳ������, ����������� �� ���� >> ";
        }
        quantityDay[i] = atoi(str);
    }
}

//���������� ����
void product::set_date(int day, int month, int year) {
    this->data.day = day;
    this->data.month = month;
    this->data.year = year;
}

//�������� ����� ����
int product::get_departmentNumber() {
    return departmentNumber;
}

int product::getSize() {
    return size;
}

date product::getDate() {
    return this->data;
}

//�������� �� �������� ����
void product::data_print(date& d) {

    if (d.day < 10)
        cout << "0" << d.day << ".";
    else cout << d.day << ".";

    if (d.month < 10)
        cout << "0" << d.month << ".";
    else cout << d.month << ".";

    cout << d.year;

}

//������� �� ����� ���
void product::Print() {
    cout << "����� ����: " << departmentNumber;
    cout << left << setw(15) << "\n��������� " << "����������� �� ����\n";
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(14) << productName[i] << quantityDay[i] << endl;
    }

    cout << "\n����: ";
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
    cout << "����� ���� >> ";

    char str[10];
    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
            cout << "�� ����� ���������� �������� ������!\n";
        }
        else break;
        cout << "�������� ����:\n";
        cout << "����� ���� >> ";
    }

    p.departmentNumber = atoi(str);

    cout << "ʳ��-�� ���� ��������� >> ";

    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n)) {
            cout << "�� ����� ���������� �������� �������!\n";
        }
        else break;
        cout << "�������� ����:\n";
        cout << "ʳ��-�� ���� ��������� >> ";
    }
    p.size = atoi(str);

    p = product(p.departmentNumber, p.size);

    p.set_product(p.size);

    cout << "������ ���� ����������:\n";
    again:
    cout << "����: ";
    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n) || atoi(str) > 31) {
            cout << "������ ��� �� ����!\n";
        }
        else break;
        cout << "�������� ����:\n";
        cout << "����: ";
    }

    p.data.day = atoi(str);

    cout << "̳����: ";
    while (true) {
        cin >> str;
        double n = atof(str);
        if (p.data.day >= 30 && atoi(str) == 2) {
            cout << "������ ��� � ������ ����!\n";
            goto again;
        }
        else if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n) || atoi(str) > 12) {
            cout << "������ ����� �� ����!\n";
        }
        else break;
        cout << "�������� ����:\n";
        cout << "̳����: ";
    }
    p.data.month = atoi(str);

    cout << "г�: ";
    while (true) {
        cin >> str;
        double n = atof(str);
        if (atoi(str) == 0 || atoi(str) <= 0 || n != round(n) || (atoi(str) >= 100 && atoi(str) <= 1900 || (atoi(str) >= 2022) )) {
            cout << "���������� �������� ����!\n";
        }
        else break;
        cout << "�������� ����:\n";
        cout << "г�: ";
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

//����������
product::~product() {
}