#include <iostream>

using namespace std;
//Trừu tượng hóa dữ liệu: Mô tả tổng quan một đối tượng trong thế giới thực. Và chi tiết các thuộc tính của đối tượng đó. Ví dụ đối tượng con người (chiều cao, câng nặng, giới tính, ngày sinh).
struct hocsinh //Tại sao struct không ở khối khai báo? Vì nó là kiểu dữ liệu toàn cục, khai báo ngoài tất cả các hàm và bên trong các hàm đều có thể sử dụng được. Còn khối khai báo thì biến trong khối khai báo chỉ có hiệu lực trong hàm khối khai báo đó mà thôi, ra ngoài gọi lại dùng không được.
{
    string hoten;
    float diemtoan,diemvan,diemtrungbinh;
};
void nhap (hocsinh&);
void diemtb (hocsinh&);
void xuat (hocsinh);
int main()
{
    hocsinh a;
    nhap(a);
    diemtb(a);
    xuat(a);
    return 0;
}
void nhap (hocsinh& a)
{
    cout << "Nhap ho ten: ";
    cin >> a.hoten;
    cout << "Nhap diem toan: ";
    cin >> a.diemtoan;
    cout << "Nhap diem van: ";
    cin >> a.diemvan;
}
void diemtb (hocsinh& a)
{
    a.diemtrungbinh = (a.diemtoan+a.diemvan)/2;
}
void xuat (hocsinh a)
{
    cout << "Ho ten: " << a.hoten << endl;
    cout << "Diem toan: " << a.diemtoan << endl;
    cout << "Diem van: " << a.diemvan << endl;
    cout << "Diem trung binh: " << a.diemtrungbinh << endl;
}
