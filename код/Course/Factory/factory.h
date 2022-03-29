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
    void add(product data); //��������� ������ ���� �� ������
    void input(); //�������� ���������� � ���������
    void show(); //��������� �� ������� �����
    void save(); //���������� �� �����
    void read(); //���������� � �����

    bool isempty(istream& fs); //�������� �� ������� �����

    int searchDepNum(int num); //����� ���� �� �������
    void delDepNum(); //��������� ����

    void sort_date(); //���������� �� ���
    int datacmp(date d1, date d2); //��������� ����
    void sort(); //����������

    void searchDepName(); //����� ����� �� ������ ��������
    void searchQuantity(); //����� ���� �� ������� ���������

    ~factory();
};

