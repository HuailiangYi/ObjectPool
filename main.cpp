#include <iostream>
#include "ObjectPool.h"
using namespace std;

struct BigObject
{
    BigObject() {}
    BigObject(int a) {}

    BigObject(const int &a, const int &b) {}

    void Print(const string &str)
    {
        cout << str << endl;
    }
};

void Print(shared_ptr<BigObject> p, const string &str)
{
    if (p != nullptr)
    {
        p->Print(str);
    }
    else
    {
        cout << "nullptr" << endl;
    }
}

void TestObjPool()
{
    ObjectPool<BigObject> pool;
    pool.Init(2); // 初始化对象池， 初始化创建两个对象

    {
        auto p = pool.Get();
        Print(p, "p");

        auto p2 = pool.Get();
        Print(p2, "p2");

        auto p3 = pool.Get();
        Print(p3, "p3");
    } // 出了作用域， 对象池返回的对象又会自动回收

    auto p = pool.Get();
    Print(p, "p");

    auto p2 = pool.Get();
    Print(p2, "p2");

    // 对象池支持重载构造函数
    pool.Init(2, 1);
    auto p4 = pool.Get<int>();
    Print(p4, "p4");

    pool.Init(2, 1, 2);
    auto p5 = pool.Get<int, int>();
    Print(p5, "p5");
}

int main()
{
    TestObjPool();

    return 0;
}