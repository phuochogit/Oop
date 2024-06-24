#include <iostream>

using namespace std;
class phanso
{
private:
    int tu,mau;
public:
    void nhap();
    int laytu();
    int laymau();
    phanso phansolonnhat(phanso, phanso);
    void xuat();
};
int main()
{
    phanso a, b, lonnhat;
    a.nhap();
    b.nhap();
    lonnhat = lonnhat.phansolonnhat(a,b);
    lonnhat.xuat();
    return 0;
}
void phanso::nhap()
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}
int phanso::laytu()
{
    return tu;
}
int phanso::laymau()
{
    return mau;
}
phanso phanso::phansolonnhat(phanso a, phanso b)
{
    phanso lonnhat = a;
    float psa = (float) a.laytu()/a.laymau();
    float psb = (float) b.laytu()/b.laymau();
    if(psa < psb)
        return b;
    return a;
}
void phanso::xuat()
{
    cout << "Phan so lon nhat la: " << tu << "/" << mau << " = " << (float)tu/mau;
}
