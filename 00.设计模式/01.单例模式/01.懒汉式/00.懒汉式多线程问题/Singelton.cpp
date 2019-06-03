#include "Singelton.h"

using namespace std ;
Singelton::Singelton(/* args */)
{
    cout << "Singelton 构造函数 begin" << endl ;
    sleep(1000) ;
    cout << "Singelton 构造函数 end" << endl ;
}

Singelton::~Singelton()
{
    cout << "Singelton 析构函数 " << endl ;
}

Singelton* Singelton::getSingelton()
{
    if(NULL == single)
    {
        count++ ;
        single = new Singelton() ;
    }

    return single ;
}

Singelton* Singelton::releaseSingelton()
{
    if(NULL != single)
    {
        delete single ;
        single = NULL ;
    }

    return single ;
}

Singelton* Singelton::single = NULL ;
int Singelton::count = 0 ;