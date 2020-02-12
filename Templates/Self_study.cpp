#include <iostream>
#include <string>

// template     <class id>      function_declaratiion
// template     <typename id>   function_declaration

/* Example:
*   // create template function with myType as parameter
*       template <class myType>
*       myType GetMax (myType a, myType b) {
*           return (a>b ? a:b);
*       }
*
*   // each instance of myType is replaced by the type passed as
*   // as the template parameter.  Automatically performed by compiler.
*       
*       int x,y;
*       GetMax <int> (x,y);
*/

template <class T>
T GetMax (T a, T b) {
    T result;
    result = (a>b) ? a:b;
    return (result);
}

template <class T, class U>
T GetMin (T a, U b) {
    return (a<b ? a:b);
}

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
    std::cout << z << std::endl;
}

