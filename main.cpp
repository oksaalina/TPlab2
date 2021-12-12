//
//  main.cpp
//  tp2
//
//  Created by Алина Кузнецова on 04.12.2021.
//

#include <iostream>
#include "keeper.hpp"
#include "train.hpp"

int main() {
    int index;
    int choose;
    bool exit = false;
    Keeper keeper;
    Train* train;
    while (!exit) {
        cout << "Основное меню:" << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Добавить объект на определенную позицию" << endl;
        cout << "3. Редактировать объект" << endl;
        cout << "4. Удалить объект" << endl;
        cout << "5. Вывести весь список на экран" << endl;
        cout << "6. Вывести объект по его номеру" << endl;
        cout << "7. Отсортировать по номерам поездов" << endl;
        cout << "0. Выход" << endl;
        cout << endl;
        cout << "Ваш выбор >>> ";
        if (cin >> choose) {
        cout << endl;
        switch (choose) {
            case 1:
                train = new Train;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> train;
                keeper.pushObj(train);
                keeper.sortByNum();
                break;
            case 2:
                for (int i = 0; i < keeper.getSize(); i++) {
                    cout << endl;
                    cout << "Объект № " << i << endl;
                    cout << keeper[i];
                }
                cout << endl;
                cout << "Введите позицию объекта >>>";
                if (cin >> index) {
                    if (index < 0 || index > (keeper.getSize() - 1)) {
                        cout << "Ошибка" << endl;
                        cout << endl;
                    } else {
                        train = new Train;
                        cin >> train;
                        keeper.addObjPos(train, index);
                        cout << endl;
                    }
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << endl;
                    cout << "Ошибка ввода!" << endl;
                    cout << endl;
                }
                break;
            case 3:
                if (keeper.getSize() == 0) {
                    cout << "Пусто! Сначала добавьте объект" << endl;
                    cout<< endl;
                } else {
                    for (int i = 0; i < keeper.getSize(); i++) {
                        cout << "Объект № " << i << endl;
                        cout << keeper[i] << endl;
                    }
                    cout << "Введите номер объекта для изменения данных" << "(0-" << (keeper.getSize() - 1) << ") >>";
                    if (cin >> index) {
                        if (index < 0 || index > (keeper.getSize() - 1)) {
                            cout << "Ошибка" << endl;
                            cout << endl;
                        } else {
                            cout << keeper[index] << endl;
                            keeper[index]->editInfoObject(index);
                        }
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl;
                        cout << "Ошибка ввода!" << endl;
                        cout << endl;
                    }
                }
                break;
            case 4:
                if (keeper.getSize() == 0) {
                    cout << "Пусто! Сначала добавьте объект" << endl;
                    cout<< endl;
                } else {
                    for (int i = 0; i < keeper.getSize(); i++) {
                        cout << "Объект № " << i << endl;
                        cout << keeper[i] << endl;
                    }
                    cout << "Введите номер >>>";
                    if (cin >> index) {
                        if (index < 0 || index > (keeper.getSize() - 1)) {
                            cout << "Ошибка!" << endl;
                            cout << endl;
                        } else {
                            keeper.popObj(index);
                    }
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl;
                        cout << "Ошибка ввода!" << endl;
                        cout << endl;
                    }
                }
                break;
            case 5:
                if (keeper.getSize() == 0) {
                    cout << "Пусто! Сначала добавьте объект" << endl;
                    cout<< endl;
                } else {
                    for (int i = 0; i < keeper.getSize(); i++ ) {
                        cout << keeper[i] << endl;
                    }
                }
                break;
            case 6:
                if (keeper.getSize() == 0) {
                    cout << "Пусто! Сначала добавьте объект" << endl;
                    cout<< endl;
                } else {
                    int num;
                    //cout << endl;
                    cout << "Введите номер поезда >>> ";
                    if (cin >> num) {
                        cout << endl;
                        keeper.getByNumber(num);
                    } else {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << endl;
                        cout << "Ошибка ввода!" << endl;
                        cout << endl;
                    }
                }
                break;
            case 7:
                keeper.sortByNum();
                break;
            case 0:
                exit = true;
                break;
            default:
                break;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            cout << "Ошибка ввода!" << endl;
            cout << endl;
        }
      }
    return 0;
}
