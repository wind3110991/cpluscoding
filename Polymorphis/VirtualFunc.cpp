#include<iostream>  
using namespace std;  
  
class A  
{  
public:  
    void foo()  
    {  
        printf("1\n");  
    }  
    virtual void fun()  
    {  
        printf("2\n");  
    }  
};  

class B : public A  
{  
public:  
    void foo()  //隐藏：派生类的函数屏蔽了与其同名的基类函数
    {  
        printf("3\n");  
    }  
    void fun()  //多态、覆盖
    {  
        printf("4\n");  
    }  
};  

int main(void)  
{  
    A a;  
    B b;  
    A *p = &a;  

    p->foo();  //输出1
    p->fun();  //输出2

    p = &b;  
    p->foo();  //取决于指针类型，输出1
    p->fun();  //取决于对象类型，输出4，体现了多态
    return 0;  
}
