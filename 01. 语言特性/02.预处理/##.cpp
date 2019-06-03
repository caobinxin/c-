
#include <iostream>
using namespace std;
 
#define concat(a, b) a ## b
int main()
{
   int xy = 100;
   
   cout << concat(x, y) << endl;
   return 0;
}

// 让我们来看看它是如何工作的。不难理解，C++ 预处理器把下面这行：

// cout << concat(x, y);

// 转换成了：

// cout << xy;