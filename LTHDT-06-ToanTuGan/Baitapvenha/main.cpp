#include <iostream>

using namespace std;
class phanso//Tại sao class phanso; không ở khối khai báo? Vì nó là lớp toàn cục. Tức khai báo bên ngoài các hàm, bên trong các hàm đều có thể sử dụng được. Ví dụ khai báo class phanso toàn cục. Trong hàm main có thể gọi lại phanso a được.
{
private:
    int tu;
    int mau;
public:
    friend istream& operator >> (istream&,phanso&);//Toán tử nhập operator >>, đầu vào thay đổi lớp istream, thay đổi lớp phanso. Đầu ra trả về cin sau khi đã thay đổi thuộc lớp istream. Hàm bạn vì lớp istream và lớp phanso là hai lớp khác nhau. Nên toán tử vào operator >> không phải là hàm thành viên của lớp phanso. Nếu muốn truy cập, thay đổi thuộc tính private lớp phanso thì cần phải gọi hàm bạn trong class phân số. Một hàm bạn được phép truy cập, thay đổi lớp phanso.
    friend ostream& operator << (ostream&,phanso);
    phanso operator = (phanso);
};
class ngay
{
private:
    int ng;
    int th;
    int nm;
public:
    friend istream& operator >> (istream&,ngay&);//Toán tử nhập operator >> không phải là phương thức thành viên của class ngay vì hoạt động ở hai lớp khác nhau là lớp istream và lớp phanso. Vì không phải là phương thức thành viên nên không có quyền truy cập vào thuộc tính riêng tư ng, th, nm của class ngay. Vì vậy để truy cập được vào thuộc tính riêng tư ng, th, nm trong class ngay thì ở đây cần gọi hàm bạn (friend) trong class ngay. Hàm bạn có quyền truy cập, thay đổi thông tin thuộc tính đối tượng của class ngay.
    friend ostream& operator << (ostream&,ngay);
    ngay operator = (ngay);
};
class thoigian
{
private:
    int gio;
    int phut;
    int giay;
public:
    friend istream& operator >> (istream&, thoigian&);// Toán tử operator >>. Đầu vào istream& thay đổi cin, thay đổi &thoigian sau khi nhập gio,phut,giay. Đầu ra tham biến istream& để có thể nối các lệnh nhập ví dụ như cin >> a >> b >> c(Nếu không có tham biến istream& thì không thể nối lệnh nhập, chỉ cin >> a. b,c không cin được). Hàm bạn(friend) vì hàm này hoạt động ở cả 2 lớp, lớp istream và lớp thoigian. Vì vậy hàm toán tử nhập operator >>  không phải là phương thức thành viên của lớp thoigian. Không có quyền truy cập, thay đổi thuộc tính private gio,phut, giay của lớp thoigian. Vì vậy, khi cin >> gio >> phut >> giay sẽ không thay đổi giá trị gio phut giay đã nhập được. Vì vậy ở đây cần một hàm bạn cho phương thức operator >> trong class thời gian. Hàm bạn có quyền truy cập thay đổi thuộc tính private gio,phut,giay của class thoigian.
    friend ostream& operator << (ostream&,thoigian);
    thoigian operator = (thoigian);
};
int main()
{
    phanso a,b;
    cin >> a;
    cout << "Phan so a: " << a << endl;
    b = a;
    cout << "Phan so b: " << b << endl;
    ngay c,d;
    cin >> c;
    cout << "Ngay so c: " << c << endl;
    d = c;
    cout << "Ngay so d: " << d << endl;
    thoigian e,f;
    cin >> e;
    cout << "Thoi gian so e: " << e << endl;
    f = e;
    cout << "Thoi gian so f: " << f << endl;
    return 0;
}
istream& operator >> (istream& cin,phanso& a)
{
    cout << "Nhap tu: ";
    cin >> a.tu;
    cout << "Nhap mau: ";
    cin >> a.mau;
    return cin;
}
ostream& operator << (ostream& cout,phanso a)
{
    cout << a.tu << " / " << a.mau;
    return cout;
}
phanso phanso::operator = (phanso x)// Toán tử gán operator = là phương thức thành viên của class phanso vì hoạt động trong cùng một lớp. Sao chép dữ liệu từ đối tượng này sang đối tượng khác trong cùng một lớp.
{
    tu = x.tu;
    mau = x.mau;
    return *this;//Return this trả về con trỏ thuộc class phanso. Con trỏ lúc này lấy giá trị = địa chỉ (0x61fd50). Vì vậy cần lấy giá trị chính xác của nó không phải địa chỉ, giá trị chính xác gồm họ tên, điểm toán, điểm văn, điểm trung bình.
    // Thay vì khai báo biến temp, return temp. Thay vào đó dùng return *this. Để đỡ mất công phải tạo thêm 1 biến temp lưu giữ giá trị tạm.
}
istream& operator >> (istream& cin, ngay& x)// Có &istream thì mới cin >> x.ng >> x.th >> x.nm; được.
{
    cout << "Nhap ngay: ";
    cin >> x.ng;
    cout << "Nhap thang: ";
    cin >> x.th;
    cout << "Nhap nam: ";
    cin >> x.nm;
    return cin;
}
ostream& operator << (ostream& cout,ngay x)//Có &ostream thì mới cout << x.ng << x.th << x.nm được. Nếu không thì chỉ cout << x.ng thôi.
{
    cout << x.ng << "/" << x.th << "/" << x.nm;
    return cout;
}
ngay ngay::operator = (ngay x)
{
    ng = x.ng;
    th = x.th;
    nm = x.nm;
    return *this;
}
istream& operator >> (istream& cin, thoigian &x)
{
    cout << "Nhap gio: ";
    cin >> x.gio;
    cout << "Nhap phut: ";
    cin >> x.phut;
    cout << "Nhap giay: ";
    cin >> x.giay;
    return cin;
}
ostream& operator << (ostream& cout, thoigian x)
{
    cout << x.gio << " gio " << x.phut << " phut " << x.giay << " giay ";
    return cout;
}
thoigian thoigian::operator = (thoigian x)
{
    gio = x.gio;
    phut = x.phut;
    giay = x.giay;
    return *this;
}
//KẾT LUẬN:
//- Tại sao class phanso; không ở khối khai báo? Vì nó là lớp toàn cục. Tức khai báo bên ngoài các hàm, bên trong các hàm đều có thể sử dụng được. Ví dụ khai báo class phanso toàn cục. Trong hàm main có thể gọi lại phanso a được.
//Nếu để
//class phanso;
//int main()
//{
//    cout << "Hello world!" << endl;
//    return 0;
//}
//class phanso
//{
//private:
//    int tu;
//    int mau;
//public:
//    nhap();
//    xuat();
//};
//Thì ở đây ở dưới khối định nghĩa hàm(bên dưới hàm main()). Ta đã có thêm khối khai báo là nhap();, xuat();. Và ta cần xuống nữa để định nghĩa hàm nhap(), xuat(). Theo trình tự đúng là khối khai báo > khối hàm main > khối định nghĩa hàm. Còn đây thì sẽ thành khối khai báo > khối hàm main > khối định nghĩa hàm > khối khai báo > khối định nghĩa hàm.
//- Tại sao phải cần tham chiếu istream& trong toán tử nhập. Vì sẽ không thể nối chuỗi các lệnh nhập với nhau bằng cách sử dụng toán tử >>.
//Ví dụ về nối chuỗi các lệnh nhập:
//Vậy nếu tôi không có tham chiếu &istream thì theo như bên dưới
//    1 cout << "Nhap ngay: ";
//    2 cin >> x.ng;
//    3 cout << "Nhap thang: ";
//    4 cin >> x.th;
//    5 cout << "Nhap nam: ";
//    6 cin >> x.nm;
//    //1,2,3,4,5,6 = cin >> x.ng >> x.th >> x.nm;
//Tôi chỉ nhập được x.ngay. Còn lại x.th và x.nm không nhập được phải không?
//Đúng, nếu bạn không trả về tham chiếu istream& từ toán tử nhập cho lớp ngay, thì khi sử dụng nối chuỗi các lệnh nhập như bạn đã nêu, chỉ có biến ng trong x sẽ nhận được giá trị từ cin, còn th và nm không nhận được giá trị nào và giữ nguyên giá trị mặc định của chúng.
//- Toán tử nhập operator >> không phải là phương thức thành viên của class ngay vì hoạt động ở hai lớp khác nhau là lớp istream và lớp phanso. Vì không phải là phương thức thành viên nên không có quyền truy cập vào thuộc tính riêng tư ng, th, nm của class ngay. Vì vậy để truy cập được vào thuộc tính riêng tư ng, th, nm trong class ngay thì ở đây cần gọi hàm bạn (friend) trong class ngay. Hàm bạn có quyền truy cập, thay đổi thông tin thuộc tính đối tượng của class ngay.
//- Toán tử gán operator = là phương thức thành viên của class phanso vì hoạt động trong cùng một lớp. Sao chép dữ liệu từ đối tượng này sang đối tượng khác trong cùng một lớp.
