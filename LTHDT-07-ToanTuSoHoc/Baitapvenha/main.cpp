#include <iostream>

using namespace std;
//Tong() = ((tu1*mau2)+(tu2*mau1))/(mau1*mau2)
//Hieu() = ((tu1*mau2)-(tu2*mau1))/(mau1*mau2)
//Tich() = (tu1*tu2)/(mau1*mau2)
//Thuong() = (tu1*mau2)/(tu2*mau1)
//++tratien: Trả tiền trước ăn sau.
//tratien++: Trả tiền sau, ăn trước.
//Vòng for thì không cần lo lắng về ++travien, tratien++ trả tiền sau hay trước gì cũng được vì cấu trúc vòng for xét biến khởi tạo > thỏa điều kiện lặp > thân > tăng biến vòng lặp > thỏa điều kiện lặp > thân > tăng biến vòng lặp ... > không thỏa điều kiện lặp.
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
    phanso operator += (phanso);
    phanso operator -= (phanso);
    phanso operator *= (phanso);
    phanso operator /= (phanso);
    phanso operator ++ ();
    phanso operator ++ (int);//(int) dùng để đánh dấu phân biệt là toán tử hậu tố(tratien++) chứ không phải là toán tử tiền tố (++tratien), theo chuẩn qui ước của C++.
    phanso operator -- ();
    phanso operator -- (int);//Ký hiệu là hậu tố theo qui ước chuẩn C++.
    int uocchunglonnhat();
    void rutgon();
};
int main()
{
    phanso a,b,kq;
    cin >> a >> b;
    kq = a + b;
    cout << "Tong:" << kq << endl;
    kq = a - b;
    cout << "Hieu:" << kq << endl;
    kq = a * b;
    cout << "Tich:" << kq << endl;
    kq = a / b;
    cout << "Thuong:" << kq << endl;
    a += b;
    cout << "Toan tu a += b: " << a << endl;
    a -= b;
    cout << "Toan tu a -= b: " << a << endl;
    a *= b;
    cout << "Toan tu a *= b: " << a << endl;
    a /= b;
    cout << "Toan tu a /= b: " << a << endl;//Rút gọn
    cout << "Toan tu ++a: " << ++a << endl;
    cout << "Toan tu a++: " << a++ << endl;//a = 1.
    cout << "Toan tu a++: " << a << endl;//a = 2.
    cout << "Toan tu --a: " << --a << endl;
    cout << "Toan tu a--: " << a-- << endl;//a = 2.
    cout << "Toan tu a--: " << a << endl;//a = 1.
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
    temp.rutgon();
    return temp;
}
phanso phanso::operator - (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.mau) - (x.tu*mau);
    temp.mau = (mau * x.mau);
    temp.rutgon();
    return temp;
}
phanso phanso::operator * (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.tu);
    temp.mau = (mau * x.mau);
    temp.rutgon();
    return temp;
}
phanso phanso::operator / (phanso x)
{
    phanso temp;
    temp.tu = (tu * x.mau);
    temp.mau = (x.tu * mau);
    temp.rutgon();
    return temp;
}
phanso phanso::operator += (phanso x)
{
    tu = (tu*x.mau) + (x.tu*mau);
    mau *= x.mau;
    this->rutgon();
    return *this;
}
phanso phanso::operator -= (phanso x)
{
    tu = (tu*x.mau) - (x.tu*mau);
    mau *= x.mau;
    this -> rutgon();
    return *this;
}
phanso phanso::operator *= (phanso x)
{
    tu *= x.tu;
    mau *= x.mau;
    this ->rutgon();
    return *this;
}
phanso phanso::operator /= (phanso x)
{
    tu *= x.mau;
    mau = x.tu * mau;
    this->rutgon();
    return *this;
}
phanso phanso::operator ++ ()
{
    tu = (tu*1) + (1*mau);
    mau *= 1;
    this->rutgon();
    return *this;
}
phanso phanso::operator ++ (int)// Rutgon.
{
    phanso temp = *this;//Trả về temp = a = 1/1.
    temp.rutgon();
    tu = (tu*1) + (1*mau);//a.tu + 1 = 2.
    mau *= 1;//a.mau + 1 = 1.
    this->rutgon();
    //*this = 2/1
    return temp;//Trả về temp = 1/1.
}
phanso phanso::operator -- ()
{
    tu = (tu*1) - (1*mau);
    mau *= 1;
    this->rutgon();
    return *this;
}
phanso phanso::operator -- (int)
{
    phanso temp = *this;
    temp.rutgon();
    tu = (tu*1) - (1*mau);
    mau *= 1;
    this->rutgon();
    return temp;
}
int phanso::uocchunglonnhat()
{
    phanso t;
    t.tu = tu;
    t.mau = mau;
    while (t.mau != 0)
    {
        int temp = t.mau;
        t.mau = t.tu%t.mau;
        t.tu = temp;
    }
    return t.tu;
}
void phanso::rutgon()
{
    int ucln = this->uocchunglonnhat();
    tu /= ucln;
    if (tu == 0) //Nếu bỏ dòng này test 2 số 0/1 và 0/27 -> Kết quả đúng là 0/1+0/27 = 0/27. Đây nếu bỏ sẽ ra 0/1 thay vì 0/27. Ra 0/1 vì lấy mau = mau/ucln. Tìm ucln sẽ ra = 27 => mau = 27/27 = 1 -> 0/1. Xét điều kiện nếu tu == 0 mau = mau. Ko tìm ucln nữa sẽ ra thẳng 0/27 (đúng) thay vì ra 0/1 (sai). Ví dụ cụ thể coi ở bài LTHDT-03-LapTrinhHDTVoiC++ Ungdung1.
        mau = mau;
    else
        mau /= ucln;
}
