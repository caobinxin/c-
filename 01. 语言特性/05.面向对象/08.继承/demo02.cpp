#include <iostream>

using namespace std;
//基类

class D
{
public:
    D(){cout<<"D()"<<endl;}
    ~D(){cout<<"~D()"<<endl;}
protected:
    int d;
};

class B:virtual public D // 如果把 virtual去掉就会有两个D 同时被生成
{
public:
    B(){cout<<"B()"<<endl;}
    ~B(){cout<<"~B()"<<endl;}
protected:
    int b;
};

class A:virtual public D // 如果把 virtual去掉就会有两个D 同时被生成
{
public:
    A(){cout<<"A()"<<endl;}
    ~A(){cout<<"~A()"<<endl;}
protected:
    int a;
};

class C:public A, public B
{
public:
    C(){cout<<"C()"<<endl;}
    ~C(){cout<<"~C()"<<endl;}
protected:
    int c;
};

int main()
{
    cout << "Hello World!" << endl;
    C c;   //D, B, A ,C
    cout<<sizeof(c)<<endl;
    return 0;
}