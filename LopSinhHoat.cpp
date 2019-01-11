//
// Created by An Nguyễn on 2018-12-23.
//

#include "LopSinhHoat.h"

LopSinhHoat::LopSinhHoat() {
    this->siSoSV = 0;
    this->arrStudents = new Student[MAX_QUEUE] ;
    this->giaoVienChuNhiem = Lecturer();
    this->tenLopSH = "none";
    this->front = 0;
    this->back = 0;
}
LopSinhHoat::LopSinhHoat(Lecturer giaoVienChuNhiem, Student *arrStudents, string tenLopSH, int siSo, int front=0, int back=0){
    this->siSoSV = siSo;
    this->arrStudents = arrStudents;
    this->giaoVienChuNhiem = giaoVienChuNhiem;
    this->tenLopSH = tenLopSH;
    this->front = front;
    this->back = back;
}
LopSinhHoat::LopSinhHoat(const LopSinhHoat& lopSH) {
    this->siSoSV = lopSH.siSoSV;
    this->arrStudents = lopSH.arrStudents;
    this->giaoVienChuNhiem = lopSH.giaoVienChuNhiem;
    this->tenLopSH = lopSH.tenLopSH;
    this->MAX_QUEUE = lopSH.MAX_QUEUE;
    this->front = lopSH.front;
    this->back = lopSH.back;
}
void LopSinhHoat::menu(){
    int index;
    string valueDeleted;
    while(true){
        cout << "------------------------MENU-----------------------"<<endl;
        cout << "1. Hien thi danh sach lop.\n";
        cout << "2. Them doi tuong Sinh vien.\n";
        cout << "3. Cap nhat thong tin.\n";
        cout << "4. Xoa doi tuong dau mang.\n";
        cout << "5. Tim doi tuong theo ten.\n";
        cout << "6. Sap xep theo ten.\n";
        cout << "0. Exit.\n";
        cout << "--------------------------------------------------"<<endl;
        do{
            cout << "Nhap vao chuc nang : ";
            cin >> index;
            if(index < 0 || index > 6) cout << "Ban chon sai chuc nang !\n";
        }while(index < 0 || index > 6);

        switch (index){
            case 0:
                cout << "Exit.\n";
                exit(0);
            case 1:
                cout << "Hien thi danh sach lop.\n";
                this->hienThiDanhSachLop();
                break;
            case 2:
                cout << "Them doi tuong Sinh vien.\n";
                this->themDoiTuongSVOCuoi();
                break;
            case 3:
                cout << "Cap nhat thong tin.\n";
                this->capNhatThongTin();
                break;
            case 4:
                valueDeleted = this->getFront().getName();
                cout << "Xoa doi tuong dau mang.\n";
                this->popFront();
                cout << "Deleted! - " << valueDeleted << "\n";
                break;
            case 5:
                cout << "Tim doi tuong theo ten.\n";
                this->timDoiTuongTheoTen();
                break;
            case 6:
                cout << "Sap xep theo ten.\n";
                cout << "\n-------------------------------------\n";
                cout << "\nDanh sach sinh vien sau khi sap xep .\n";
                this->sapXepTheoTen();
                break;
        }
        if(index == 0) break;
    }
}
void LopSinhHoat::pushBack(Student student){
    if(this->sizeQQ() < this->MAX_QUEUE){
        this->arrStudents[back] = student;
        this->siSoSV ++;
        this->back ++;
    } else{
        this->popFront();
        this->pushBack(student);
    }
}
void LopSinhHoat::popFront(){
    if(!this->isEmpty()){
        for(int i=this->front; i<this->sizeQQ()-1; i++){
            this->arrStudents[i] = this->arrStudents[i+1];
        }
        this->arrStudents[this->sizeQQ()] = Student();
        this->siSoSV--;
        this->back--;
    } else{
        cout << "QUEUE is empty!!";
    }
}
Student LopSinhHoat::getFront(){
    if(!this->isEmpty())
        return this->arrStudents[front];
    else{
        cout << "QUEUE is empty!!";
        Student student;
        return student;
    }
}
int LopSinhHoat::sizeQQ(){
    return this->siSoSV;
}
bool LopSinhHoat::isEmpty(){
    return this->sizeQQ() == 0;
}
bool LopSinhHoat::isFull(){
    return this->MAX_QUEUE == this->sizeQQ();
}

