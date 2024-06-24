#include <iostream>

using namespace std;
//Kiến trúc chương trình C.
//Khối khai báo: Khai báo hàm, biến toàn cục, thư viện, hằng,kiểu dữ liệu.
//Khối hàm main: Chỉ chứa hàm main, và chứa các lời gọi hàm cần thiết, ví dụ chứa lời gọi hàm nhập, xuất bên trong hàm main.
//Khối định nghĩa hàm: chứa các định nghĩa hàm đã được khai báo, ví dụ khai báo ra hàm void nhap(phanso x).Định nghĩa hàm sẽ ghi là bên trong cin>>x.tu, cin>>x.mau như thế nào. Mình hiểu vậy là đúng hay sai.
//Tại sao phải tuân theo kiến trúc: Khai báo, hàm main, định nghĩa hàm?
void nhap();
string hoten;
float diemtoan,diemvan,diemtrungbinh;
void tinhdiemtrungbinh();
void xuat();
int main()
{
    nhap();
    tinhdiemtrungbinh();
    xuat();
    return 0;
}
void nhap()
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap diem toan: ";
    cin >> diemtoan;
    cout << "Nhap diem van: ";
    cin >> diemvan;
}
void tinhdiemtrungbinh()
{
    diemtrungbinh=(diemtoan+diemvan)/2;
}
void xuat()
{
    cout << "Ho ten: " << hoten <<endl;
    cout << "Diem toan: " << diemtoan <<endl;
    cout << "Diem van: " << diemvan <<endl;
    cout << "Diem trung binh: " << diemtrungbinh <<endl;
}
