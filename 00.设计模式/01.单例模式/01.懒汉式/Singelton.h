#include <iostream>
using namespace std;

class Singelton
{
private:
    /* data */
public:
    static Singelton *getInstance() ;
    static void freeInstance() ;
private:
    static Singelton *m_psl ;
    Singelton(/* args */) ;
    ~Singelton() ;
    
};

