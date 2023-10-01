#include<bits/stdc++.h>
using namespace std;

class Base
{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    Base()
    {
        cout<<"Base class default constructor called\n";
    }
    Base(int x)
    {
        cout<<"BAse class param called "<<x<<endl;
    }
};
class Derived:public Base
{   
    public:

    Derived()
    {
        cout<<"Derived default called\n";
    }
    Derived(int x)
    {   
        cout<<" derived param called "<<x<<endl;
    }


};
int main()
{   
    Derived d;
    d.b=10;
    cout<<d.b;
 return 0;
}