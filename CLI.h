#include <iostream>
#include <vector>
#include <map>

#pragma once

using namespace std;

void Welcome() {
    cout << "===============================\n";
    cout << "=====Телефонный справочник=====\n";
    cout << "===============================\n";
}

void ShowMenu() {
    cout << "Пункты меню:\n";
    cout << "1. Добавить номер\n";
    cout << "2. Поиск номера\n";
    cout << "3. Показать весь справочник\n";
    cout << "4. Изменить данные\n";
    cout << "5. Удалить данные\n";
    cout << "6. Экспрорт в файл\n";
    cout << "7. Импорт из файла\n";
    cout << "\n";
    cout << "0. Выход\n";
    cout << "===============================\n";

}
