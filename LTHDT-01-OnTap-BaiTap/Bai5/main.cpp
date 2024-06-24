#include <iostream>

using namespace std;
struct phanso
{
    int tu,mau;
};
void nhap (phanso &x)
{
    cout << "Nhap tu: ";
    cin >> x.tu;
    cout << "Nhap mau: ";
    cin >> x.mau;
}
void xuat (phanso x)
{

    cout << "Phan so lon nhat la: "<< x.tu << "/" << x.mau << " = " << (float) x.tu/x.mau;
}
int sosanh (phanso x, phanso y)
{
    float a =  (float) x.tu/x.mau;//Lấy mẫu chia tử nên bị sai.
    float b =  (float) y.tu/y.mau;
    if (a>b)
        return 1;
    if (a<b)
        return -1;
    return 0;
}
int main()
{
    phanso a,b;
    cout << "Nhap phan so thu nhat: " << endl;
    nhap(a);
    cout << "Nhap phan so thu hai: " << endl;
    nhap(b);
    int kq = sosanh(a,b);
    if (kq == 1)
        xuat(a);
    if (kq == -1)
        xuat(b);
    if (kq == 0)
        xuat(a);
    return 0;
}
