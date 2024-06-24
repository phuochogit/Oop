#include <iostream>

using namespace std;
class hocsinh
{
private:
    string hoten;
    int diemtoan;
    int diemvan;
    float diemtrungbinh;
public:
    friend istream& operator >> (istream&, hocsinh&);
    void tinhdiemtrungbinh();
    int operator > (hocsinh&);
};
int main()
{
    hocsinh a,b;
    cin >> a >> b;
    if (a > b)
        cout << "DTB a lon hon DTB b";
    else
        cout << "DTB a khong lon hon DTB b";
    return 0;
}
istream& operator >> (istream &cin, hocsinh& x)
{
    cin >> x.hoten >> x.diemtoan >> x.diemvan;
}
void hocsinh::tinhdiemtrungbinh()
{
    diemtrungbinh = (float) (diemtoan + diemvan)/2;
}
int hocsinh::operator > (hocsinh& x)
{
    this->tinhdiemtrungbinh();
    x.tinhdiemtrungbinh();
    if(diemtrungbinh > x.diemtrungbinh)
        return 1;//Đúng a > b.
    return 0;//Sai a > b.
}

