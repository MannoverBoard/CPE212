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

// template that allows function to take mixed datatypes
template <class T, class U>
T GetMin (T a, U b) {
    return (a<b ? a:b);
}

// Class template allowing class members to mix datatypes
template <class T>
class Keene {
    private:
        T savings;
        T checking;
        T focus;
        T health;

    public:
        // Setters
        Keene(T t);
        T   setSavings   ();
        T   setChecking  ();
        T   setFocus     ();

        // Getters
        T   getHealth   (T h);
        T   getChecking    ();
        T   getSavings     ();
        T   getFocus       ();

};
