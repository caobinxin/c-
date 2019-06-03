#include <iostream>
#include "Singelton.h"

int main(int argc, char const *argv[])
{
    printf("\n") ;

    Singelton *p1 = Singelton::getInstance();
    Singelton *p2 = Singelton::getInstance();

    if(p1 == p2){
        std::cout << "是同一个对象" << std::endl;
    }else{
        std::cout << "不是同一个对象" << std::endl;
    }

    Singelton::freeInstance();

    system("sleep 2s");//这个是通过shell来执行的
    return 0;
}
