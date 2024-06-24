#include <iostream>

using namespace std;
//Mục tiêu học để nắm khái niệm: Làm bài tập khi có cần thì nhớ nó và áp dụng.
//Thiết lập là gì: Sinh ra. Ví dụ khi khai báo đối tượng trong hàm main() phanso a; Lúc này đối tượng sẽ được sinh ra.
//Tại sao phải thiết lập: Ép kiểu từ đối tượng này sang đối tượng khác?
//Phá hủy là gì?: Chết đi.
//Phương thức thiết lập chia làm ba nhóm: mặc định, sao chép, nhận tham số đầu vào
//Ví dụ mặc định: class dongvatcovu {private: chan dongvatcovu(){chan = "di"}}
//Ví dụ nhận tham số đầu vào: class dongvatcovu {ditrenday(dichuyen){chan = dichuyen}} hàm main() dongvatcovu connguoi; connguoi.ditrenday("di chuyển");
//Ví dụ sao chép: class dongvatcovu{private: chan, public:dongvatcovu(const dongvatcovu& connguoi {chan = connguoi.chan}}hàm main() dongvatcovu connguoi, conkhi; connguoi.ditrenday("di chuyển"), conkhi(connguoi);conkhi: có thể bắt chước con người di chuyển đi trên dây.
class phanso
{
private:
    int tu,mau;
public:
    void nhap();
    void xuat();

};
int main()
{
    phanso a,b;
    a.nhap();
    b = a;//Câu hỏi, nếu ở đây gán b = a được thì thiết lập phương thức sao chép có ý nghĩa gì? Và định nghĩa toán tử gán làm chi nữa? -> Trả lời: Đặt trường hợp có một thuộc tính là con trỏ, nếu dùng toán tử gán thì sẽ chỉ gán đến địa chỉ của thuộc tính không gán đến giá trị của thuộc tính đó nên dẫn đến nếu là con trỏ thì cần phải dùng phương thức sao chép, hoặc định nghĩa toán tử gán để gán đúng giá trị của thuộc tính không gán nhầm sang địa chỉ. Ví dụ có thuộc tính con trỏ class phanso {tu,mau}. Hàm main() phanso a, b; a.nhap(); b = a; lúc này gán b.tu = x09323ff(bằng địa chỉ con trỏ a.tu), b.mau = x0983fx(bằng địa chỉ on trỏ a.mau) Lúc này không sử dụng phương thức sao chép hoặc định nghĩa toán tử gán thì in ra kết quả sẽ bị sai. Vì vậy cần học phương thức sao chép, và định nghĩa toán tử gán để gán đúng giá trị mình mong muốn, ko gán địa chỉ.Phục vụ cho việc học ở trình độ cao hơn là con trỏ.
    a.xuat();
    b.xuat();
    return 0;
}
void phanso::nhap()
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}
void phanso::xuat()
{
    cout << tu << "/" << mau << endl;
}