void LopSinhHoat::hienThiDanhSachLop(){
    if(this->sizeQQ() <= 0){
        cout << "\nDanh sach rong!!!\n";
    }else{
        cout << this->giaoVienChuNhiem;
        cout << setw(55) << "Danh sach lop " << this->tenLopSH << endl << endl;
        cout << "STT" << setw(15) << "Ten" << setw(17) << "Tuoi" << setw(15) << "Dia chi" << setw(15) << "Gioi tinh"
        << setw(15)  << "MSSV" << setw(15) << "Diem TB" << endl;
        for(int i=0; i<siSoSV ; i++){
            cout << " \n  " << i + 1 << "\t" << this->arrStudents[i] << endl;
        }
    }
}
void LopSinhHoat::themDoiTuongSVOCuoi(){
    Student student;
    cout << "Nhap thong tin sinh vien .\n";
    cin >> student;
    this->pushBack(student);
}
void LopSinhHoat::capNhatThongTin(){
    cout << *this;
    int n;
    do{
        cout << "1. Sua thong tin giao vien, 2. Sua thong thin sinh vien : ";
        cin >> n;
        if(n < 1 || n > 2) cout << "\nBan chon sai vui long chon lai!\n";
    }while(n < 1 || n > 2);
    if(n == 2){
        cout << "\nMoi ban chon STT sinh vien can chinh sua : ";
        int index;
        do{
            cin >> index;
            if(index -1 < 0 || index-1 > sizeQQ()) cout << "\nBan nhap sai vui long nhap lai!\n";
        }while(index -1 < 0 || index-1 > sizeQQ());
        cout << "\nNhap thong tin moi :\n";
        Student st;
        cin >> st;
        int temp = this->sizeQQ();
        Student *students = new Student[this->sizeQQ()];
        for(int i=0; i<temp; i++){
            if(i == index-1){
                students[i] = st;
            } else{
                students[i] = this->arrStudents[i];
            }
        }
        //Gan lai cho this
        for(int i=0; i< temp; i++) {
            this->popFront();
            this->pushBack(students[i]);
        }
        delete []students;
    }
    else{
        cout << "Nhap thong tin giao vien chu nhiem :\n";
        Lecturer lecturer;
        cin >> lecturer;
        this->setLecturer(lecturer);

    }
    cout << "\nUpdated!!!\n";
}
void LopSinhHoat::setTenLop(string className){
    this->tenLopSH = className;
}
void LopSinhHoat::setLecturer(Lecturer lecturer){
    this->giaoVienChuNhiem = lecturer;
}

void LopSinhHoat::merge(Student *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    Student L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i].getLastName() <= R[j].getLastName()){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void LopSinhHoat::mergeSort(Student *arr, int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int LopSinhHoat::binarySearch(Student *arr, int begin, int end, string x)
{
    if (end >= begin) {
        int mid = begin + (end - begin) / 2;
        if (arr[mid].getLastName() == x)
            return mid;
        if (arr[mid].getLastName() > x)
            return binarySearch(arr, begin, mid - 1, x);
        return binarySearch(arr, mid + 1, end, x);
    }
    return -1;
}
void LopSinhHoat::timDoiTuongTheoTen(){
    this->sapXepTheoTen();
    cout << "\nNhap ten ban muon tim kiem : ";
    string temp, name = "";
    cin.ignore();
    getline(cin, temp);
    for(int i=0; i<temp.size(); i++)
        name += tolower(temp[i]);
    cout << "name = " << name << endl;
    int result  = this->binarySearch(this->arrStudents, 0, this->sizeQQ() - 1,name);
    (result == -1) ? cout << "Khong tim thay phan tu trong he thong!" << endl
                                : cout << "Tim thay phan tu o vi tri " << result + 1 << ".\n";
}
void LopSinhHoat::sapXepTheoTen(){
    LopSinhHoat lopSinhHoat;
    int sizee = this->sizeQQ();
    for(int i=0; i < sizee; i++){
        lopSinhHoat.pushBack(this->getFront());
        this->popFront();
    }
    cout << "this->sizeQQ() = " << this->sizeQQ() << endl;
    cout << "lopSinhHoat->sizeQQ() = " << lopSinhHoat.sizeQQ() << endl;
    cout << "sizee = " << sizee << endl;
    mergeSort(lopSinhHoat.arrStudents, 0, sizee - 1);
    for(int i=0; i < sizee; i++){
        this->pushBack(lopSinhHoat.getFront());
        lopSinhHoat.popFront();
    }
    cout << *this;
}
istream& operator >> (istream& in, LopSinhHoat& lopSH){
    cout << "Nhap vao ten lop SH : ";
    getline(in, lopSH.tenLopSH);
    cout << "Nhap vao si so      : ";
    in >> lopSH.siSoSV;
    cout << "Thong tin giao vien chu nhiem : ";
    in >> lopSH.giaoVienChuNhiem;
    cout << "Nhap vao thong tin cac sinh vien trong lop:\n";
    for(int i=0; i<lopSH.siSoSV; i++){
        Student student;
        in >> student;
        lopSH.pushBack(student);
    }
    lopSH.front = 0;
    lopSH.back = 0;
    return in;
}
ostream& operator << (ostream& out,LopSinhHoat& lopSH){
    cout << "Ten lop SH          :" << lopSH.tenLopSH << endl;
    cout << "Si so               :" << lopSH.siSoSV << endl;
    cout << "Giao vien chu nhiem :" << lopSH.giaoVienChuNhiem << endl;
    lopSH.hienThiDanhSachLop();
    return out;
}
Student& LopSinhHoat::operator[](int index){
    Student *arrTemp = new Student[this->sizeQQ()];
    for(int i=0; i< this->sizeQQ(); i++){
        arrTemp[i] = arrStudents[i];
    }
    static Student tam;
    return (index>0)&&(index<this->siSoSV) ? arrTemp[index]:tam;
}
const LopSinhHoat& LopSinhHoat::operator=(const LopSinhHoat& lopSH){
    if(this != &lopSH){
        this->siSoSV = lopSH.siSoSV;
        this->arrStudents = lopSH.arrStudents;
        this->giaoVienChuNhiem = lopSH.giaoVienChuNhiem;
        this->tenLopSH = lopSH.tenLopSH;
    }
    return *this;
}
LopSinhHoat::~LopSinhHoat() {
    delete []this->arrStudents;
}