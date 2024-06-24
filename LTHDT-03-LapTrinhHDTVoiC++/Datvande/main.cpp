#include <iostream>

using namespace std;
//Tại sao không gọi là hàm mà lại gọi là phương thức?. 1.Hàm không gắn liền với đối tượng nào, hàm thường không có quyền truy cập trực tiếp vào thuộc tính của đối tượng, trừ khi hàm được truyền đối tượng đó là tham số. Ví dụ hàm main() int a,b,tong. hàm void Ctong() tong = a+b thì lúc này ko được vì ko có quyền truy cập vào thuộc tính a,b,tong trong hàm main(). Trừ khi sử dụng void Ctong (int a, int b, int &tong). Hàm main () Ctong(a,b,tong). Lúc này hàm  Ctong() mới có quyền truy cập và thay đổi thuộc tính a,b tong trong hàm main(). Phương thức là các hàm liên kết với các đối tượng trong cùng một lớp. Phương thức có thể truy cập và thay đổi thuộc tính của lớp. Ví dụ trong lớp phanso. Phương thức rutgon() có thể thay đổi thuộc tính tu, mau của đối tượng phanso.
class hocsinh//Lớp đối tượng.
{
private://Thành phần dữ liệu.
    string hoten;
    float diemtoan,diemvan,diemtrungbinh;
public://Thành phần xử lý.
    void nhap();//Phương thức.
    void tinhdiemtrungbinh();
    void xuat();
//Chỉ phương thức mới có thể truy cập, thay đổi thuộc tính private trong cùng một lớp. Vì ví dụ nhập đối tượng Hocsinh phuoc, thao. private: hoten, sothich; public: an(), hoc(), choi(). Thì private là hoten và sothich của phuoc và thao riêng. Có chung là thao va phuoc đều có an(), hoc(), choi(). Chỉ phương thức choi() của thảo mới thay đổi được thuộc tính là sở thích của đối tượng hocsinh thao.
}
public:
    void nhap();
    void tinhdiemtrungbinh();
    void xuat();
};
int main()
{
    hocsinh a;//Đối tượng a.
    a.nhap();//Đối tượng hành động.
    a.tinhdiemtrungbinh();
    a.xuat();
    return 0;
}
void hocsinh::nhap()
{
    cout << "Nhap ho ten: ";
    cin >> hoten;
    cout << "Nhap diem toan: ";
    cin >> diemtoan;
    cout << "Nhap diem van: ";
    cin >> diemvan;
}
void hocsinh::tinhdiemtrungbinh()
{
    diemtrungbinh = (diemvan+diemtoan)/2;
}
void hocsinh::xuat()
{
    cout << "Ho ten: " << hoten << endl;
    cout << "Diem toan: " << diemtoan << endl;
    cout << "Diem van: " << diemvan << endl;
    cout << "Diem trung binh: " << diemtrungbinh << endl;
}
