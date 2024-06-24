#include <iostream>

using namespace std;
class phanso
{
private:
    int tu;
    int mau;
public:
    friend istream& operator >> (istream&,phanso&);
    float ketqua();
    int operator > (phanso);
    int operator < (phanso);
    int operator >= (phanso);
    int operator <= (phanso);
    int operator == (phanso);
    int operator != (phanso);
};
int main()
{
    phanso a,b;
    cin >> a >> b;
    if (a>b)
        cout << "a > b" << endl;
    if (a<b)
        cout << "a < b" << endl;
    if (a>=b)
        cout << "a >= b" << endl;
    if (a<=b)
        cout << "a <= b" << endl;
    if (a==b)
        cout << "a == b" << endl;
    if (a!=b)
        cout << "a != b" << endl;
    return 0;
}
istream& operator >> (istream& cin, phanso& x)
{
    cin >> x.tu >> x.mau;
}
float phanso::ketqua()
{
    float kq = (float)tu/mau;//(float)(tu/mau) không được vì (3/4) > (0) > (float)(0) = 0.
    return kq;
}
int phanso::operator > (phanso x)
{
    float a = this->ketqua();
    float b = x.ketqua();
    if (a > b)
        return 1;
    return 0;
}
int phanso::operator < (phanso x)
{
    float a = this->ketqua();
    float b = x.ketqua();
    if (a < b)
        return 1;
    return 0;
}
int phanso::operator >= (phanso x)
{
    float a = this->ketqua();
    float b = x.ketqua();
    if (a >= b)
        return 1;
    return 0;
}
int phanso::operator <= (phanso x)
{
    float a = this->ketqua();
    float b = x.ketqua();
    if (a <= b)
        return 1;
    return 0;
}
int phanso::operator == (phanso x)
{
    float a = this->ketqua();
    float b = x.ketqua();
    if (a == b)
        return 1;
    return 0;
}
int phanso::operator != (phanso x)
{
    float a = this->ketqua();
    float b = x.ketqua();
    if (a != b)
        return 1;
    return 0;
}
