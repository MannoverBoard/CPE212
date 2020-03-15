#include<iostream>


#include<string>
#include<new>

template<typename T>
struct Node{
    T   localData;
    Node<T> *next;

    Node(const T &data) {
        localData = data;
        next      = NULL;
    }
};

template<typename T>
class List 
{
    private:
        Node<T> *head;
        Node<T> *tail;
        Node<T> *iterator;
        
        unsigned int count;

    public:
        List();

        void addItem   (const T &data);
        void Print     ();
        bool removeItem(const T &data);
        bool isEmpty   ();


};

#include "List_impl.hpp"
