#include <iostream>

using namespace std;
//Biến toàn cục khai báo bên ngoài tất cả các hàm và bên trong tất cả các hàm đều có thể gọi lại nó được.
//Ví dụ: biến toàn cục hoten gọi trong hàm main, hàm nhập, hàm xuất đều có nó.
//Biến khai báo bên trong thân hàm main không phải là biến toàn cục mà là biến cục bộ của hàm main.
string hoten;
float diemtoan,diemvan,diemtrungbinh;
int main()
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap diem toan: ";
    cin >> diemtoan;
    cout << "Nhap diem van: ";
    cin >> diemvan;
    diemtrungbinh = (diemtoan+diemvan)/2;
    cout <<"Ho ten: " << hoten << endl;
    cout <<"Diem toan: " << diemtoan << endl;
    cout <<"Diem van : " << diemvan << endl;
    cout <<"Diem trung binh: " << diemtrungbinh << endl;
    return 0;
}
