有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。

    1.public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private

    2.protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private

    3.private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private

但无论哪种继承方式，上面两点都没有改变：

    1.private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；

    2.protected 成员可以被派生类访问。


**如果继承时不显示声明是 private，protected，public 继承，则默认是 private 继承，在 struct 中默认 public 继承：**

总结一下三种继承方式：
继承方式 	基类的public成员 	基类的protected成员 	基类的private成员 	继承引起的访问控制关系变化概括
public继承 	仍为public成员 	仍为protected成员 	不可见 	基类的非私有成员在子类的访问属性不变
protected继承 	变为protected成员 	变为protected成员 	不可见 	基类的非私有成员都为子类的保护成员
private继承 	变为private成员 	变为private成员 	不可见 	基类中的非私有成员都称为子类的私有成员