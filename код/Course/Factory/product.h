#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>

using namespace std;

//���������, ��� ������ ����
struct date {
    int day;
    int month;
    int year;

    friend istream& operator >>(istream& in, date& d);
    friend ostream& operator <<(ostream& out, const date& d);    
};

class product {
private:
    int departmentNumber; //����� ����
    string* productName; //����� � ������ ���������
    int* quantityDay; //�����, ���� ������ ������� ����� � ���������, ����������� �� ����
    int size; //����� ������ (������� ���, ���������)
    date data; //����
public:
    //���������
    product();

    product(int departmentNumber, int size);

    friend void setDepart(product& p);

    void set_departmentNumber(int departmentNumber);

    void set_sizeProduct(int size);

    void set_product(int size);

    void set_date(int day, int month, int year);

    int get_departmentNumber();

    int getSize();

    string getNameProd(int i);
    int getQuantityDay(int i);

    date getDate();

    void data_print(date& d);

    void Print();
    void sortName(product& p);

    friend ostream& operator <<(ostream& out, const product& p);
    friend ostream& operator <<(ostream& out, const date& d);
    friend istream& operator>>(istream& in, product& p);

    ~product();
};

