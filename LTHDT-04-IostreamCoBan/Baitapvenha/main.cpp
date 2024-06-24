#include <iostream>

using namespace std;
class thoigian
{
private:
    int gio,phut,giay;
public:
    friend istream& operator >> (istream&,thoigian&);
    friend ostream& operator << (ostream&,thoigian&);
};
int main()
{
    thoigian a;
    cin >> a;
    cout << a;
    return 0;
}
istream& operator >> (istream &cin, thoigian &a)
{
    cout << "Nhap gio: ";
    cin >> a.gio;
    cout << "Nhap phut: ";
    cin >> a.phut;
    cout << "Nhap giay: ";
    cin >> a.giay;
    return cin;
}
ostream& operator << (ostream &cout, thoigian &a)
{
    cout << a.gio << " gio " << a.phut << " phut " << a.giay << " giay ";
}
