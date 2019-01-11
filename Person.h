//
// Created by An Nguyễn on 2018-12-23.
//

#ifndef BAITAP03_PERSON_H
#define BAITAP03_PERSON_H


#include <string>
#include <iostream>

using namespace std;

class Person {
private:
    string name;
    int    age;
    string address;
    bool   sex;            //true - nam , false - nu
public:
    Person();
    Person(string, int, string, bool);
    Person(const Person&);
    string getName();
    int getAge();
    string getAddress();
    bool getGioiTinh();
    void setName(string);
    void setAge(int);
    void setAddress(string);
    void setGioiTinh(bool);
//    friend ostream& operator << (ostream&, Person&);
//    friend istream& operator >> (istream&, Person&);
    ~Person();
};


#endif //BAITAP03_PERSON_H
