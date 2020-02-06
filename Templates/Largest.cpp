// Pass two integers to function template, character with larger ASCII value is returned

#include <iostream>

// template function
template <class T>
T Large(T n1, T n2)
{
    return (n1 > n2) ? n1 : n2;  // ? is a conditional operator that returns
                                // one of two values depending on result of
                                // expression

}

int main()
{
    int i1, i2;
    float f1, f2;
    char c1, c2;

    std::cout << "Enter two integers:\n";
    std::cin >> i1 >> i2;
    std::cout << Large(i1, i2) << " is the larger.\n";

    std::cout <<"Enter two floating-point integers:\n";
    std::cin >> f1 >> f2;
    std::cout << Large(f1, f2) << " is the larger.\n";

    std::cout << "Enter two characters:\n";
    std::cin >> c1 >> c2;
    std::cout << Large(c1, c2) << " is the larger.\n";

    return 0;
}