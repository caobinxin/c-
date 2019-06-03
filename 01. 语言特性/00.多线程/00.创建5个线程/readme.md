创建线程

下面的程序，我们可以用它来创建一个 POSIX 线程：

#include <pthread.h>
pthread_create (thread, attr, start_routine, arg) 

在这里，pthread_create 创建一个新的线程，并让它可执行。下面是关于参数的说明：
参数 	描述
thread 	指向线程标识符指针。
attr 	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
start_routine 	线程运行函数起始地址，一旦线程被创建就会执行。
arg 	运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。

创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。
终止线程

使用下面的程序，我们可以用它来终止一个 POSIX 线程：

#include <pthread.h>
pthread_exit (status) 

在这里，pthread_exit 用于显式地退出一个线程。通常情况下，pthread_exit() 函数是在线程完成工作后无需继续存在时被调用。

如果 main() 是在它所创建的线程之前结束，并通过 pthread_exit() 退出，那么其他线程将继续执行。否则，它们将在 main() 结束时自动被终止。