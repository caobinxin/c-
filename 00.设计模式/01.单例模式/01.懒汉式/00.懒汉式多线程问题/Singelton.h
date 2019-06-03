#include "Sleep.h"
#include <iostream>
class Singelton
{
public:
    static Singelton *getSingelton();
    static Singelton *releaseSingelton();
    static void printS();

private:
    Singelton(/* args */);
    ~Singelton();

    static Singelton* single ;
    static int count ;
};
