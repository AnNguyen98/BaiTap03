//
// Created by An Nguyễn on 2018-12-23.
//

#ifndef BAITAP03_LECTURER_H
#define BAITAP03_LECTURER_H
#include "Person.h"

class Lecturer: public Person {
private:
    string maLecturer;
    string capBac;

public:
    Lecturer();
    Lecturer(string, int, string, bool, string, string);
    Lecturer(Lecturer& );
    friend ostream& operator << (ostream&, Lecturer&);
    friend istream& operator >> (istream&, Lecturer&);
    virtual ~Lecturer();
};

#endif //BAITAP03_LECTURER_H
