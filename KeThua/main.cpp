#include <iostream>

using namespace std;
class A
{
public:
    virtual void Sketchy()
    {
        cout << "A's Skectchy()" << endl;
        Sketchy(-1);
    }
    virtual void Sketchy(int num)
    {
        cout << "A's Skectchy(int) " << num << endl;
    }
};
class B: public A
{
public:
    void Sketchy()
    {
        cout << "B's Sketchy()";
        Sketchy(-2);
    }
    void Sketchy(int num)
    {
        cout << "B's Sketchy(int) " << num << endl;
    }
};
class C:public B
{
public:
    void Sketchy(int num)
    {
        cout << "C's Sketchy(int) " << num;
    }
};
void Curious (A* wacky)
{
    wacky ->Sketchy();
    ((C*)wacky)->Sketchy(123);
}
int main()
{
    A* inky = new B;
    inky->Sketchy();
    Curious(inky);
    return 0;
}
