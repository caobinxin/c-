#include ""
#include "Singelton.h"
#include <pthread.h>
#include <iostream>
#include "Sleep.h"

using namespace std ;

int main2(int argc, char const *argv[])
{
    Singelton *s1 = Singelton::getSingelton() ;
    Singelton *s2 = Singelton::getSingelton() ;

    if( s1 == s2)
    {
        cout << "ok ... equal" << endl;
    }else{
        cout << "hello....." << endl;
    }

    system("sleep 3s") ;

    return 0;
}

void MyThreadFunc(void *)
{
    cout << "我是线程体..." << endl ;
    Singelton::getSingelton()->printS() ;
}

int main(int argc, char* argv[])
{
    //main2() ;

    HANDLE hThread[10] ;

    for(int i = 0; i < 3; i++)
    {
        hThread[i] = (HANDLE)_beginthread(MyThreadFunc, 0, NULL) ;
    }

    for(int i = 0; i < 3; i++)
    {
        WaitForSingleObject(hThread[i], INFINITE) ;
    }

    cout << "hello " << endl ;
    system("sleep 2s") ;

    return 0 ;
}