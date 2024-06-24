#include <iostream>

using namespace std;
class ngay
{
private:
    int ng,th,nm;
public:
    friend istream& operator >> (istream&,ngay&);
    friend ostream& operator << (ostream&,ngay&);
};
int main()
{
    ngay a;
    cin >> a;
    cout << a;
    return 0;
}
istream& operator >> (istream &cin, ngay &a)
{
    cout << "Nhap ngay: ";
    cin >> a.ng;
    cout << "Nhap thang: ";
    cin >> a.th;
    cout << "Nhap nam: ";
    cin >> a.nm;
    return cin;
}
ostream& operator << (ostream &cout, ngay &a)
{
    cout << "Ngay " << a.ng << " thang " << a.th << " nam " << a.nm;
    return cout;
}
