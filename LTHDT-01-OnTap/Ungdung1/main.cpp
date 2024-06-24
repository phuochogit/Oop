#include <iostream>

using namespace std;
struct phanso
{
    int tu,mau;
};
void nhap (phanso&);
int ucln (phanso);
void rutgon (phanso&);
void xuat (phanso);
int main()
{
    phanso a;
    nhap(a);
    rutgon(a);
    xuat(a);
    return 0;
}
void nhap (phanso&a)
{
    cout << "Nhap tu: ";
    cin >> a.tu;
    cout << "Nhap mau: ";
    cin >> a.mau;
}
int ucln (phanso a)
{
    while (a.mau != 0)
    {
        int temp = a.mau;
        a.mau = a.tu%a.mau;
        a.tu = temp;
    }
    return a.tu;
}
void rutgon (phanso&a)
{
    int ucl = ucln(a);
    a.tu = a.tu/ucl;
    a.mau = a.mau/ucl;
}
void xuat (phanso a)
{
    cout << "Phan so sau khi rut gon la: " << a.tu << "/" << a.mau << " = " << (float)a.tu/a.mau;
}
