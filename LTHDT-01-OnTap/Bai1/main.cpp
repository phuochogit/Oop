#include <iostream>

using namespace std;
struct phanso
{
    int tu,mau;
};
void nhap(phanso&);
void xuly(phanso);
int main()
{
    phanso a;
    nhap(a);
    xuly(a);
    return 0;
}
void nhap(phanso &x)
{
    cout << "Nhap tu: ";
    cin >> x.tu;
    cout << "Nhap mau: ";
    cin >> x.mau;
}
void xuly(phanso x)
{
    float kq = (float)x.tu/x.mau;
    if (kq < 0)
        cout << "Phan so " << x.tu << "/" << x.mau << " la phan so am";
    if (kq > 0)
        cout << "Phan so " << x.tu << "/" << x.mau << " la phan so duong";
    if (kq == 0)
        cout << "Phan so " << x.tu << "/" << x.mau << " la phan so bang khong";
}
