//
// Created by An Nguyễn on 2018-12-23.
//

#include "Student.h"

Student::Student(){
    this->setName("none");
    this->setAge(0);
    this->setAddress("none");
    this->setGioiTinh(true);
    this->mssv = "none";
    this->diemTB = 0.0;
}
Student::Student(string name, int age, string address, bool sex, string mssv, double diemTB):Person(name,age,address,sex){
    this->mssv = mssv;
    this->diemTB = diemTB;
}
Student::Student(Student& student){
    this->setName(student.getName());
    this->setAge(student.getAge());
    this->setAddress(student.getAddress());
    this->setGioiTinh(student.getGioiTinh());
    this->mssv = student.mssv;
    this->diemTB = student.diemTB;
}
double Student::getDiemTB(){
    return this->diemTB;
}
string Student::getLastName(){
    string lastName = "";
    int indexLastName = 0;
    for(int i=0; i < this->getName().size(); i++){
        if(this->getName()[i] == ' ') indexLastName = i +1;
    }
    for(int i=indexLastName; i < this->getName().size(); i++){
        lastName += tolower(this->getName()[i]);
    }
    return lastName;
}
ostream& operator << (ostream& out, Student& student){
    string gt = student.getGioiTinh() ? "Nam" : "Nu";
    cout << setw(5) << " " << student.getName() << setw(25 - student.getName().size());
    cout << student.getAge() << setw(10 + student.getAddress().size());
    cout << student.getAddress() << setw(19 - student.getAddress().size());
    cout << gt << setw(13 + student.mssv.size());
    cout << student.mssv << setw(20 - student.mssv.size());
    cout << student.diemTB << endl;
    return out;
}
istream& operator >> (istream& in, Student& student){
    string name,address;
    int age;
    bool gioiTinh;

    in.ignore();
    cout << "Nhap vao ten : ";
    getline(in, name);
    student.setName(name);
    cout << "Nhap vao dia chi : ";
    getline(in, address);

    bool checkMSSV = false;
    do{
        cout << "Nhap MSSV 10 kí tự (0, ... 9), ký tự đầu tiên không được bắt đầu bằng ký tự “0” :\n";
        getline(in, student.mssv);

        //Nhap va check MSSV thoa man bai toan
        bool check1 = (student.mssv[0] != '0') && (student.mssv.size() == 10);
        bool check2 = false;
        char arrNumber[] = {'1','2','3','4','5','6','7','8','9'};
        for(int i=1; i<student.mssv.size(); i++){
            for(int j=0; j<10; j++){
                if(student.mssv[i] == arrNumber[j]) {check2 = true; break;}
            }
            if(!check2) break;
        }
        checkMSSV = check1 && check2;
        if(!checkMSSV) cout << "Ban can xem lai MSSV.!!"<< endl;
    }while(!checkMSSV);
    student.setAddress(address);
    cout << "Gioi tinh : ";
    in >> gioiTinh;
    student.setGioiTinh(gioiTinh);
    cout << "Nhap tuoi : ";
    in >> age;
    student.setAge(age);
    //Check Diem TB
    do{
        cout << "Nhap diem trung binh (0-4) : ";
        in >> student.diemTB;
        if(student.diemTB < 0 || student.diemTB > 4) cout << "Diem trung binh trong khoang (0-4)!!" << endl;
    }while(student.diemTB < 0 || student.diemTB > 4);


    return in;
}
Student::~Student(){

}


