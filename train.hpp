//
//  train.hpp
//  tp2
//
//  Created by Алина Кузнецова on 04.12.2021.
//

#ifndef train_hpp
#define train_hpp
#include <iostream>
#include <string>

using namespace std;

class Train {
private:
    string nameWay;
    string number;
    string time;
public:
    Train();
    Train(string _name, string _number, string _time);
    Train (Train &obj);
    ~Train();
    bool numbersInStr(string str);
    bool charInNumbers(string str);
    void setNameWay(string _nameWay);
    void setNumber(string _number);
    void setTime(string _time);
    string getNameWay();
    string getNumber();
    string getTime();
    
    void setInfoObject();
    void editInfoObject(int index);
    friend istream& operator>>(istream& stream, Train* obj);
    friend ostream& operator<<(ostream& stream, Train* obj);
};

#endif /* train_hpp */
