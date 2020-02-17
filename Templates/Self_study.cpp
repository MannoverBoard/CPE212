#include "Self_study.hpp"

int main() {
    int     i = 5,      j = 6,      k;
    long    l = 10,     m = 5,      n;
    int                             z;

    //k = GetMax<int> (i,j);
    //n = GetMax<long>(l,m);
    k = GetMax(i,j);
    n = GetMax(l,m);

    // using brackets is unecessary as compiler automatically
    // chooses what type to cast result as.

    std::cout << k << std::endl;
    std::cout << n << "\n\n";

    z = GetMin(i,l);
    z = GetMin<int,long>(i,l);
    std::cout << z << std::endl;

    int *ptr = &i;
    ptr;
    &ptr;
    *ptr;

}

