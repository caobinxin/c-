class INTEGER
{
    friend void Print(const INTEGER& obj);//声明友元函数
};

void Print(const INTEGER& obj)// 不属于任何一个 类，故不用写明作用域
{
    //函数体
}

int main()
{
    INTEGER obj;
    Print(obj);//直接调用

    return 0;
}