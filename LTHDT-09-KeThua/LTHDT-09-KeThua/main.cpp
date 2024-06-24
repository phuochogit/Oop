#include <iostream>

using namespace std;
//- Hiểu các loại quan hệ: 11,1n,nn, đặc biệt hóa tổng quát hóa.
//- Khái niệm quan hệ đặc biệt hóa tổng quát hóa: lớp đối tượng B là trường hợp đặc biệt của lớp đối tượng A, và lớp đối tượng A là trường hợp tổng quát của lớp đối tượng B.
//+ Ví dụ: Lớp đối tượng tam giác cân là trường hợp đặc biệt của lớp đối tượng tam giác, lớp đối tượng tam giác là trường hợp tổng quát của lớp đối tượng tam giác cân.
//+ Ví dụ: Môn lập trình hướng đối tượng là trường hợp đặc biệt của ngành hệ thống thông tin, và ngành hệ thống thông tin là trường hợp tổng quát của môn lập trình hướng đối tượng.
//+ Ví dụ: Ngành hệ thống thông tin là trường hợp đặc biệt của ngành công nghệ thông tin, và ngành công nghệ thông tin là trường hợp tổng quát của ngành hệ thống thông tin.
//+ Ví dụ: Lớp người, lớp heo là trường hợp đặc biệt của lớp động vật, và lớp động vật là trường hợp tổng quát của lớp người, lớp heo.
//+ Ví dụ: Hồ Thạnh Phước, Hồ Bảo Duyên là trường hợp đặc biệt của Hồ Văn Ban, Hồ Văn Ban là trường hợp tổng quát của Hồ Thạnh Phước, Hồ Bảo Duyên.
//- Kế thừa là gì.
//+ Thế giới thực.
//+ Lập trình hướng đối tượng với C++.
//+ Phạm vi truy xuất.
//+ Từ khóa dẫn xuất.
//- Qui tắc kế thừa trong c++
//+ Private thuộc tính, phương thức ở lớp cha, không được kế thừa thuộc tính, phương thức lớp con.
//+ Private từ khóa dẫn xuất thì tất cả biến thành private hết.
//+ Public từ khóa dẫn xuất thì giữ nguyên lại.
//- Toán tử gán: Lớp cha không thể gán cho lớp con.
//+ Ví dụ: Lớp HoThanhPhuoc = HoVanBan là sai, HoVanBan = HoThanhPhuoc là đúng.
//- A *a: *a là con trỏ giữ địa chỉ của một đối tượng thuộc về lớp a.
//Cây kế thừa
//Sơ đồ lớp
class A
{

};
class B:public A
{

};
int main()
{
    A *a;
    B *b;
    A x;
    B y;
    a = &x;
    b = &y;
    a = &y;
    x = y;
//    y = x;
//    b = &x;
    return 0;
}
