#include <iostream>

using namespace std;
//Tại sao khối khai báo phải void Nhap (char[],int &, int&) mà không nhập (char[]hoten, int &diemtoan, int &diemvan). Để nhìn đơn giản, khỏi rối. Ví dụ: Bai9.
void nhap (string &, float &, float &);
void diemtrungbinh (float , float , float &);
void xuat (string ,float , float, float);
int main()
{
    string hoten;
    float diemtoan, diemvan,diemtb;
    nhap(hoten,diemtoan,diemvan);
    diemtrungbinh(diemtoan,diemvan,diemtb);
    xuat(hoten,diemtoan,diemvan,diemtb);
    return 0;
}
void nhap (string &hoten, float &diemtoan, float &diemvan)
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap diem toan: ";
    cin >> diemtoan;
    cout << "Nhap diem van: ";
    cin >> diemvan;
}
void diemtrungbinh (float toan, float van, float &tb)// toan, van, &tb chỉ có hiệu lực trong hàm diemtrungbinh() này thôi.
{
    tb = (toan+van)/2;
}
void xuat (string hoten,float toan, float van, float tb)
{
    cout << "Ho ten: " << hoten << endl;
    cout << "Diem toan: " << toan << endl;
    cout << "Diem van: " << van << endl;
    cout << "Diem trung binh: " << tb << endl;
}
