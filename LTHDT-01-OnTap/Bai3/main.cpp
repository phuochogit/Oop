#include <iostream>

using namespace std;
//Lập trình hướng đơn thể?
struct phanso
{
    int tu, mau;
};
void nhap (phanso&, phanso&);
phanso timphansolonnhat (phanso, phanso);
void xuat(phanso);
int main()
{
    phanso a,b,lonnhat;
    nhap(a,b);
    lonnhat = timphansolonnhat(a,b);
    xuat(lonnhat);
    return 0;
}
void nhap (phanso&a, phanso&b)
{
    cout  << "Nhap phan so 1" << endl;
    cout << "Nhap tu: ";
    cin >> a.tu;
    cout << "Nhap mau: ";
    cin >> a.mau;
    cout  << "Nhap phan so 2" << endl;
    cout << "Nhap tu: ";
    cin >> b.tu;
    cout << "Nhap mau: ";
    cin >> b.mau;
}
phanso timphansolonnhat (phanso a, phanso b)
{
    phanso lonnhat = a;
    if ((float)b.tu/b.mau >(float)a.tu/a.mau)
        lonnhat = b;
    return lonnhat;
}
void xuat(phanso a)
{
    cout << " Phan so lon nhat: " << a.tu << "/" << a.mau << endl;
}
