#include <iostream>

using namespace std;
//- this: trả về giá trị. Ví dụ a = 123.
//- *this: trả về địa chỉ ô nhớ. Ví dụ &a = f0x15ff.
//- Mối quan hệ giữa <*> và <virtual>. Vì nếu không sử dụng * thì sẽ mặc định là lấy lớp cha (chitiet). Nếu sử dụng * thì sẽ lấy lớp con (chitietdon, chitietphuc). Ví dụ: Chitiet kq = ds[i].Timkiem() thì sẽ gọi phương thức Timkiem() ở lớp cha, và phương thức Timkiem() của lớp con sẽ không được gọi ngay cả khi phương thức Timkiem() đã được khai báo là virtual trong lớp cha. Vì vậy cần dùng chitiet *kq = ds[i].Timkiem(). Lúc này ở lớp cha phương thức virtual Timkiem() thì sẽ thực hiện Timkiem() ở bên trong cả lớp con.
//- C++: new don; Java: new don(). Java có constructor mặc định(new don()) vì trong c++ sẽ tự động tạo constructor mặc định khi tạo lớp, còn trong java phải tạo thủ công constructor mặc định khi tạo lớp. Đó là sự khác biệt về mặt cú pháp.
class chitiet
{
protected:
    string maso;
    int giatien = 0;
public:
    virtual void nhap();
    virtual chitiet* timkiemmotchitietmaytheomaso(const string);//Sử dụng dấu * chitiet* timkiemmotchitietmaytheomaso(). Vì ở dòng chitiet* kq = ct[i]->timkiemmotchitietmaytheomaso(maso); phương thức timkiemmotchitietmaytheomaso(maso) phải trả về một biến con trỏ (chitiet*) vì để gán cho biến kq cũng là một biến con trỏ (chitiet[kq]). Hai biến gán giá trị bằng nhau phải là hai biến có cùng kiểu dữ liệu. Ví dụ (int a = 5, int b = 0, a = b) là đúng vì có cùng kdl int. Trường hợp int *a = 5, int b = 0, a = b, sai vì 1 cái là địa chỉ ô nhớ a (0x1323ff) còn một cái là giá trị (b=0). Không thể gán địa chỉ = giá trị được, sẽ ra lỗi invalid conversion from ‘int’ to ‘int*’ [-fpermissive].
    virtual int tinhtienchomay();
    virtual void xuat();
};
class don:public chitiet
{
public:
    void nhap();
    chitiet* timkiemmotchitietmaytheomaso(const string);
    int tinhtienchomay();
    void xuat();
};
class phuc:public chitiet
{
private:
    int soluongchitietthanhphan;
    chitiet* danhsachchitietthanhphan[100];
public:
    void nhap();
    chitiet* timkiemmotchitietmaytheomaso(const string);
    int tinhtienchomay();
    void xuat();
};
class may
{
private:
    int n;
    chitiet* ct[100];//Sử dụng chitiet* ct[100] vì nếu không sử dụng dấu <*> cơ chế đa xạ sẽ không hoạt động. Ví dụ, chitiet* kq = ct[i]->timkiemmotchitietmaytheomaso(maso); Nếu không sử dụng * thì chitiet kq = ct[i].timkiem(). Lúc này sẽ chỉ tìm kiếm được ở lớp cha(chitiet). Không sử dụng phương thức timkiem() được ở lớp con (don,phuc), mặc dù ở lớp cha phương thức timkiem() đã có từ khóa virtual. Ngược lại nếu có dấu * tức chitiet* ct[100] và chitiet* kq = ct[i]->timkiem(). Lúc này sẽ sử dụng phương thức timkiem() được ở lớp cha và lớp con, cùng với từ khóa virtual trong phương thức timkiem() ở lớp cha.
public:
    void nhap();
    void timkiemmotchitietmaytheomaso(const string);
    void tinhtienchomay();
    void xuat();
};
int main()
{
    may abc;
    abc.nhap();
    abc.timkiemmotchitietmaytheomaso("1");
    abc.tinhtienchomay();
    abc.xuat();
    return 0;
}
void may::nhap()
{
    bool loai;
    cout << "Nhap so luong chi tiet may (toi da 100): ";
    cin >> n;
    while (n < 0 || n > 100)
    {
        cout << "Nhap so luong chi tiet may (toi da 100): ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap chi tiet don hay chi tiet phuc: 0.Chi tiet don 1.Chi tiet phuc ";
        cin >> loai;
        switch(loai)
        {
        case 0: ct[i] = new don;
            break;
        case 1: ct[i] = new phuc;
            break;
        }
        ct[i]->nhap();
    }
}
void may::timkiemmotchitietmaytheomaso(const string ms)
{
    chitiet* kq = NULL;
    for (int i = 0;i < n; i++)
    {
        kq = ct[i]->timkiemmotchitietmaytheomaso(ms);//Ở đây dùng chitiet *kq vì hai lý do. Một, nếu dùng chitiet kq = ds[i].timkiem() thì chỉ gọi được phương thức timkiem() ở lớp cha (chitiet), không gọi được phương thức timkiem() ở lớp con(don,phuc), mặc dù ở lớp cha đã có từ khóa virtual. Ngược lại, nếu gọi chitiet* kq = ds[i]->timkiem(). Sẽ thực hiện hàm timkiem() được ở lớp cha và lớp con, với từ khóa virtual timkiem() ở lớp cha. Hai, vì ct[] là kiểu dữ liệu con trỏ(chitiet* ct[100]), nên để gán được cho biến kq, thì biến kq cũng phải thuộc kiểu dữ liệu con trỏ(chitiet* kq).
        if (kq != NULL)
            break;
    }
    if (kq != NULL)
        cout << "Tim thay chi tiet may" << endl;
    if(kq == NULL)
        cout << "Khong tim thay chi tiet may" << endl;
}
void may::tinhtienchomay()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += ct[i]->tinhtienchomay();
    cout << "Tong tien cho may la: " << sum << endl;
}
void may::xuat()
{
    for (int i=0;i<n;i++)
        ct[i]->xuat();
}
void chitiet::nhap()
{

}
chitiet* chitiet::timkiemmotchitietmaytheomaso(const string ms)
{

}
int chitiet::tinhtienchomay()
{

}
void chitiet::xuat()
{

}
void don::nhap()
{
    cout << "Nhap ma so: ";
    cin >> maso;
    cout << "Nhap gia tien: ";
    cin >> giatien;
}
chitiet* don::timkiemmotchitietmaytheomaso(const string ms)
{
    if(ms==maso)
        return this;//Trả về địa chỉ.
    return NULL;
}
int don::tinhtienchomay()
{
    return giatien;
}
void don::xuat()
{
    cout << "Chi tiet don" << endl;
    cout << "Ma so: " << maso << endl;
    cout << "Gia tien: " << giatien << endl;
}
void phuc::nhap()
{
    bool loai;
    cout << "Nhap ma so: ";
    cin >> maso;
    cout << "Nhap so luong chi tiet thanh phan(toi da 100): ";
    cin >> soluongchitietthanhphan;
    while (soluongchitietthanhphan<0||soluongchitietthanhphan>100)
    {
    cout << "Nhap so luong chi tiet thanh phan(toi da 100): ";
    cin >> soluongchitietthanhphan;
    }
    for (int i = 0; i < soluongchitietthanhphan; i++)
    {
        cout << "Nhap chi tiet don hay chi tiet phuc: 0.Chi tiet don 1.Chi tiet phuc ";
        cin >> loai;
        switch(loai)
        {
        case 0: danhsachchitietthanhphan[i]= new don;
            break;
        case 1: danhsachchitietthanhphan[i]= new phuc;
            break;
        }
        danhsachchitietthanhphan[i]->nhap();
    }
}
chitiet* phuc::timkiemmotchitietmaytheomaso(const string ms)
{
    if (ms==maso)
        return this;
    for(int i = 0;i<soluongchitietthanhphan;i++)
    {
        chitiet* kq = danhsachchitietthanhphan[i]->timkiemmotchitietmaytheomaso(ms);
        if(kq!=NULL)
        return kq;
    }
    return NULL;
}
int phuc::tinhtienchomay()
{
    for(int i = 0;i<soluongchitietthanhphan;i++)
        giatien += danhsachchitietthanhphan[i]->tinhtienchomay();
    return giatien;
}
void phuc::xuat()
{
    cout << "Chi tiet phuc" << endl;
    cout << "Ma so: " << maso << endl;
    cout <<"So luong chi tiet thanh phan: " << soluongchitietthanhphan << endl;
    for(int i=0;i<soluongchitietthanhphan;i++)
        danhsachchitietthanhphan[i]->xuat();
}
