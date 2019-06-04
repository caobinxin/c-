基类 & 派生类

一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。定义一个派生类，我们使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名，形式如下：

class derived-class: access-specifier base-class

其中，访问修饰符 access-specifier 是 public、protected 或 private 其中的一个，base-class 是之前定义过的某个类的名称。如果未使用访问修饰符 access-specifier，则默认为 private。



访问控制和继承

派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。

我们可以根据访问权限总结出不同的访问类型，如下所示：
访问	public	protected	private
同一个类	yes	yes	yes
派生类	    yes	yes	no
外部的类	yes	no	no

**一个派生类继承了所有的基类方法，但下列情况除外：**

    基类的构造函数、析构函数和拷贝构造函数。
    基类的重载运算符。
    基类的友元函数。

继承类型

当一个类派生自基类，该基类可以被继承为 public、protected 或 private 几种类型。继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。

我们几乎不使用 protected 或 private 继承，通常使用 public 继承。当使用不同类型的继承时，遵循以下几个规则：

    公有继承（public）：当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。
    保护继承（protected）： 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。
    私有继承（private）：当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。


多继承

多继承即一个子类可以有多个父类，它继承了多个父类的特性。

C++ 类可以从多个类继承成员，语法如下：

class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
{
<派生类类体>
};

其中，访问修饰符继承方式是 public、protected 或 private 其中的一个，用来修饰每个基类，各个基类之间用逗号分隔，如上所示。现在让我们一起看看下面的实例：


# 虚拟继承 demo02.cpp

另外多继承(环状继承),A->D, B->D, C->(A，B)，例如：

class D{......};
class B: public D{......};
class A: public D{......};
class C: public B, public A{.....};

这个继承会使D创建两个对象,要解决上面问题就要用虚拟继承格式

格式：class 类名: virtual 继承方式 父类名

class D{......};
class B: virtual public D{......};
class A: virtual public D{......};
class C: public B, public A{.....};

虚继承--（在创建对象的时候会创建一个虚表）在创建父类对象的时候

A:virtual public D
B:virtual public D