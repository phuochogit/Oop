#include <iostream>

using namespace std;
struct phanso // Tự định nghĩa biến phân số của mình. Ví dụ biến có sẵn là int.
{
    int tu;
    int mau;
};
void nhap (phanso& x)//&:Tham chiếu. Mọi thay đổi trên biến tham chiếu đều sẽ thay đổi trên biến được tham chiếu.
{
    cout << "Nhap tu: ";
    cin >> x.tu;
    cout << "Nhap mau: ";
    cin >> x.mau;
}
void xuat (phanso x)//Hàm tại sao lại có tham số x? giống khai báo biến ví dụ int a,
{
    cout << "Tu: " << x.tu;
    cout << "Mau: " << x.mau;
}
int xetdau (phanso x)
{
    if (x.tu*x.mau > 0)
        return 1;
    if (x.tu*x.mau < 0)
        return -1;
    return 0;
}
int main()
{
    phanso x;
    nhap(x);
    switch (xetdau(x))
    {
        case 1: cout << "Phan so " << x.tu << "/" << x.mau << " la phan so duong";
        break;
        case -1: cout << "Phan so " << x.tu << "/" << x.mau << " la phan so am";
        break;
        case 0: cout << "Phan so " << x.tu << "/" << x.mau << " la phan so bang khong";
        break;
    }
    return 0;
}
