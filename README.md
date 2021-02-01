#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "CLI.h"

using namespace std;

struct Data {
    string lastname;
    string firstname;
    string patronymic_name;
    string phone;
    string group;
};

void AddName (map<string, Data> & phoneBook)
{
    Data data;
    string lastName, firstName, patronymic_Name, Phone, Group ;
    cout<<"Введите фамилию \n";
    cin >>lastName;
    data.lastname = data.lastname;
    cout<<"Введите имя \n";
    cin >>firstName;
    data.firstname = firstName;
    cout<<"Введите отчество \n";
    cin >> patronymic_Name;
    data.patronymic_name = patronymic_Name;
    cout<<"Введите номер телефона \n";
    cin >> Phone;
    data.phone = Phone;
    cout<<"Введите номер группы \n";
    cin >> Group;
    data.group = Group;
    phoneBook.insert(make_pair(lastName, data));
}

void InputPhoneBook (map<string, string >&phoneBook)
{
    string tel, name;
    cout << "Enter phone's number:\n";
    cin >> tel;
    cout<<"Enter name \n";
    cin >> name;
    phoneBook.insert(pair<string,string>(tel,name));
}

void ShowPhoneBook (map<string,string> phoneBook)
{
    for (pair<string, string > element : phoneBook){
        cout<<element.first << " - " << element.second<<endl;
    }
}
void ShowAll(map<string, Data> phoneBook) {
        for (auto data : phoneBook) {
        cout << endl;
        cout << data.first  << " "
             << data.second.lastname << " "
             << data.second.firstname << " "
             << data.second.patronymic_name << " "
             << data.second.phone << " "
             << data.second.group << endl;
    }
}

void FindPerson(map<string, Data> phoneBook, string key) {
    auto data = phoneBook.find(key);
    if (data != phoneBook.end()) {
        cout << data->second.lastname << " "
             << data->second.firstname << " "
             << data->second.phone << " "
             << data->second.group << endl;
    }
    else {
        cout << "Не найдено" << endl;
    }

}

void ChangePerson(map<string, Data> phoneBook) {
    string key;
    key = FindPerson(phoneBook);
    auto data = phoneBook.find(key);
    cout << "Что вы хотите изменить?" << endl;
    cout << "1 - Фамилия" << endl;
    cout << "2 - Имя" << endl;
    cout << "3 - Отчество" << endl;
    cout << "4 - Номер телефона" << endl;
    cout << "5 - Группу" << endl;

    string temp;
    bool tempBool;
    int change;
    cin >> change;
    switch (change) {
        case 1:
            cout << "Введите новую фамилию: " << endl;
            cin >> temp;
            data->second.lastname = temp;
            break;
            ​
        case 2:
            cout << "Введите новое имя: " << endl;
            cin >> temp;
            data->second.firstname = temp;
            break;
        case 3:
            cout << "Введите новое отчество: " << endl;
            cin >> temp;
            data->second.firstname = temp;
            break;

        case 4:
            cout << "Введите новый номер телефона: " << endl;
            cin >> temp;
            data->second.phone = temp;
            break;

        case 5:
            cout << "Введите новый номер группы: " << endl;
            cin >> temp;
            data->second.group = temp;
            break;
    }


    void DeleteSomebody(map<string, Data> phoneBook) {
        string key;
        key = FindSomebody(phoneBook);
        auto iterator = phoneBook.find(key);

    }

int main() {
    system("chcp 65001");

    map<string, Data> phoneBook;

    Welcome();
    ShowMenu();
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
            FindPerson(phoneBook);
            return main();
        }
        case '3': {
            ShowAll(phoneBook);
            return main();
        }
        case '4': {
            ChangePerson(phoneBook);
            return main();

        }
        case '4': {
            DeleteSomebody(phoneBook);
            return main();
        }
    }
}
