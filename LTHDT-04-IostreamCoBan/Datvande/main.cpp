#include <iostream>

using namespace std;
//Nhập, xuất phân số với thư viện iostream.h: phanso a; cin>>a; cout << a;
//Hàm bạn (friend) là hàm được phép truy cập, thay đổi thành phần(thuộc tính, phương thức) đối tượng thuộc về lớp đó bất chấp thành phần được khai báo trong phạm vi nào.
//Ví dụ: friend istream &operator >> (istream &, phanso &). Hàm bạn này có thể truy cập, thay đổi thuộc tính hoặc phương thức private, protected, public của lớp phanso. Vì khai báo toán tử operator >> không phải là phương thức thành viên của lớp phân số. Phải có hàm bạn khi khai báo toán tử operator >> thì mới truy cập, thay đổi được thuộc tính riêng tư của lớp phanso.
//Tại sao phải nạp chồng toán tử. Mục đích học toán tử trong lập trình hướng đối tượng để code đơn giản hơn. Ví dụ bài toán tính tổng hiệu tích thương hai phân số: phanso a, b, tong, hieu, tich, thuong; cin >> a >> b; tong = a + b; hieu = a - b; tich = a * b; thuong = a / b; thay vì cách cũ là phanso a, b , tong, hieu, tich, thuong; a.nhap(); b.nhap(); tong = tong.kqtong(a,b);
//Nạp chồng toán tử sử dụng trong: C++, Python, C#, Swift. Không sử dụng trong Java. Mình định hướng làm trong java, nhưng cũng chưa chắc có cơ hội. Còn thời gian thì cứ học. Học cho có tư duy lập trình.
//Mình cần học không: Cần vì:
//1.Hiện tại, Nó nằm trong bài thi: Gói gọn trong 1 buổi
//2.Sau này học cao học lên sẽ học python. Có cần thì dùng.
//3.C#: Sau này nữa, không biết sau này có làm không, nhưng minh thích C# vì nó gần gũi, mình đã từng code.
class phanso
{
private:
    int tu, mau;
public:
    friend istream& operator >> (istream &, phanso &);//Toán tử nhập operator>> không phải là một phương thức thành viên của lớp phanso(ko có quyền truy cập vào thuộc tính riêng tư của lớp phanso, vì vậy nên ở đây đầu vào khai báo phanso& là không được) toán tử operator >> không thuộc về phương thức thành viên của class phanso vì toán tử operator >> thuộc về phương thức thành viên của lớp istream. Nếu cần toán tử operator >> truy cập, sửa đổi vào thuộc tính riêng tư của lớp phân số thì phải gọi nó thông qua một hàm bạn (friend).
   //B1. <ten>
   //B2. <ten> <dauvao>
   //B3. <daura> <ten> <dauvao>
   //B4. <friend> <daura> <ten> <dauvao>
   //VD:
   //B1. &operator >>
   //B2. &operator >> (istream &is, phanso &x);
   //B3. istream &operator >> (istream &is, phanso &x);
   //B4. friend istream &operator >> (istream &is, phanso &x);
    friend ostream& operator << (ostream&,phanso&); //Hàm bạn có thể truy cập và thay đổi thuộc tính, phương thức hay gọi chung là thành phần của cả 1 lớp phanso. Bởi vì toán tử operator << không phải là phương thức thành viên của class phanso.
};
int main()
{
    phanso a;
    cin >> a;
    cout << a;
    return 0;
}
istream& operator >> (istream &cin,phanso &a)//&operator >> = thay đổi toán tử >> - (istream &cin, phanso &a) = thay đổi cin, thay doi phanso a - istream = trả về lớp istream.
{
    cout << "Nhap tu: ";
    cin >> a.tu;
    cout << "Nhap mau: ";
    cin >> a.mau;
    return cin;// Trả về cin đã thay đổi thuộc lớp istream.
}
ostream& operator << (ostream &cout,phanso&a)
{
    cout << a.tu << "/" << a.mau;
    return cout;//ostream&: Thay đổi cout của lớp ostream. Thay đổi đầu vào, đầu ra.
}
//KẾT LUẬN
//- Hàm bạn (friend) là hàm được phép truy cập, thay đổi thành phần(thuộc tính, phương thức) đối tượng thuộc về lớp đó bất chấp thành phần được khai báo trong phạm vi nào.
//Ví dụ: friend istream &operator >> (istream &, phanso &). Hàm bạn này có thể truy cập, thay đổi thuộc tính hoặc phương thức private, protected, public của lớp phanso. Vì khai báo toán tử operator >> không phải là phương thức thành viên của lớp phân số. Phải có hàm bạn khi khai báo toán tử operator >> thì mới truy cập, thay đổi được thuộc tính riêng tư của lớp phanso.
//- Khai báo, định nghĩa, ý nghĩa hàm nạp chồng toán tử.
//Khai báo hàm
//Ví dụ: friend istream &operator >> (istream&,phanso&).
//B1. <ten>.
//B2. <ten> <dauvao>.
//B3. <daura> <ten> <dauvao>.
//B4. <friend> <dauvao> <ten> <daura>.
//B1. &operator >>.
//B2. &operator >> (istream&, phanso&).
//B3. istream &operator >> (istream&, phanso&).
//B4. friend istream &operator >> (istream&, phanso&).
//Định nghĩa hàm
//friend istream &operator >> (istream &cin, phanso &a).
//Ý nghĩa hàm
//B1. &operator >>: Thay đổi toán tử vào(>>) bằng tham biến &.
//B2. &operator >> (istream &cin, phanso &a): Đầu vào truyền tham biến &cin(trong hàm thay đổi biến cin thì trong lớp istream cũng thay đổi). Truyền tham biến &a(trong hàm thay đổi biến a thì trong lớp phanso cũng thay đổi).
//B3. istream &operator >> (istream &cin, phanso &a): Trả về biến cin thuộc lớp istream sau khi đã thay đổi trong thân hàm.
//{
//    ...
//    return cin;
//}
//B4.friend istream &operator >> (istream &cin, phanso &a): Vì có hàm bạn(friend). Nên thành phần của class istream, phanso sẽ được thay đổi như bên trong thân hàm. Cụ thể sẽ thay đổi cin(vì đầu vào &cin), thay đổi tu,mau phanso a(vì đầu vào &a).
//{
//    cout << "Nhap tu: ";
//    cin >> a.tu;
//    cout << "Nhap mau: ";
//    cin >> a.mau;
//    return cin;
//}
//- istream&: Truy cập, thay đổi đầu vào đầu ra của cin >> trong lớp istream.
