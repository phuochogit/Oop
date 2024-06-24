#include <iostream>

using namespace std;
class ngay
{
private:
    int ng;
    int th;
    int nm;
public:
    ngay();
    ngay(const ngay &);//Tại sao chỗ này lại const?
    ngay(int, int, int);
    friend ostream &operator << (ostream&, ngay&);//Hàm nạp chồng toán tử operator >> không phải là hàm thành viên của class ngay, nên không có quyền truy cập vào thuộc tính private. Vì vậy, ở đây gọi hàm bạn (friend), hàm bạn trong class có quyền truy cập vào thuộc tính private của class đó.
};
int main()
{
    ngay a;//Mặc định.
    cout << a;
    ngay b(a);//Sao chép.
//    b.ngay(a);//Không sử dụng b.ngay(a) được vì constructor được gọi tự động ngay khi khai báo đối tượng. Nếu muốn khai báo b, gọi hàm b.ngay() thì cần tạo hàm thành viên.
    cout << b;
    ngay c(30,8,2024);//Nhận tham số. Không được truyền số 08 vì trong c++ số bắt đầu từ 0 là số octal(cơ số 8). Trong octal, các chữ số chỉ từ 0 đến 7. Vì vậy ghi 08 sẽ gây ra lỗi.
    cout << c;
//    c(30,08,2024);//Không được vì constructor được gọi tự động ngay khi khai báo.
    return 0;
}
ngay::ngay()//ngay::ngay. Định nghĩa hàm thành viên của class ngay, lúc này hàm ngay() mới chính thức là hàm thành viên của class ngay, và có quyền truy cập, thay đổi thông tin của thuộc tính private ng,th,nm.
{
    ng = 1;
    th = 1;
    nm = 2024;
}
ngay::ngay(const ngay &a)
{
    ng = a.ng;
    th = a.th;
    nm = a.nm;
}
ngay::ngay(int nga, int tha, int nam)
{
    ng = nga;
    th = tha;
    nm = nam;
}
ostream &operator << (ostream &cout, ngay &abc)// Hàm operator << không phải là hàm thành viên của class ngay nên không có tầm vực ngay::ostream.
{
    cout << "Ngay: " << abc.ng << " Thang: " << abc.th << " Nam: " << abc.nm << endl;
    return cout;
}
