#include <iostream>

using namespace std;
//- Toán tử so sánh là gì? > < >= <= == !=.
//- Tại sao lại làm toán tử so sánh.Nếu không sử dụng toán tử gán, vậy so sánh phanso a, b; a > b có được không. Không vì sẽ báo lỗi error: no match for 'operator>' (operand types are 'phanso' and 'phanso')|. Đại loại là không thể sử dụng toán tử > để so sánh class phanso với phanso.
//- Cài đặt
class phanso
{
private:
    int tu;
    int mau;
public:
    friend istream& operator >> (istream&, phanso&);
    phanso operator > (phanso);
};
int main()
{
    phanso a, b;
    cin >> a >> b;
    if(a>b)
        cout << "a > b" << endl;
    else
        cout << "a < b" << endl;
    return 0;
}
istream& operator >> (istream&cin, phanso& x)
{
    cin >> x.tu >> x.mau;
}
phanso phanso::operator > (phanso x)
{

}
