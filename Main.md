#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "CLI.h"
#include "Export.h"
#include "Import.h"

using namespace std;

struct Data {
    string lastname;
    string firstname;
    string patronymic_name;
    string phone;
    string group;
};

void AddName(map<string, Data> &phoneBook) {
    Data data;
    string lastName, firstName, patronymic_Name, Phone, Group;
    cout << "Введите фамилию \n";
    cin >> lastName;
    data.lastname = data.lastname;
    cout << "Введите имя \n";
    cin >> firstName;
    data.firstname = firstName;
    cout << "Введите отчество \n";
    cin >> patronymic_Name;
    data.patronymic_name = patronymic_Name;
    cout << "Введите номер телефона \n";
    cin >> Phone;
    data.phone = Phone;
    cout << "Введите номер группы \n";
    cin >> Group;
    data.group = Group;
    phoneBook.insert(make_pair(lastName, data));
}

void InputPhoneBook(map<string, string> &phoneBook) {
    string tel, name;
    cout << "Enter phone's number:\n";
    cin >> tel;
    cout << "Enter name \n";
    cin >> name;
    phoneBook.insert(pair<string, string>(tel, name));
}

void ShowPhoneBook(map<string, string> phoneBook) {
    for (pair<string, string> element : phoneBook) {
        cout << element.first << " - " << element.second << endl;
    }
}

void ShowAll(map<string, Data> phoneBook) {
    for (auto data : phoneBook) {
        cout << endl;
        cout << data.first << " "
             << data.second.lastname << " "
             << data.second.firstname << " "
             << data.second.patronymic_name << " "
             << data.second.phone << " "
             << data.second.group << endl;
    }
}

void FindPerson(map<string, Data> phoneBook, string key) {
    auto iterator = phoneBook.find(key);
    if (iterator != phoneBook.end()) {
        cout << iterator->second.lastname << " "
             << iterator->second.firstname << " "
             << iterator->second.patronymic_name << " "
             << iterator->second.phone << " "
             << iterator->second.group << endl;
    } else {
        cout << "Не найдено в данном справочнике!" << endl;
    }
}

void ChangePerson(map<string, Data> &phoneBook, string key, int change, string temp) {
    auto iterator = phoneBook.find(key);
    if (change == 1) {
        iterator->second.lastname = temp;
    }
    if (change == 2) {
        iterator->second.firstname = temp;
    }
    if (change == 3) {
        iterator->second.patronymic_name = temp;
    }
    if (change == 4) {
        iterator->second.phone = temp;
    }
    if (change == 5) {
        iterator->second.group = temp;
    }
    FindPerson(phoneBook, key);
}


void DeletePerson(map<string, Data> &phoneBook, string key) {
    phoneBook.erase(key);
}


int main() {
    system("chcp 65001");

    map<string, Data> phoneBook;

    Welcome();
    ShowMenu();
    string key;
    string temp;
    int change;
    char menu;
    cin >> menu;
    switch (menu) {
        case '1': {
            int fl;
            do {
                AddName(phoneBook);
                cout << "Добавить еще людей в список? (1 - да, 0 - нет)\n";
                cin >> fl;
            } while (fl != 0);
        }
        case '2': {
            FindPerson(phoneBook, key);
            return main();
        }
        case '3': {
            ShowAll(phoneBook);
            return main();
        }
        case '4': {
            ChangePerson(phoneBook, key, change, temp);
            return main();
        }
        case '5': {
            DeletePerson(phoneBook, key);
            return main();
        }
        case '6': {
            ExportToFile(phoneBook);
            break;
        }
        case '7': {
            ImportFromFile(phoneBook);
            break;
        }
    }

}
