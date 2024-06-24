#include <iostream>

using namespace std;
//Toán tử gán: dùng để gán thuộc tính đối tượng a cho đối tượng b trong con trỏ. Vì trong con trỏ nếu gán a = b, thì chỉ gán địa chỉ, không gán được giá trị.
class hocsinh
{
private:
    string hoten;
    int toan;
    int van;
    float diemtrungbinh;
public:
    hocsinh();
    ~hocsinh();//Phá hủy.
    hocsinh(string hoten, int toan, int van);//Nhập
    friend ostream& operator << (ostream&, hocsinh&);// Toán tử xuất operator << không phải là phương thức thành viên của lớp vì nó hoạt động ở hai lớp khác nhau. Lớp xuất ostream để xuất dữ liệu đầu ra từ một đối tượng lớp hocsinh.
    hocsinh operator = (hocsinh&);//Toán tử gán operator = là phương thức thành viên của lớp bởi vì hoạt động ở cùng một lớp, sao chép dữ liệu từ đối tượng này sang đối tượng khác trong cùng một lớp. Ví dụ có class hocsinh{diemtoan,diemvan}; Phương thức thành viên để lấy biến private diemtoan nguyenvana, gán cho biến private diemtoan của nguyenvanb.
};
int main()
{
    hocsinh a("Ho Thanh Phuoc",9,8);
    cout << a;
    hocsinh b;
    b = a;
    cout << b;
    return 0;
}
hocsinh::hocsinh()
{
    hoten = "none";
    toan = 0;
    van = 0;
    diemtrungbinh = 0;
}
hocsinh::~hocsinh()
{

}
hocsinh::hocsinh(string ht, int to, int va)
{
    hoten = ht;
    toan = to;
    van = va;
    diemtrungbinh = (float)(to+va)/2;
}
ostream &operator << (ostream &cout, hocsinh &hs)
{
    cout << "Ten: " << hs.hoten << endl;
    cout << "Diem van: " << hs.toan << endl;
    cout << "Diem toan: " << hs.van << endl;
    cout << "Diem trung binh: " << hs.diemtrungbinh << endl;
    return cout;
}
hocsinh hocsinh:: operator=(hocsinh &a)
{
    hoten = a.hoten;
    toan = a.toan;
    van = a.van;
    diemtrungbinh = (float)(a.toan+a.van)/2;
    return *this;//Tại sao chỗ này return *this?. Tại vì this là con trỏ, trỏ đến đối tượng hocsinh. Tuy nhiên nếu để this không thì sẽ trả về địa chỉ ô nhớ (0x61fd50) lưu trữ giá trị của con trỏ, không trả về giá trị con trỏ. Vì vậy, cần trả về giá trị thì dùng *this.
    //this là con trỏ trỏ đến đối tượng đó.
    //*this: * là vào vùng nhớ lấy giá trị mà đối tượng con trỏ đang trỏ tới.
    //Giá trị của một biến con trỏ là địa chỉ ô nhớ.

}

//KẾT LUẬN
//- Toán tử gán dùng để gán thuộc tính đối tượng a cho đối tượng b trong con trỏ. Vì trong con trỏ nếu gán a = b, thì chỉ gán địa chỉ, không gán được giá trị.
//- Toán tử xuất operator << không phải là phương thức thành viên của lớp vì nó hoạt động ở hai lớp khác nhau. Lớp xuất ostream để xuất dữ liệu đầu ra từ một đối tượng lớp hocsinh.
//- Toán tử gán operator = là phương thức thành viên của lớp bởi vì hoạt động ở cùng một lớp, sao chép dữ liệu từ đối tượng này sang đối tượng khác trong cùng một lớp. Ví dụ có class hocsinh{diemtoan,diemvan}; Phương thức thành viên để lấy biến private diemtoan nguyenvana, gán cho biến private diemtoan của nguyenvanb.
//- Tại sao chỗ này return *this?. Tại vì this là con trỏ, trỏ đến đối tượng hocsinh. Tuy nhiên nếu để this không thì sẽ trả về địa chỉ ô nhớ (0x61fd50) lưu trữ giá trị của con trỏ, không trả về giá trị con trỏ. Vì vậy, cần trả về giá trị thì dùng *this.
//- Nếu không return *this. Toán tử gán sẽ trông như sau.
//    hocsinh hocsinh::operator=(hocsinh &a)
//    hocsinh temp;
//    temp.hoten = a.hoten;
//    temp.toan = a.toan;
//    temp.van = a.van;
//    temp.diemtrungbinh = (float)(a.toan + a.van) / 2;
//    return temp;
//    Việc này sẽ tạo thêm một biến temp để gán. Thông thường return *this gán a = b. Nếu return temp; temp = b; a = temp. Vì vậy ở đây sẽ có tổng cộng 3 biến được gán gây tốn tài nguyên.
