#include <iostream>

using namespace std;
class phanso
{
private:
    int tu,mau;
public:
    void nhap();
    int uocchunglonnhat(phanso);
    void rutgon(phanso &);
    void xuat();
};
int main()
{
    phanso a;
    a.nhap();
    a.rutgon(a);
    a.xuat();
    return 0;
}
void phanso::nhap()
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}
int phanso::uocchunglonnhat(phanso a)
{
     while (a.mau != 0)
    {
        int temp = a.mau;
        a.mau = a.tu%a.mau;
        a.tu = temp;
    }
    return a.tu;
}
void phanso::rutgon(phanso &a)
{
    int ucln = uocchunglonnhat(a);
    a.tu = a.tu/ucln;
    if (a.tu==0)
        a.mau = a.mau; //Test số 0/27. -> ra 0/27(đúng) hay ra 0/1(sai)
    else
        a.mau = a.mau/ucln;
}
void phanso::xuat()
{
    cout << "Phan so sau khi rut gon la: " << tu << "/" << mau << " = " << (float)tu/mau;
}
