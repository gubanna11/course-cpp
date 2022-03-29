#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>

using namespace std;

//структура, яка зберігає дату
struct date {
    int day;
    int month;
    int year;

    friend istream& operator >>(istream& in, date& d);
    friend ostream& operator <<(ostream& out, const date& d);    
};

class product {
private:
    int departmentNumber; //номер цеху
    string* productName; //масив з видами продукцій
    int* quantityDay; //масив, який зберігає кількість кожної з продукції, виготовленої за день
    int size; //розмір масиву (кількості днів, продукції)
    date data; //дата
public:
    //прототипи
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

