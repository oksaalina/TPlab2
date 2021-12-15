//
//  train.cpp
//  tp2
//
//  Created by Алина Кузнецова on 04.12.2021.
//

#include "train.hpp"

Train::Train() {
    nameWay = "Не найдено";
    number = "Не найден";
    time = "Не найдено";
    cout << "[Был запущен конструктор Train]" << endl;
    cout << endl;
}

Train::Train(string _name, string _number, string _time) {
    nameWay = _name;
    number = _number;
    time = _time;
    cout << "[Был запущен конструктор Train (с параметром)]" << endl;
    cout << endl;
}

Train::Train(Train &obj) {
    nameWay = obj.nameWay;
    number = obj.number;
    time = obj.time;
    cout << "[Был запущен конструктор копирования Train]" << endl;
    cout << endl;
}

Train::~Train() {
    nameWay = "";
    number = "";
    time = "";
    cout << "[Был запущен деструктор Train]" << endl;
    cout << endl;
}

void Train::setNameWay(string _nameWay) {
    nameWay = _nameWay;
}

void Train::setNumber(string _number) {
    number = _number;
}

void Train::setTime(string _time) {
    time = _time;
}

string Train::getNameWay() {
    return nameWay;
}

string Train::getNumber() {
    return number;
}

string Train::getTime() {
    return time;
}

istream& operator>>(istream& stream, Train* obj) {
    string str;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "1. Пункт назначения: ";
    getline(cin, str);
    if (!obj->numbersInStr(str)) {
            obj->nameWay = str;
        } else {
            cout << "Ошибка! Вы ввели число, попробуйте еще раз" << endl;
        }
    
    cout << "2. Номер поезда: ";
    getline(cin, str);
    if (obj->charInNumbers(str)) {
            obj->number = str;
        } else {
            cout << "Ошибка! Вы ввели букву, попробуйте еще раз" << endl;
        }
    cout << "3. Время отправления: ";
    getline(cin, str);
    if (obj->charInNumbers(str)) {
            obj->time = str;
        } else {
            cout << "Ошибка! Вы ввели букву, попробуйте еще раз" << endl;
        }
    return stream;
}

ostream& operator<<(ostream& stream, Train* obj) {
    stream << "1. Пункт назначения: " << obj->nameWay << endl;
    stream << "2. Номер поезда: " << obj->number << endl;
    stream << "3. Время отправления: " << obj->time << endl;
    return stream;
}

void Train::editInfoObject(int index) {
    string str;
    cout << "Что именно вы хотите изменить? (1-3) >>>";
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(index){
        case 1:
            cout << "Введите новое наименование пункта назначения >>>" << endl;
            getline(cin, str);
            if (!numbersInStr(str)) {
            nameWay = str;
            } else {
                cout << "Ошибка! Вы ввели число, попробуйте еще раз" << endl;
            }
            break;
        case 2:
            cout << "Введите новый номер поезда >>>" << endl;
            getline(cin, str);
            if (charInNumbers(str)) {
                number = str;
            } else {
                cout << "Ошибка! Вы ввели букву, попробуйте еще раз" << endl;
            }
            break;
        case 3:
            cout << "Введите новое время отправления(xx:xx) >>>" << endl;
            getline(cin, str);
            if (charInNumbers(str)) {
                time = str;
            } else {
                cout << "Ошибка! Вы ввели букву, попробуйте еще раз" << endl;
            }
            break;
        default:
            cout << "Ошибка!" << endl;
            cout << endl;
            break;
    }
}

bool Train::charInNumbers(string str) {
    return str.find_first_not_of("0123456789:") == string::npos;
}

bool Train::numbersInStr(string str) {
    int i = 0;
    int found = 0;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            found++;
            return true;
        }
        i++;
    }
    if (found == 0) {
        return false;
    }
    return 0; //??
}
