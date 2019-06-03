// C++ STL 之 vector 的 capacity 和 size 属性区别

// size 是当前 vector 容器真实占用的大小，也就是容器当前拥有多少个容器。

// capacity 是指在发生 realloc 前能允许的最大元素数，即预分配的内存空间。

// 当然，这两个属性分别对应两个方法：resize() 和 reserve()。

// 使用 resize() 容器内的对象内存空间是真正存在的。

// 使用 reserve() 仅仅只是修改了 capacity 的值，容器内的对象并没有真实的内存空间(空间是"野"的)。

// 此时切记使用 [] 操作符访问容器内的对象，很可能出现数组越界的问题。

#include <iostream>
#include <vector>

using std::vector;
int main(void)
{
    vector<int> v;
    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
    v.reserve(10);//这里相当于，设置了 每次alloc 增长的空间
    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;
    v.resize(1);

    v.push_back(1);
    v.push_back(2);
    std::cout<<"v.size() == " << v.size() << " v.capacity() = " << v.capacity() << std::endl;

    //下面的操作暂时是对的， 但是很容易出现 数据越界的问题
    for(int i = 0; i < v.capacity(); i++){
        std::cout << "v.value = " << v[i] << std::endl;
    }

    //正确的做法
    for(int i = 0; i < v.size(); i++){
        std::cout << "v.value = " << v[i] << std::endl;
    }

    return 0;
}


    // 相关引申：

    // 针对 capacity 这个属性，STL 中的其他容器，如 list map set deque，由于这些容器的内存是散列分布的，
    // 因此不会发生类似 realloc() 的调用情况，因此我们可以认为 capacity 属性针对这些容器是没有意义的，因此设计时这些容器没有该属性。

    // 在 STL 中，拥有 capacity 属性的容器只有 vector 和 string。