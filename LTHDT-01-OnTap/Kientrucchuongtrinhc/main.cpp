#include <iostream>

using namespace std;
//Vì sao không sử dụng struct ở một khối khai báo, mà lại dùng nó ở đầu chương trình như là một khối định nghĩa hàm? Vì trong một khối khai báo, các biến được khai báo trong đó sẽ chỉ có hiệu lực trong phạm vi của khối đó. Hiểu struct như là một kiểu dữ liệu được định nghĩa ở mức toàn cục (toàn cục: thường được khai báo ở đầu chương trình. Vì biến toàn cục khai báo bên ngoài tất cả các hàm, và bên trong tất cả các hàm đều có thể gọi lại nó được, ví dụ khai báo kiểu dữ liệu toàn cục là struct phanso, thì kiểu dữ liệu phanso này có thể được gọi trong hàm main, kiểu dữ liệu giá trị trả về hàm nhập hàm xuất, và khai báo biến thuộc kiểu dữ liệu phanso trong hàm nhập hàm xuất.Ở bất cứ hàm nào cũng được.
struct phanso
{
    float tu,mau;
};
void nhap(phanso &x);
phanso tong (phanso x, phanso y);    //tong = (tu1*mau2)+(tu2*mau1)/(mau1*mau2).
phanso hieu (phanso x, phanso y);    //hieu = (tu1*mau2)-(tu2*mau1)/(mau1*mau2).
phanso tich (phanso x, phanso y);    //tich =(tu1*tu2)/(mau1*mau2).
phanso thuong (phanso x, phanso y);//thuong = (tu1*mau2)/(mau1*tu2).
void xuat(phanso x);
int main()
{
    phanso a,b,kq;
    nhap(a);
    nhap(b);
    kq = tong(a,b);
    xuat(kq);
    kq = hieu(a,b);
    xuat(kq);
    kq = tich(a,b);
    xuat(kq);
    kq = thuong(a,b);
    xuat(kq);
    return 0;
}
void nhap(phanso &x)
{
    cout << "Nhap tu:";
    cin >> x.tu;
    cout << "Nhap mau:";
    cin >> x.mau;
}
phanso tong (phanso x, phanso y)
{
    phanso kq;
    kq.tu = (x.tu*y.mau)+(y.tu*x.mau);
    kq.mau = x.mau*y.mau;
    return kq;
}
phanso hieu (phanso x, phanso y)
{
    phanso kq;
    kq.tu = (x.tu*y.mau)-(y.tu*x.mau);
    kq.mau = x.mau*y.mau;
    return kq;
}
phanso tich (phanso x, phanso y)
{
    phanso kq;
    kq.tu = x.tu*y.tu;
    kq.mau = x.mau*y.mau;
    return kq;
}
phanso thuong (phanso x, phanso y)
{
    phanso kq;
    kq.tu = x.tu*y.mau;
    kq.mau = x.mau*y.tu;
    return kq;
}
void xuat(phanso x)
{
    cout << x.tu << "/" << x.mau << " = " << x.tu/x.mau << endl;
}
