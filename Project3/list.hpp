#ifndef LIST_HPP
#define LIST_HPP

#include <new>
#include <iostream>

template<typename Type>
struct Node
{
    Type localData;
    Node<Type> *nextItem;

    Node(const Type &data)
    {
        localData = data;
        nextItem = nullptr;
    }
};

/// List must be implemented by the student
template<typename Type>
class List
{
private:
    Node<Type> *_firstNode{nullptr};
    Node<Type> *_lastNode{nullptr};

    //this is horrible, what if this thing was used in a multi-threaded
    //environment! this is no good.
    // Also if a class instance wants to iterate while iterating it will never finish!
    // this is double no good.
    mutable Node<Type> *_iteratorNode{nullptr};

    unsigned int _count{0};
public:
    List();
    ~List();
    //<MEGA RANT>
    // THIS guy does not follow rule of None/3/5
    //</MEGA RANT>

    //THIS INTERFACE DOESN'T PROVIDE FINDING. UGH what use is this class?
    void AppendItem(const Type &data);
    bool DeleteItem(const Type &data);
    unsigned int Count() const;

    Type& Front();
    Type Front() const;
    Type& Back();
    Type Back() const;

    Type* IterateItems() const;
    bool AtEnd() const;
    void ResetIterator() const;
};


#include "list_impl.hpp"


#endif // #ifndef LIST_HPP
