#include <iostream>

using namespace std;
class ngay
{
private:
    int ng;
    int th;
    int nm;
public:
    friend istream& operator >> (istream&,ngay&);
    int operator == (ngay);
    int operator != (ngay);
};
class thoigian
{
private:
    int gio;
    int phut;
    int giay;
public:
    friend istream& operator >> (istream&,thoigian&);
    int operator == (thoigian);
    int operator != (thoigian);
};
int main()
{
//    ngay ng1,ng2;
//    cin >> ng1 >> ng2;
//    if(ng1 == ng2)
//        cout << "Ngay 1 == Ngay 2" << endl;
//    if(ng1 != ng2)
//        cout << "Ngay 1 != Ngay 2" << endl;
    thoigian tg1, tg2;
    cin >> tg1 >> tg2;
    if (tg1 == tg2)
        cout << "Thoi gian 1 == Thoi gian 2" << endl;
    if (tg1 != tg2)
        cout << "Thoi gian 1 != Thoi gian 2" << endl;
    return 0;
}
istream& operator >> (istream&cin, ngay& x)
{
    cin >> x.ng >> x.th >> x.nm;
}
int ngay::operator == (ngay x)
{
    if((ng == x.ng) && (th == x.th) && (nm == x.nm))
        return 1;
    return 0;
}
int ngay::operator != (ngay x)
{
    if((ng != x.ng) || (th != x.th) || (nm != x.nm))
        return 1;
    return 0;
}
istream& operator >> (istream& cin, thoigian& x)
{
    cin >> x.gio >> x.phut >> x.giay;
}
int thoigian::operator == (thoigian x)
{
    if((gio == x.gio) && (phut == x.phut) && (giay == x.giay))
        return 1;
    return 0;
}
int thoigian::operator != (thoigian x)
{
    if((gio != x.gio) || (phut != x.phut) || (giay != x.giay))
        return 1;
    return 0;
}
