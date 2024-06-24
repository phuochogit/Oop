#include <iostream>

using namespace std;
//Biến cục bộ là biến được khai báo trong một hàm, và phạm vi sử dụng chỉ trong một hàm đó thôi. Ra hàm khác sử dụng không được
//Ví dụ: Nhap(int a, int b), Xuat (int b, int c). Biến b của hàm nhập thì chỉ sử dụng được trong hàm nhập, qua hàm xuất sử dụng lại biến b không được.
//Biến khai báo trong thân hàm main là biến cục bộ của hàm main
int main()
{
    string hoten;
    float diemtoan,diemvan,diemtrungbinh;
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
