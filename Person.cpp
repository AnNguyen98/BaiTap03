//
// Created by An Nguyễn on 2018-12-23.
//

#include "Person.h"

Person::Person(){
    this->name     = "noneName";
    this->age      = 0;
    this->address  = "noneAddress";
    this->sex      = true;
}
Person::Person(string name, int age, string address, bool sex){
    this->name     = name;
    this->age      = age;
    this->address  = address;
    this->sex      = sex;
}
Person::Person(const Person& myPerSon){
    this->name     = myPerSon.name;
    this->age      = myPerSon.age;
    this->address  = myPerSon.address;
    this->sex      = myPerSon.sex;
}

string Person::getName(){
    return this->name;
}
int Person::getAge(){
    return this->age;
}
string Person::getAddress(){
    return this->address;
}
bool Person::getGioiTinh(){
    return this->sex;
}

void Person::setName(string name){
    this->name = name;
}
void Person::setAge(int age){
    this->age = age;
}
void Person::setAddress(string address){
    this->address = address;
}
void Person::setGioiTinh(bool gioiTinh){
    this->sex = gioiTinh;
}

//ostream& operator << (ostream& out,Person& person){
//    cout << "Ten : " << person.name << endl;
//    cout << "Tuoi : " << person.age << endl;
//    cout << "Dia chi : " << person.address << endl;
//    cout << "Gioi tinh : " << person.sex << endl;
//    return out;
//}
//istream& operator >> (istream& in, Person& person){
//    cout << "Nhap vao ten : ";
//    in.ignore();
//    getline(in, person.name);
//    cout << "Nhap tuoi : ";
//    in >> person.age;
//    cout << "Nhap vao dia chi : ";
//    getline(in, person.address);
//    cout << "Gioi tinh : ";
//    in >> person.sex;
//    return in;
//}
Person::~Person(){

}
