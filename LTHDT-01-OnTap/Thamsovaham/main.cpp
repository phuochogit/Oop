#include <iostream>

using namespace std;
//Đầu vào: tham số của hàm.
//Hai loại tham số: tham trị(không đổi), tham biến &(thay đổi).
//Cấp phát bộ nhớ: Tham trị cấp phát bộ nhớ để lưu giá trị một biến, tham biến không cấp phát bộ nhớ cập nhật giá trị dựa trên biến có bộ nhớ đã cấp phát ban đầu.
void nhap (string &hoten, float &diemtoan, float &diemvan);
float diemtrungbinh (float diemtoan, float diemvan);
void xuat(string hoten, float diemtoan, float diemvan,float diemtrungbinh);//? float diemtoan,diemvan luôn một lần trong hàm được. Vì C++ cần chỉ rõ kiểu dữ liệu của mỗi biến là gì trong hàm. Không tự hiểu ví dụ như trong hàm main int a,b; được.
int main()
{
    string hoten;
    float diemtoan,diemvan,diemtb;
    nhap(hoten,diemtoan,diemvan);
    diemtb = diemtrungbinh(diemtoan,diemvan);
    xuat(hoten,diemtoan,diemvan,diemtb);
    return 0;
}
void nhap (string &hoten, float &diemtoan, float &diemvan)
{
    cout << "Nhap ho ten: ";
    cin>> hoten;
    cout << "Nhap diem toan: ";
    cin>> diemtoan;
    cout << "Nhap diem van: ";
    cin>> diemvan;
}
float diemtrungbinh (float diemtoan, float diemvan)
{
     return (diemtoan+diemvan)/2;
}
void xuat(string hoten, float diemtoan, float diemvan,float diemtrungbinh)
{
    cout << "Ho ten: " << hoten << endl;
    cout << "Diem toan: " << diemtoan << endl;
    cout << "Diem van: " << diemvan << endl;
    cout << "Diem trung binh: " << diemtrungbinh << endl;
}
