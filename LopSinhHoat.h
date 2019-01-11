//
// Created by An Nguyễn on 2018-12-23.
//

#ifndef BAITAP03_LOPSINHHOAT_H
#define BAITAP03_LOPSINHHOAT_H
#include "Lecturer.h"
#include "Student.h"


class Student;
class LopSinhHoat {
private:
    int MAX_QUEUE = 100;
    int back;
    int front;
    Lecturer giaoVienChuNhiem;
    Student *arrStudents;
    string tenLopSH;
    int siSoSV;

public:
    LopSinhHoat();
    LopSinhHoat(const LopSinhHoat& lopSH);
    LopSinhHoat(Lecturer, Student *, string, int, int, int);
    void pushBack(Student);
    void popFront();
    Student getFront();
    int sizeQQ();
    bool isEmpty();
    void setTenLop(string);
    void setLecturer(Lecturer);
    void menu();
    bool isFull();
    void hienThiDanhSachLop();
    void themDoiTuongSVOCuoi();
    void capNhatThongTin();
    int binarySearch(Student*, int, int, string);
    void timDoiTuongTheoTen();
    void mergeSort(Student *, int, int );
    void merge(Student *, int, int, int);
    void sapXepTheoTen();
    friend istream& operator >> (istream& in, LopSinhHoat&);
    friend ostream& operator << (ostream& out,LopSinhHoat&);
    Student & operator [] (int);
    const LopSinhHoat& operator = (const LopSinhHoat&);
    virtual ~LopSinhHoat();
};


#endif //BAITAP03_LOPSINHHOAT_H
