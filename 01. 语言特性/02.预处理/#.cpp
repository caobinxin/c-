
#include <iostream>
using namespace std;
 
#define MKSTR( x ) #x
 
int main ()
{
    cout << MKSTR(HELLO C++ CBX) << endl; // 这里将会被打印出 "HELLO C++ CBX"
 
    return 0;
}


// 让我们来看看它是如何工作的。不难理解，C++ 预处理器把下面这行：

// cout << MKSTR(HELLO C++ CBX) << endl;

// 转换成了：

// cout << "HELLO C++ CBX" << endl;