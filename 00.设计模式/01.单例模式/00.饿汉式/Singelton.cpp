#include <iostream>
#include "Singelton.h"
using namespace std;

Singelton::Singelton(/* args */)
{
    cout << "Singelton 构造函数执行" << endl;
}

Singelton::~Singelton()
{
}

Singelton* Singelton::getInstance()
{
    return m_psl;
}

void Singelton::freeInstance()
{
    if( NULL != m_psl){
        delete m_psl;
        m_psl = NULL;
    }
}

Singelton *Singelton::m_psl = new Singelton;


