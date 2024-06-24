#include <iostream>
#include <string>

using namespace std;
class nhanvien
{
protected:
    string hoten;
    string ngaysinh;
    int luong;
    int luongcoban = 3000000;
public:
    virtual void nhap();
    virtual void tinhluong();//virtual để xác định tính lương cho nhân viên nào, nhanvienvanphong, nhanvienquanly, nhanviensanxuat. Nếu không có virtual thì mặc định sẽ tính lương cho lớp nhanvien(lớp cơ sở).
    virtual void xuat();//virtual để xác định xuất thông tin nhân viên ăn phòng, quản lý hay sản xuất. Nếu không có virtual thì sẽ mặc định xuất lớp nhaanvien lớp cơ sở.
    int layluong();//Ko cần virtual vì thuộc  tính luong là thuộc tính của lớp cơ sở(nhân viên), và được kế thừa bởi các lớp dẫn xuất (nhanvienvanphong,nhanvienquanly,nhanviensanxuat). Vì vậy nên khi gọi phương thức public layluong(), cùng với từ khóa dẫn xuất là public ở lớp dẫn xuất (nhanvienvanphong,nhanvienquanly,nhanviensanxuat) có thể kế thừa, sử dụng phương thức layten() của lớp cơ sở(nhanvien).
    string layten();//Ko cần virtual vì class nhanvienvanphong,nhanvienquanly,nhanviensanxuat có thể kế thừa phương thức layten() để dùng cho mỗi lớp (nhanvienvanphong, nhanviensanxuat, nhanvienquanly). Vì phạm vi phương thức là public và từ khóa dẫn xuất là public.
    virtual int laysongaylamviec();//Đây là lí do vì sao gọi là hàm ảo, vì tạo hàm ảo laysongaylamviec() để lấy biến songaylamviec. Biến songaylamviec không có trong class nhanvien, có trong class nhanvienvanphong. Thông qua một phương thức ảo từ lớp cơ sở(nhanvien) để lấy thuộc tính từ phương thức thật của lớp dẫn xuất(nhanvienvanphong).
};
class nhanvienvanphong:public nhanvien
{
private:
    int songaylamviec;
    int trocap;
public:
    void nhap();
    void tinhluong();
    void xuat();
    int timkiemtheosongaylamviec(int);
    int laysongaylamviec();
};
class nhanvienquanly:public nhanvien
{
private:
    int hesochucvu;
    int thuong;
public:
    void nhap();
    void tinhluong();
    void xuat();
};
class nhanviensanxuat:public nhanvien
{
private:
    int sosanpham;
public:
    void nhap();
    void tinhluong();
    void xuat();
};
class congty
{
private://Để private cũng được vì chỉ dùng ở phương thức thuộc class congty().
    int n;
    nhanvien *nv[100];//Đa xạ là cơ chế thực hiện thông qua con trỏ đối tượng. Vì để xác định nhập vào thuộc loại nhân viên nào. Nhân viên văn phòng, nhân viên quản lý, hay nhân viên sản xuất. Xác định thông qua hàm ảo (virtual). Hàm ảo dùng để nếu gọi lớp nhanvienvanphong sẽ ra lớp nhanvienvanphong. Nếu không có hàm ảo thì gọi lớp nhanvienvanphong(lớp dẫn xuất) thì nó sẽ ra lớp nhanvien(lớp cơ sở). Con trỏ dùng để trỏ vào lớp cần gọi (nhanvienvanphong). Nếu không có con trỏ c++ hiểu sẽ gọi lớp nhanvien.
public:
    void nhap();
    void tinhluong();//Chạy vòng for để tính lương cho nhân viên từ i = 0 đến n.
    void xuat();//Chạy vòng for để xuất thông tin các nhân viên từ i = 0 đến n.
    void tongluong();//Chạy vòng for để tính tổng lương của tất cả nhân viên trong công ty.
    void timkiemtheohoten(string);
    void timkiemtheosongaylamviec(int);
};
int main()
{
    congty abc;
    abc.nhap();
    abc.tinhluong();
    abc.xuat();
    abc.tongluong();
    abc.timkiemtheohoten("a");
    abc.timkiemtheosongaylamviec(21);
    return 0;
}
void congty::nhap()
{
    int loai;
    cout << "Nhap so luong nhan vien (toi da 100 nhan vien): ";
    cin >> n;
    while ( (n < 0) || (n > 100))
    {
        cout << "Nhap so luong nhan vien (toi da 100 nhan vien): ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Chon loai nhan vien can nhap: 0.Nhanvienvanphong 1.Nhanvienquanly 2.Nhanviensanxuat: ";
        cin >> loai;
        switch(loai)
        {
            case 0: nv[i] = new nhanvienvanphong;
            break;
            case 1: nv[i] = new nhanvienquanly;
            break;
            case 2: nv[i] = new nhanviensanxuat;
            break;
        }
        nv[i]->nhap();
    }
}
void congty::tinhluong()
{
    for (int i = 0; i < n; i++)
    {
        nv[i]->tinhluong();
    }
}
void congty::xuat()
{
    for (int i = 0; i < n; i++)
    {
        nv[i]->xuat();
    }
}
void congty::tongluong()
{
    int tongluongcuacongty = 0;
    for (int i = 0; i < n; i++)
    {
        tongluongcuacongty += nv[i]->layluong();
    }
    cout << "Tong luong cua cong ty la: " << tongluongcuacongty << endl;
}
void congty::timkiemtheohoten(string hoten)
{

    bool flag = 0;//Không tìm thấy nhân viên.
    for (int i = 0; i<n ; i++)
    {
        if (hoten == nv[i]->layten())//Template operator==, ctrl + F > Find in file > operator==
        {
            flag = 1;//Tìm thấy nhân viên.
        }
    }
    if(flag == 0)
        cout << "Khong tim thay nhan vien" << endl;
    if (flag == 1)
        cout << "Tim thay nhan vien" << endl;
}
void congty::timkiemtheosongaylamviec(int songaylamviec)
{

    bool flag = 0;//Không tìm thấy nhân viên.
    for (int i = 0; i<n ; i++)
    {
        if (songaylamviec == nv[i]->laysongaylamviec())
        {
            flag = 1;//Tìm thấy nhân viên.
        }
    }
    if(flag == 0)
        cout << "Khong tim thay nhan vien" << endl;
    if (flag == 1)
        cout << "Tim thay nhan vien" << endl;
}
void nhanvien::nhap()
{

}
void nhanvien::xuat()
{

}
void nhanvien::tinhluong()
{

}
int nhanvien::layluong()
{
    return luong;
}
string nhanvien::layten()
{
    return hoten;
}
int nhanvien::laysongaylamviec()
{

}
void nhanvienvanphong::nhap()
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap ngay sinh: ";
    cin >> ngaysinh;
    cout << "Nhap so ngay lam viec: ";
    cin >> songaylamviec;
    cout << "Nhap tro cap: ";
    cin >> trocap;
}
void nhanvienvanphong::tinhluong()
{
    luong = luongcoban + (songaylamviec*100000) + trocap;
}
void nhanvienvanphong::xuat()
{
    cout << "Ho ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Luong: " << luong << endl;
    cout << "Luong co ban: " << luongcoban << endl;
    cout << "So ngay lam viec: " << songaylamviec << endl;
    cout << "Tro cap: " << trocap << endl;
}
int nhanvienvanphong::laysongaylamviec()
{
    return songaylamviec;
}
void nhanvienquanly::nhap()
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap ngay sinh: ";
    cin >> ngaysinh;
    cout << "Nhap he so chuc vu: ";
    cin >> hesochucvu;
    cout << "Nhap thuong: ";
    cin >> thuong;
}
void nhanvienquanly::tinhluong()
{
    luong = (luongcoban*hesochucvu) + thuong;
}
void nhanvienquanly::xuat()
{
    cout << "Ho ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Luong: " << luong << endl;
    cout << "Luong co ban: " << luongcoban << endl;
    cout << "He so chuc vu: " << hesochucvu << endl;
    cout << "Thuong: " << thuong << endl;
}
void nhanviensanxuat::nhap()
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap ngay sinh: ";
    cin >> ngaysinh;
    cout << "Nhap so san pham: ";
    cin >> sosanpham;
}
void nhanviensanxuat::tinhluong()
{
    luong = luongcoban + (sosanpham*2000);
}
void nhanviensanxuat::xuat()
{
    cout << "Ho ten: " << hoten << endl;
    cout << "Ngay sinh: " << ngaysinh << endl;
    cout << "Luong: " << luong << endl;
    cout << "Luong co ban: " << luongcoban << endl;
    cout << "So san pham: " << sosanpham << endl;
}

