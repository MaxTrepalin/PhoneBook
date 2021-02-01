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
    data.lastname = lastName;
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

void ShowAll(map<string, Data> phoneBook) {
    cout << "\n\n\n\t+++ПОЛНЫЙ СПИСОК+++\n\n\n";
    int i = 1;
    for (auto data : phoneBook) {
        cout << "+++HUMAN # " << i << "+++" << endl << endl;
        cout << "First name - " << data.first << endl;
        cout << "Second name - " << data.second.firstname << endl;
        cout << "Second name - " << data.second.patronymic_name << endl;
        cout << "Phone number - " << data.second.phone << endl;
        cout << "Group - " << data.second.group << endl << endl << endl;
        i++;
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
    char menu = '-';
    while (menu !='9') {
        cin >> menu;
        switch (menu) {
            case '1': {
                int fl;
                do {
                    AddName(phoneBook);
                    cout << "Добавить еще людей в список? (1 - да, 0 - нет)\n";
                    cin >> fl;
                } while (fl != 0);
                break;
            }
            case '2': {
                cin>>key;
                FindPerson(phoneBook, key);
                break;
            }
            case '3': {
                ShowAll(phoneBook);
                break;
            }
            case '4': {
                cin>>key;
                ChangePerson(phoneBook, key, change, temp);
                break;
            }
            case '5': {
                cin>>key;
                DeletePerson(phoneBook, key);
                break;
            }
                //    case '6': {
                //      ExportToFile(phoneBook);
                //      break;
                // }
                //     case '7': {
                //       ImportFromFile(phoneBook);
                //      break;
                // }
        }
        return main();
    }
}


