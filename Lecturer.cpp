//
// Created by An Nguyễn on 2018-12-23.
//

#include "Lecturer.h"

Lecturer::Lecturer() {
    this->setAge(0);
    this->setAddress("none");
    this->setGioiTinh(1);
    this->setName("none");
    this->maLecturer = "none";
    this->capBac     = "none";
}

Lecturer::Lecturer(string name, int age, string address, bool sex, string maLecturer, string capBac):Person(name,age,address,sex){
    this->maLecturer = maLecturer;
    this->capBac     = capBac;
}

Lecturer::Lecturer(Lecturer& lecturer) {
    this->setName(lecturer.getName());
    this->setAge(lecturer.getAge());
    this->setAddress(lecturer.getAddress());
    this->setGioiTinh(lecturer.getGioiTinh());
    this->maLecturer = lecturer.maLecturer;
    this->capBac     = lecturer.capBac;
}
ostream& operator << (ostream& out,Lecturer& lecturer){
    cout << "\nTen        : " << lecturer.getName() << endl;
    cout << "Tuoi       : " << lecturer.getAge() << endl;
    cout << "Dia chi    : " << lecturer.getAddress() << endl;
    string gt = lecturer.getGioiTinh() ? "Nam" : "Nu";
    cout << "Gioi tinh  : " << gt << endl;
    cout << "Ma lacturer: " << lecturer.maLecturer << endl;
    cout << "Cap bac    : " << lecturer.capBac << endl;
    return out;
}
istream& operator >> (istream& in, Lecturer& lecturer){
    string name,address;
    int age;
    bool gioiTinh;
    in.ignore();
    cout << "\nNhap vao ten : ";
    getline(in, name);
    lecturer.setName(name);
    cout << "Nhap vao dia chi : ";
    getline(in, address);
    lecturer.setAddress(address);
    cout << "Nhap tuoi : ";
    in >> age;
    lecturer.setAge(age);
    cout << "Nhap vao gioi tinh : ";
    in >> gioiTinh;
    lecturer.setGioiTinh(gioiTinh);

    //Lê Thị Mỹ Hạnh: “102ltmhanh”
    string maLecturer = "102";
    maLecturer += tolower(name[0]);
    int soSpaceEnd = 0;
    for(int i=1; i<name.size()-1; i++){
        if(name[i] == ' ') soSpaceEnd = i;
    }
    if(soSpaceEnd == 0){
        maLecturer = maLecturer + name;
    } else{
        for(int i=0; i < name.size(); i++){
            if(name[i] == ' ' && i < soSpaceEnd) maLecturer += tolower(name[i+1]);
            if(i >= soSpaceEnd && name[i] != ' ') maLecturer += name[i];
        }
    }
    lecturer.maLecturer = maLecturer;

    cout << "Chon cap bac Lecturer ( 1 : assistant professor, 2 : associate professor, 3 : full professor): ";
    int index;
    in >> index;
    if(index == 1) lecturer.capBac = "Assistant professor";
    if(index == 2) lecturer.capBac = "Associate professor";
    if(index == 3) lecturer.capBac = "Full professor";
    return in;
}
Lecturer::~Lecturer() {

}
