#include <iostream>

using namespace std;
//Nhap()
//Xuat()
//Tong() = ((tu1*mau2)+(tu2*mau1))/(mau1*mau2)
//Hieu() = ((tu1*mau2)-(tu2*mau1))/(mau1*mau2)
//Tich() = (tu1*tu2)/(mau1*mau2)
//Thuong() = (tu1*mau2)/(tu2*mau1)
struct phanso
{
    float tu,mau;
};
void nhap (phanso &x)//&x: x.tu, x.mau sẽ được thay đổi giá trị khi nhập x.tu, x.mau
{
    cout << "Nhap tu: ";
    cin >> x.tu;
    cout << "Nhap mau: ";
    cin >> x.mau;
}
phanso tong (phanso x, phanso y)
{
    phanso kq;
    kq.tu = ((x.tu*y.mau)+(y.tu*x.mau));
    kq.mau = (x.mau*y.mau);
    return kq;
}
phanso hieu (phanso x, phanso y)
{
    phanso kq;
    kq.tu = ((x.tu*y.mau)-(y.tu*x.mau));
    kq.mau = (x.mau*y.mau);
    return kq;
}
phanso tich (phanso x, phanso y)
{
    phanso kq;
    kq.tu = (x.tu*y.tu);
    kq.mau = (x.mau*y.mau);
    return kq;
}
phanso thuong (phanso x, phanso y)
{
    phanso kq;
    kq.tu = (x.tu*y.mau);
    kq.mau = (y.tu*x.mau);
    return kq;
}
void xuat (phanso x)
{
    cout << x.tu << "/" << x.mau << " = " << x.tu/x.mau << endl;
}
int main()
{
    phanso a,b,kq;
    nhap(a);
    nhap(b);
    kq = tong(a,b);
    cout << "Tong la: ";
    xuat(kq);
    kq = hieu(a,b);
    cout << "Hieu la: ";
    xuat(kq);
    kq = tich(a,b);
    cout << "Tich la: ";
    xuat(kq);
    kq = thuong(a,b);
    cout << "Thuong la: ";
    xuat(kq);
    return 0;
}
