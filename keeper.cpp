//
//  keeper.cpp
//  tp2
//
//  Created by Алина Кузнецова on 04.12.2021.
//

#include "keeper.hpp"

using namespace std;

Keeper::Keeper() {
    _size = 0;
    head = nullptr;
    cout << "[Был запущен конструктор Keeper]" << endl;
    cout << endl;
}

Keeper::~Keeper() {
    Element* ptr = head;
    if (head != nullptr) {   
        while (ptr->nextElement != nullptr) {
            ptr = head;
            head = head->nextElement;
            ptr->data->~Train();
            delete(ptr);
            }
        } else {
        head->data->~Train();
        delete(head);
        }
    cout << "[Был запущен деструктор Keeper]" << endl;
    cout << endl;
}

void Keeper::pushObj(Train *obj) {
    Element* newObj = new Element;
    if (_size == 0) {
        newObj->data = obj;
        newObj->nextElement = nullptr;
        _size++;
        head = newObj;
    } else {
        Element* ptr = head;
        while(ptr->nextElement !=nullptr) {
          ptr =  ptr->nextElement;
        }
        newObj->data = obj;
        newObj->nextElement = nullptr;
        _size++;
        ptr->nextElement = newObj;
    }
}

void Keeper::popObj(int index) {
    if (head == nullptr) {
        cout << "пусто" << endl;
        
    } else {
        if (head->nextElement == nullptr){
            head->data->~Train();
            head = nullptr;
            _size--;
        } else {
            Element* ptr = head;
            if (index == 0) {
                head = ptr->nextElement;
                ptr->data->~Train();
                delete ptr;
            } else {
                Element* nextPtr;
                for (int i = 0; i < (index - 1); i++) {
                    ptr = ptr -> nextElement;
                }
                nextPtr = ptr->nextElement;
                ptr->nextElement = nextPtr->nextElement;
                nextPtr->data->~Train();
                delete nextPtr;
            }
            _size--;
        }
    }
    cout << "Объект был успешно удален" << endl;
}

int Keeper::getSize() {
    return _size;
}

Train* Keeper::operator[](int index) {
    Element* ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->nextElement;
    }
    return ptr->data;
}

void Keeper::sortByNum() {
    if (head == nullptr) {
        cout << "Пусто!" << endl;
        cout << endl;
    } else {
        if (head->nextElement == nullptr) {
            //cout << "Готово!" << endl;
            cout << endl;
        } else {
            Element* ptr;
            Element* tmp = new Element;
            bool swapped = true;
            while (swapped) {
                swapped = false;
                ptr = head;
                while (ptr->nextElement != nullptr) {
                    if (strcmp(ptr->data->getNumber().c_str(), ptr->nextElement->data->getNumber().c_str()) > 0) {
                            swapped = true;
                            tmp->data = ptr->data;
                            ptr->data = ptr->nextElement->data;
                            ptr->nextElement->data = tmp->data;
                         }
                    ptr = ptr->nextElement;
              }
            }
         }
      }
  cout << "Готово!" << endl;
}

void Keeper::addObjPos(Train* obj, int index) {
    Element* ptr = head;
    Element* nextPtr;
    Element* newObj = new Element;
    if (_size == 0) {
        cout << "Пусто!" << endl;
        cout << endl;
    } else {
        if (head->nextElement == nullptr) {
            pushObj(obj);
        }
        if (index == 0) {
            newObj->data = obj;
            newObj->nextElement = ptr;
            head = newObj;
            _size++;
        } else {
            for (int i = 0; i < (index - 1); i++) {
                ptr = ptr->nextElement;
            }
            nextPtr = ptr->nextElement;
            newObj->data = obj;
            newObj->nextElement = nextPtr;
            ptr->nextElement = newObj;
            _size++;
        }
    }
}

void Keeper::getByNumber(int num) {
    Element* ptr = head;
    bool detect = false;
    int numberCheck = 0;
    cout<< "Найденные поезда:" << endl;
    if (head->nextElement == nullptr) {
        numberCheck = atoi(ptr->data->getNumber().c_str());
        if (numberCheck == num) {
            detect = true;
            cout << ptr->data << endl;
        }
    } else {
        while (ptr != nullptr) {
            numberCheck = atoi(ptr->data->getNumber().c_str());
            if (numberCheck == num) {
                detect = true;
                cout << ptr->data << endl;
            }
            ptr = ptr->nextElement;
        }
    }
    if (!detect) {
        cout << "Совпадений не обнаружено" << endl;
    }
}
