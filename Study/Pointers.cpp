#include <iostream>
#include <string>
class A
{
    public:
        A() {
            int v = 10;
            std::cout << v << " " << std::endl;
        };

};

class B : public A
{
    public:
        A* a;
        B() {
            A* a = new A;
        }
};

int main()
{
    B b;
}