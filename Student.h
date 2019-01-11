//
// Created by An Nguyễn on 2018-12-23.
//

#ifndef BAITAP03_STUDENT_H
#define BAITAP03_STUDENT_H
#include "Person.h"
#include <iomanip>
//#include "LopSinhHoat.h"

//class LopSinhHoat;

class Student: public Person {
private:
    string      mssv;
    double      diemTB;
    //LopSinhHoat lopSinhHoat;
public:
    Student();
    Student(string, int, string, bool, string, double);
    Student(Student&);
    string getLastName();
    double getDiemTB();
    friend ostream& operator << (ostream&, Student&);
    friend istream& operator >> (istream&, Student&);
    ~Student();
};


#endif //BAITAP03_STUDENT_H
