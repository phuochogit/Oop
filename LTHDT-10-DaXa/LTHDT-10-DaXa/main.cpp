#include <iostream>

using namespace std;
//- Cơ chế đa xạ là cơ chế thực hiện thông qua con trỏ đối tượng. Vì cho phép C++ xác định lớp thực sự của đối tượng tại thời điểm chạy và gọi đúng phiên bản của hàm ảo tương ứng trong lớp dẫn xuất.
//- Học đa xạ để đi làm.
class A
{
public:
    virtual void sketchy();
    virtual void sketchy(int);
};
class B: public A
{
public:
    void sketchy();
    void sketchy(int);
};
class C: public B
{
public:
    void sketchy(int);
};
void curious (A*);
int main()
{
    A* inky = new B;
    inky->sketchy();
    inky->sketchy(23);
    curious(inky);
    B* pinky = new C;
    pinky->sketchy();
    pinky->sketchy(46);
    curious(pinky);
    return 0;
}
void A::sketchy()
{
    cout << "\n A's Sketchy()";
    sketchy(-1);
}
void A::sketchy(int num)
{
    cout << "\n A's Sketchy (int)" << num;
}
void B::sketchy()
{
    cout<<"\n B‘s Sketchy()";
    sketchy(-2);
}
void B::sketchy(int num)
{
    cout<<"\n B's Sketchy(int)" << num;
}
void C::sketchy(int num)
{
    cout<<"\n C's Sketchy (int)" << num;
}
void curious(A* wacky)//Khai báo con trỏ *A wacky
{
    wacky -> sketchy();//wacky.sketchy();
    ((C*)wacky)->sketchy(123);//Ép kiểu này ép cho địa chỉ của con trỏ, ko ép cho giá trị của con trỏ.
}

