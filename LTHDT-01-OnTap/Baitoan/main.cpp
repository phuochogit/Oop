#include <iostream>

using namespace std;
//Nhap
//Struct hocsinh hoten,diemtoan,diemvan
//Diemtrungbinh = (diemtoan+diemvan)/2
//Xuat
struct hocsinh
{
    string hoten;
    float diemtoan,diemvan,diemtrungbinh;
};
void nhap(hocsinh &x)
{
    cout << "Nhap ho ten: ";
    cin >> x.hoten;
    cout << "Nhap diem toan: ";
    cin >> x.diemtoan;
    cout << "Nhap diem van: ";
    cin >> x.diemvan;
}
void diemtrungbinh (hocsinh &x)
{
    x.diemtrungbinh = (x.diemtoan+x.diemvan)/2;
}
void xuat(hocsinh x)
{
    cout << "Hoc sinh: " << x.hoten << endl;
    cout << "Diem toan: " << x.diemtoan << endl;
    cout << "Diem van: " << x.diemvan << endl;
    cout << "Diemtrungbinh: " << x.diemtrungbinh << endl;
}
int main()
{
    hocsinh a;
    nhap(a);
    diemtrungbinh(a);
    xuat(a);
    return 0;
}
