#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include "product.h"

using namespace std;

class factory
{
    int index, size;
    product* depart;
public:
    factory(); 
    void add(product data); //додавання нового цеху до списку
    void input(); //введення інформації з клавіатури
    void show(); //виведення на консоль даних
    void save(); //збереження до файлу
    void read(); //зчитування з файлу

    bool isempty(istream& fs); //перевірка на пустоту файлу

    int searchDepNum(int num); //пошук цеху за номером
    void delDepNum(); //видалення цеху

    void sort_date(); //сортування по даті
    int datacmp(date d1, date d2); //порівняння дати
    void sort(); //сортування

    void searchDepName(); //пошук цехів за назвою продукта
    void searchQuantity(); //пошук цеху за кількістю продукції

    ~factory();
};

