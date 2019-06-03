#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    int a = 1;
    while (a)
    {
        cout << "欢迎来到菜鸟教程！" << endl;
        sleep(3);
        a = 0 ;
    }
    system("ls");
    return 0;
}