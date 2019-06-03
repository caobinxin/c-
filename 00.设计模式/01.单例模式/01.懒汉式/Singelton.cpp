#include "Singelton.h"

Singelton::Singelton(/* args */)
{
    cout << "Singelton 构造函数执行" << endl ;
}

Singelton::~Singelton()
{
    cout << "Singelton 析构函数执行" << endl ;
}

Singelton* Singelton::getInstance()
{
    if( m_psl == NULL)
    {
        m_psl = new Singelton() ;
    }

    return m_psl ;
}

void Singelton::freeInstance()
{
    if( NULL != m_psl){
        delete m_psl ;
        m_psl = NULL ;
    }
}

Singelton* Singelton::m_psl = NULL ;