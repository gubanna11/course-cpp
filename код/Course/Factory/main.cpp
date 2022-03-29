#include <iostream>
#include "windows.h"
#include <fstream>
#include "product.h"
#include "factory.h"
#include <conio.h>

using namespace std;

void Menu() {
    system("cls");
    cout << " 1. Введення інформації про новий цех" << endl;
    cout << " 2. Зберегти введену інформацію" << endl;
    cout << " 3. Зчитати інформацію з файлу" << endl;
    cout << " 4. Вивести на екран інформацію про наявні цехи" << endl;
    cout << " 5. Видалити цех" << endl;
    cout << " 6. Знайти бажані цехи за назвою продукту" << endl;
    cout << " 7. Знайти бажані цехи, кількість продукції яких перевищує задане число" << endl;
    cout << " 8. Сортування" << endl;
    cout << " 9. Вихід з програми (Esc)" << endl << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool exit = false;

    const int amountMenuItems = 9;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD menuItem;
    int activeMenuItem = 0;
    menuItem.X = 0;

    int ch = 0;

    factory products;

    fstream fs;

    while (!exit) {
        Menu();

        menuItem.Y = activeMenuItem;

        SetConsoleCursorPosition(hCon, menuItem);

        ch = _getch();
        if (ch == 224)
            ch = _getch();

        switch (ch) {
        case 27: { //escape
            system("cls");
            exit = true;
            break;
        }
        case 72: //вверх
        {
            activeMenuItem--;
            break;
        }
        case 80: { //вниз
            activeMenuItem++;
            break;
        }
        case 13: {//enter
            {
                if (activeMenuItem == 0) {
                    products.input();
                }
                else  if (activeMenuItem == 1) {
                    products.save();
                }
                else  if (activeMenuItem == 2) {
                    products.read();
                }
                else  if (activeMenuItem == 3) {
                    products.show();
                }
                else  if (activeMenuItem == 4) {
                    products.delDepNum();
                }
                else  if (activeMenuItem == 5) {
                    products.searchDepName();
                }
                else  if (activeMenuItem == 6) {
                    products.searchQuantity();
                }
                else if (activeMenuItem == 7) {
                    products.sort();
                    products.show();
                }
                else  if (activeMenuItem == 8) {
                    exit = true;
                }
                break;
            }
        }
        }
        if (activeMenuItem < 0)
            activeMenuItem = amountMenuItems - 1;
        if (activeMenuItem > amountMenuItems - 1)
            activeMenuItem = 0;
    }

    system("cls");
    cout << "Кінець програми!\n";
    system("pause");

    return 0;
}
