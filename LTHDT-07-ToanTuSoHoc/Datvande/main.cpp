#include <iostream>

using namespace std;
//Tong() = ((tu1*mau2)+(tu2*mau1))/(mau1*mau2)
//Hieu() = ((tu1*mau2)-(tu2*mau1))/(mau1*mau2)
//Tich() = (tu1*tu2)/(mau1*mau2)
//Thuong() = (tu1*mau2)/(tu2*mau1)
class phanso
{
private:
    int tu;
    int mau;
public:
    friend istream& operator >> (istream&,phanso&);
    friend ostream& operator << (ostream&,phanso);
    phanso operator + (phanso);
    phanso operator - (phanso);
    phanso operator * (phanso);
    phanso operator / (phanso);
};
int main()
{
    phanso a,b, kq;
    cin >> a >> b;
    kq = a + b;
    cout << "Tong:" << kq << endl;
    kq = a - b;
    cout << "Hieu:" << kq << endl;
    kq = a * b;
    cout << "Tich:" << kq << endl;
    kq = a / b;
    cout << "Thuong:" << kq << endl;
    return 0;
}
istream& operator >> (istream&cin, phanso& x)
{
    cout << "Nhap tu: ";
    cin >> x.tu;
    cout << "Nhap mau: ";
    cin >> x.mau;
    return cin;
}
ostream& operator << (ostream&cout, phanso x)
{
    cout << x.tu << "/" << x.mau;
    return cout;
}
phanso phanso::operator + (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.mau) + (x.tu*mau);
    temp.mau = (mau * x.mau);
    return temp;
}
phanso phanso::operator - (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.mau) - (x.tu*mau);
    temp.mau = (mau * x.mau);
    return temp;
}
phanso phanso::operator * (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.tu);
    temp.mau = (mau * x.mau);
    return temp;
}
phanso phanso::operator / (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.mau);
    temp.mau = (x.tu * mau);
    return temp;
}
