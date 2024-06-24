#include <iostream>

using namespace std;
//Khai báo lớp
class CNgay
{
    private://Tại sao chỗ này lại private để mà chi?
        int ngay,thang,nam;
    public:
        CNgay();
        CNgay(int, int, int);
        CNgay(const CNgay&);
        ~CNgay();
        friend istream& operator >> (istream &is, CNgay &x);
        friend ostream& operator << (ostream &os, CNgay &x);
        CNgay operator = (CNgay &);
        CNgay operator ++ (int);//Vì sao chỗ này là int?
        CNgay operator -- (int);
        int operator > (CNgay);
        int operator < (CNgay);
};
int main()
{
    CNgay a;//Định nghĩa phương thức thiết lập mặc định.
    CNgay b(a);//Định nghĩa phương thức thiết lập sao chép.
    CNgay c(2,2,2);//Định nghĩa phương thức thiết lập khi biết đầy đủ thông tin.
    CNgay d;
    cin >> d;//Định nghĩa toán tử vào.
    cout << d;//Định nghĩa toán tử ra.
    CNgay e;
    e = d;//Định nghĩa toán tử gán.
    cout << e;
    CNgay f = e++;//Định nghĩa toán tử tăng một.
    cout << f;
    CNgay g = e--;//Định nghĩa toán tử giảm một.
    cout << g;
    if (f>g)//Định nghĩa toán tử so sánh lớn.
        cout << "Nam f lon hon nam g" << endl;
    else
        cout << "Nam f khong lon hon nam g" << endl;
    if (g<f)
        cout << "Nam g be hon nam f" << endl;
    else
        cout << "Nam g khong be hon nam f" << endl;
    return 0;
}
//Định nghĩa phương thức thiết lập mặc định.
CNgay::CNgay()
{
    ngay = 1;
    thang = 1;
    nam = 1;
}
//Định nghĩa phương thức thiết lập sao chép.
CNgay::CNgay(const CNgay &x)
{
    ngay = x.ngay;
    thang = x.thang;
    nam = x.nam;
}
//Định nghĩa phương thức thiết lập khi biết đầy đủ thông tin.
CNgay::CNgay(int ng, int th, int nm)
{
    ngay = ng;
    thang = th;
    nam = nm;
}
CNgay::~CNgay()
{
    return;
}
//Định nghĩa toán tử vào.
istream& operator >> (istream &is, CNgay &x)
{
    cout << "Nhap ngay: ";
    is >> x.ngay;
    cout << "Nhap thang: ";
    is >> x.thang;
    cout << "Nhap nam: ";
    is >> x.nam;
    return is; // Tại sao phải trả về is?
}
//Định nghĩa toán tử ra.
ostream& operator << (ostream &os, CNgay &x)
{
    os << x.ngay << " " << x.thang << " " << x.nam << " " << endl;
    return os;
}
//Định nghĩa toán tử gán.
CNgay CNgay::operator = (CNgay &x)
{
    ngay = x.ngay;
    thang = x.thang;
    nam = x.nam;
    return *this;
}
//Định nghĩa toán tử tăng một.
CNgay CNgay::operator++(int x)
{
    CNgay temp;
    temp.ngay = ngay + 1;
    temp.thang = thang + 1;
    temp.nam = nam + 1;
    return temp;
}
//Định nghĩa toán tử giảm một.
CNgay CNgay::operator--(int x)
{
    CNgay temp;
    temp.ngay = ngay - 1;
    temp.thang = thang - 1;
    temp.nam = nam - 1;
    return temp;
}
//Định nghĩa toán tử so sánh lớn.
int CNgay::operator > (CNgay x)
{
    if (nam > x.nam);
        return 1;
    return 0;
}
//Định nghĩa toán tử so sánh bé.
int CNgay::operator < (CNgay x)
{
    if (nam < x.nam);
        return 1;
    return 0;
}
