#include <iostream>

using namespace std;
template temp
class phanso
{
private:
    int tu;
    int mau;
public:
    phanso();//Mặc định.
    phanso(const phanso&);//Sao chép. Dùng const để đảm bảo rằng đối tượng được sao chép không bị sửa đổi trong quá trình sao chép. Ví dụ trong hàm sao chép nếu sửa đổi phanso& thì không được vì đã dùng const.
    phanso(int tutu, int maumau);//Nhận tham số đầu vào.
    ~phanso();//Phá hủy.
};
class ngay
{
private:
    int ng;
    int th;
    int nm;
public:
    ngay();//Mặc định.
    ngay(const ngay&);//Sao chép, const &ngay để tham số đầu vào là ngày truyền vào là tham số đã có ở hàm main. Bên trong thân phương thức sao chép không thể thay đổi giá trị của phanso. Đảm bảo sao chép là chỉ sao chép thôi.
    ngay (int ngng, int thth, int nmnm);//Nhận tham số đầu vào.
    ~ngay();//Phá hủy.
};
class thoigian
{
private:
    int gio;
    int phut;
    int giay;
public:
    thoigian();
    thoigian(const thoigian&);
    thoigian(int giogio, int phutphut, int giaygiay);
    ~thoigian();
};
int main()
{
    phanso a;
    phanso b(a);
    phanso c(1,2);
    ngay d; //Constructor được gọi tự động ngay khi khai báo.
    ngay e(d);
    ngay f(30,8,2024);//Ko nhập 01 vì C++ có cơ số octal(cơ số 8). Khi nhập số 01 thì hiểu nó là octal. Tuy nhiên, octal thì chỉ được từ 0->7.
    thoigian g;
    thoigian h(g);
    thoigian k(1,50,48);
    return 0;
}
phanso::phanso()
{
    tu = 1;
    mau = 1;
    cout << tu << "/" << mau << endl;
}
phanso::phanso(const phanso &a)
{
//    tu = a.tu + 1;//Sử dụng const để đảm bảo rằng bên trong thân phương thức sao chép của phanso a không có thay đổi tử và mẫu của a.
    tu = a.tu;
    mau = a.mau;
    cout << tu << "/" << mau << endl;
}
phanso::phanso(int tutu, int maumau)
{
    tu = tutu;
    mau = maumau;
    cout << tu << "/" << mau << endl;
}
phanso::~phanso()
{
    cout << "Đã phá hủy phân số." << endl;
}
ngay::ngay()
{
    ng = 1;
    th = 1;
    nm = 2024;
    cout << " Ngay: " << ng << " Thang: " << th << " Nam: " << nm << endl;
}
ngay::ngay(const ngay &d)//const &ngay không thay đổi được ng, th, nm bên trong thân hàm.
{
    ng = d.ng;
    th = d.th;
    nm = d.nm;
    cout << " Ngay: " << ng << " Thang: " << th << " Nam: " << nm << endl;
}
ngay::ngay(int ngng, int thth, int nmnm)
{
    ng = ngng;
    th = thth;
    nm = nmnm;
    cout << " Ngay: " << ng << " Thang: " << th << " Nam: " << nm << endl;
}
ngay::~ngay()//Phương thức phá hủy đi trình tự từ dưới lên trên theo tôi hiểu là bởi vì. Ví dụ Phuoc rời khỏi DotB. Thì hủy drive tài nguyên của Phuoc trong DotB lần lượt từ những cái Phuoc đã là gần đây nhất từ mầm non, đến alab, đến các bài tập đầu vào.
{
    cout << "Đã phá hủy ngày." << endl;
}
thoigian::thoigian()
{
    gio = 0;
    phut = 0;
    giay = 0;
    cout << gio << " gio " << phut << " phut " << giay << " giay " << endl;
}
thoigian::thoigian(const thoigian& ghk)
{
    gio = ghk.gio;
    phut = ghk.phut;
    giay = ghk.giay;
    cout << gio << " gio " << phut << " phut " << giay << " giay " << endl;
}
thoigian::thoigian(int giogio, int phutphut, int giaygiay)
{
    gio = giogio;
    phut = phutphut;
    giay = giaygiay;
    cout << gio << " gio " << phut << " phut " << giay << " giay " << endl;
}
thoigian::~thoigian()
{
cout << "Đã phá hủy thời gian." << endl;
}
