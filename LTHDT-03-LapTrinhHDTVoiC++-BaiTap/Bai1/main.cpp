#include <iostream>

using namespace std;
//Lập trình hướng đối tượng bao gồm thuộc tính và phương thức. Ví dụ đối tượng con người: gồm thuộc tính mắt mũi tay chân. Phương thức ăn ngủ ỉa.
class phanso// Không sử dụng như khối khai báo, sử dụng như là lớp cục bộ. Được gọi bên ngoài tất cả các hàm và bên trong tất cả các hàm đều có thể sử dụng được. Ví dụ bên trong hàm main có thể gọi được class phanso.
{
private://Tại sao private. Chỉ có các phương thức bên trong lớp phanso mới có thể truy cập và thay đổi giá trị của tu,mau.Ví dụ chỉ có phương thức nhap() trong class phanso mới thay đổi được giá trị của tu,mau. Nếu trong hàm main khai báo phanso a, cin >> a.tu thì sẽ báo lỗi error: 'float phanso::tu' is private within this context|. Vì tu,mau chỉ được nhập trong phuong thuc nhap() của class phân số mà thôi. Nếu chỗ này khai báo public: thì trong hàm main khi khai báo phanso a. cin >> a.tu; cout << a.tu. Thì biến tu sẽ được truy cập và thay đổi trực tiếp trong hàm main luôn. Và sẽ xuất ra kết quả. Ví dụ nhập cin >> a.tu = 1, xuất a.tu = 1.
    float tu,mau;
public://Tại sao public. Có thể truy cập từ bất kỳ đâu trong chương trình. Ví dụ trong hàm main có thể gọi hàm nhap() bằng cách khai báo phanso a, a.nhap(). Nếu chỗ này private: thì khi ra hàm main khai báo a.nhap() thì sẽ báo lỗi error: 'void phanso::nhap()' is private within this context|. Vì hàm nhap() lúc này chỉ có phạm vi trong class phanso mà thôi. Vì vậy kéo theo cũng sẽ không thay đổi được thuộc tính tu,mau nếu thuộc tính và phương thức đều là private hết. Tuy nhiên, có 3 trường hợp ngoại lệ khi muốn sử dụng private cho phương thức.1.Điều kiện đặc biệt cho đối tượng nội tại. 2.Lớp chỉ dùng để kế thừa (abstract class). 3.Tối ưu hóa hiệu suất. ChatGPT.
    void nhap ();//Chỗ này không có dấu nhap (&phanso) vì trong hàm main a.nhap(). Hết.
    void xuly ();
};
//Class phanso, private: thuộc tính, public: phương thức. Vì mục đích chỉ những phương thức trong class phanso mới có thể truy cập và thay đổi thuộc tính tu,mau.
int main()
{
    phanso a;
    a.nhap();
    a.xuly();
    return 0;
}
void phanso::nhap()//<đầu ra> <tên lớp>::<tên phương thức của lớp>(<đầu vào>)
{
    cout << "Nhap tu: ";
    cin >> tu;
    cout << "Nhap mau: ";
    cin >> mau;
}
void phanso::xuly ()
{
    if ((tu/mau) < 0)
        cout << "Phan so " << tu << "/" << mau << " la phan so am";
    if ((tu/mau) > 0)
        cout << "Phan so " << tu << "/" << mau << " la phan so duong";
    if ((tu/mau) == 0)
        cout << "Phan so " << tu << "/" << mau << " la phan so bang khong";
}
//Kết luận:
//Bài này cần nắm hai ý:
//1. Mô tả:
//private:
//    float tu,mau;
//public:
//    void nhap();
//    void xuly();
//Vì chỉ phương thức nhap(), xuly() trong class phanso mới có thể truy cập và thay đổi thuộc tính tu,mau.
//2. Mô tả
//void phanso::nhap()
//<đầu ra> <tên lớp>::<tên phương thức của lớp>(<đầu vào>)
//B1. <tên lớp>
//B2. <tên lớp>::<tên phương thức của lớp>
//B3. <tên lớp>::<tên phương thức của lớp>(<đầu vào>)
//B4. <đầu ra> <tên lớp>::<tên phương thức của lớp>(<đầu vào>)
//VD:
//B1. phanso
//B2. phanso::nhap()
//B3. phanso::nhap(<đầu vào>)
//B4. <đầu ra> phanso::nhap(<đầu vào>)
