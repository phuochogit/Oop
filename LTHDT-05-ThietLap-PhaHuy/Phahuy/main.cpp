#include <iostream>

using namespace std;
//Phương thức phá hủy(Destructor): Thu hồi lại hết tài nguyên đã cấp phát khi đối tượng hết phạm vi hoạt động.
//Ví dụ: int a = 10; cout << a; ~a; int b = 20; cout << b; ~b;.
//Ví dụ: Phước làm ở DotB sẽ có drive tài nguyên DotB. Khi nghỉ làm chị Hải sẽ thu hồi lại hết tài nguyên drive của DotB cho Phước.
//Tên phương thức phá hủy: class phanso{~phanso}.
//Không có đầu vào, đầu ra.
//Tự động gọi khi đối tượng hết phạm vi sử dụng: tự động hủy drive Phuoc khi Phuoc nghỉ ở DotB.
//Nhóm phương thức xử lý bao gồm: Khởi tạo, sap chép, giải phóng tài nguyên. Ví dụ: sinh ra, bắt chước, chết đi.
//Chỉ có duy nhất một phương thức phá hủy trong một lớp. Ví dụ Phuoc làm ở DotB làm luồng(), erd(), tài liệu(), prototype(). Khi nghỉ thì gọi một phương thức phá hủy. Hủy hết drive của luồng(), erd(), tài liệu(), prototype().
//Chết một lần mà thôi.
class phanso
{
private:
    int tu;
    int mau;
public:
    phanso();//Sinh ra.
    ~phanso();//Chết đi.
};
int main()
{
    phanso a;//Sinh ra.
    //Chết đi. Tự động gọi khi phương thức hết phạm vi sử dụng.
    return 0;
}
phanso::phanso()//Là hàm thành viên của class, phanso, có quyền truy cập, thay đổi thuộc tính private của class phanso.
{
    tu = 1;
    mau = 1;
    cout << "Sinh ra." << endl;
    return;//Hiểu ngầm giá trị trả về được
}
phanso::~phanso()//Là hàm thành viên nên được phanso::phanso.
{
    cout << "Chết đi." << endl;
    // Không cần return cũng được vì theo như dòng 33. Hiểu ngầm giá trị trả về được.
}
