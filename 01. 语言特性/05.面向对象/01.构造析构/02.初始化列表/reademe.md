使用初始化列表来初始化字段

使用初始化列表来初始化字段：
Line::Line( double len): length(len)
{
    cout << "Object is being created, length = " << len << endl;
}

上面的语法等同于如下语法：
Line::Line( double len)
{
    length = len;
    cout << "Object is being created, length = " << len << endl;
}

假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化，同理地，您可以使用上面的语法，只需要在不同的字段使用逗号进行分隔，如下所示：
C::C( double a, double b, double c): X(a), Y(b), Z(c)
{
  ....
}
