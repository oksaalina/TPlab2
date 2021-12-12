//
//  keeper.hpp
//  tp2
//
//  Created by Алина Кузнецова on 04.12.2021.
//

#ifndef keeper_hpp
#define keeper_hpp
#include "element.hpp"
#include <iostream>
#include <stdlib.h>

class Keeper {
private:
    Element *head;
    int _size;
public:
    Keeper();
    ~Keeper();
    int getSize();
    void pushObj(Train* obj);
    void popObj(int index);
    void addObjPos(Train* obj, int index);
    void getByNumber(int num);
    void sortByNum();
    Train* operator[](int index);
};

#endif /* keeper_hpp */
