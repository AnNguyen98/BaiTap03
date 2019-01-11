#include <iostream>
#include <string>
#include "LopSinhHoat.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    LopSinhHoat myLopSinhHoat;
    //Add students

    Lecturer l1 = Lecturer("Mai Van Ha", 30, "Can Tho", 0, "102mvHa", "full prosfessional");
    Student t1 = Student("Nguyen Van Cam", 20, "Ha Noi", 1, "1023413232", 3.2);
    Student t2 = Student("Nguyen Hoai An", 23, "Hai Phong", 0, "1025313232", 2.2);
    Student t3 = Student("Nguyen Thi Mo", 20, "Ha Tinh", 1, "1023313324", 2.5);
    Student t4 = Student("Nguyen Van Ly", 25, "TP.HCM", 1, "1023135334", 3.0);
    Student t5 = Student("Tran Van Tho", 28, "Long An", 0, "1054231334", 3.2);
    Student t6 = Student("Phan Van Dao", 22, "Da Nang", 0, "1025631343", 4);
    myLopSinhHoat.setTenLop("Lop 16T1");
    myLopSinhHoat.setLecturer(l1);
    myLopSinhHoat.pushBack(t1);
    myLopSinhHoat.pushBack(t2);
    myLopSinhHoat.pushBack(t3);
    myLopSinhHoat.pushBack(t4);
    myLopSinhHoat.pushBack(t5);
    myLopSinhHoat.pushBack(t6);

    myLopSinhHoat.menu();



    return 0;
}
