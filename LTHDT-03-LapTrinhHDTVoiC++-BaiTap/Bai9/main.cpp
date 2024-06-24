#include <iostream>

using namespace std;
//Hàm rút gọn phân số hoặc qua bài mới.
//Tong() = ((tu1*mau2)+(tu2*mau1))/(mau1*mau2)
//Hieu() = ((tu1*mau2)-(tu2*mau1))/(mau1*mau2)
//Tich() = (tu1*tu2)/(mau1*mau2)
//Thuong() = (tu1*mau2)/(tu2*mau1)
class phanso
{
private:
    int tu,mau;
public:
    void nhap();//Khai báo thôi thì vẫn không được coi là phương thức thành viên của class phanso, cần phải định nghĩa thì nó mới coi là phương thức thành viên của class phanso.
    int laytu();
    int laymau();
    phanso tong(phanso,phanso);
    phanso hieu(phanso,phanso);
    phanso tich(phanso,phanso);
    phanso thuong(phanso,phanso);
    int ucln (phanso);
    void rutgon(phanso&);
    void xuat();
};
int main()
{
    phanso a, b, kqtong, kqhieu, kqtich, kqthuong;
    a.nhap();
    b.nhap();
    kqtong=kqtong.tong(a,b);
    kqtong.rutgon(kqtong);// Ví dụ có 2 phân số: 5/4 + 5/4 = 40/16. Nếu để kqtong.rutgon() thì sẽ ra kết quả = 1/0 vì hàm ucln() sẽ trả về ucln = tu = 8, và mau = 0. Lúc này vô hàm rutgon(), tu = tu/ucln(8/8), tu = 1, và mau = mau/ucln(0/8), mau = inf ko xác định. Vì vậy ở đây ta cần dùng kqtong.rutgon(kqtong) để với tu = 40, mau = 16 gọi hàm tìm ucln(phanso kqtong) = 8. Và phanso kqtong tu = 40, mau=16 không thay đổi vì ko có tham chiếu & trong hàm ucln(phanso kqtong). Sau đó ở hàm rutgon(phanso &kqtong) có tham chiếu & nên sẽ thay đổi tu, mau của phanso kqtong. Lúc này ucln = 8. tu = tu/ucln (40/8), mau = mau/ucln(16/8). tu = 5, mau = 2. Và ở đây có tham chiếu & rutgon(phanso &kqtong) nên sẽ thay đổi giá trị phanso kqtong tu,mau bên ngoài hàm main từ 40/16 thành 5/2.
    cout << "Tong la: ";
    kqtong.xuat();
    kqhieu=kqhieu.hieu(a,b);
    kqhieu.rutgon(kqhieu);
    cout << "Hieu la: ";
    kqhieu.xuat();
    kqtich=kqtich.tich(a,b);
    kqtich.rutgon(kqtich);
    cout << "Tich la: ";
    kqtich.xuat();
    kqthuong=kqthuong.thuong(a,b);
    kqthuong.rutgon(kqthuong);
    cout << "Thuong la: ";
    kqthuong.xuat();
    return 0;
}
void phanso::nhap()//Định nghĩa phương thức thành viên nhap() của lớp phanso. Lúc này phương thức nhập mới chính thức là phương thức thành viên của class phanso.
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}
int phanso::laytu()//Có dấu phanso:: để định nghĩa đây chính thức là phương thức thành viên của lớp phân số.
{
    return tu;
}
int phanso::laymau()
{
    return mau;
}
phanso phanso::tong(phanso a, phanso b)
{
    phanso kq;
    kq.tu = (a.laytu() * b.laymau())+(b.laytu()*a.laymau());//Ở đây có thể gọi phanso kqtong.tu vì phanso kqtong nằm trong phương thức tong() thuộc phương thức thành viên của lớp phanso. Ghi chú thêm: Chỉ những phương thức thuộc lớp phanso mới có thể truy cập và thay đổi thuộc tính riêng tư tu,mau của lớp phanso. Ví dụ class phuoc gồm private: mat, mui, tay, chan. public: an(),ngu(). Để định nghĩa hàm phuoc ngu() thì phuoc p; p.mat = nham, mat chỉ được truy cập hoặc sửa đổi khi dùng đến phương thức an() ngu() trong class phuoc. Ở đây dùng p.mat được là vì p.mat nằm trong phương thức ngu() là phương thức thành viên của lớp phuoc, có quyền truy cập và thay đổi thuộc tính riêng tư là mat.
    kq.mau = (a.laymau()*b.laymau());
    return kq;
}
phanso phanso::hieu(phanso a, phanso b)
{
    phanso kq;
    kq.tu = (a.laytu() * b.laymau())-(b.laytu()*a.laymau());
    kq.mau = (a.laymau()*b.laymau());
    return kq;
}
phanso phanso::tich(phanso a, phanso b)
{
    phanso kq;
    kq.tu = a.laytu()*b.laytu();
    kq.mau = a.laymau()*b.laymau();
    return kq;
}
phanso phanso::thuong(phanso a, phanso b)
{
    phanso kq;
    kq.tu = a.laytu()*b.laymau();
    kq.mau = b.laytu()*a.laymau();
    return kq;
}
int phanso::ucln(phanso kq)
{
    while (kq.mau != 0)
    {
        int temp = kq.mau;
        kq.mau = kq.tu%kq.mau;
        kq.tu = temp;
    }
    return kq.tu;
}
void phanso::rutgon(phanso &kq)
{
    int ucl = kq.ucln(kq);
    kq.tu = kq.tu/ucl;
    if (kq.tu==0)
        kq.mau = kq.mau;
    else
        kq.mau = kq.mau/ucl;
}
void phanso::xuat()
{
    cout << tu << "/" << mau <<  " = " << (float)tu/mau << endl;
}
