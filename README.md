# PhoneBook
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

int main() {
    system("chcp 65001");

    map<string, Data> phoneBook;



    Welcome;
    ShowMenu;

        char menu;
        cin >> menu;

        switch (menu) {

            case '1': {
                bool flag = false;
                while (!flag) {
                    AddName(phoneBook);
                    cout << "Добавить еще людей в список? (1 - да, 0 - нет)\n";
                    return main();
                }
                return main();
            }
            case '2': {
                ShowAll(phoneBook);
                return main();
            }
        }

    AddName(phoneBook);
    ShowAll(phoneBook);

    }

