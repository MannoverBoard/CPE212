/// IMPLEMENT THE FOLLOWING FUNCTIONS

template<typename Type>
List<Type>::List()
{
    /// initialize the nodes correctly
}

template<typename Type>
List<Type>::~List()
{
    /// delete all data within the list, be sure to account for memory leaks.
}

template<typename Type>
void List<Type>::AppendItem(const Type &data)
{
    /// Append an item correctly into the list
    /// increment _count
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
    /// remove an item correctly to the list
    /// All items in this project will be equal comparable
    /// return false if the item was not removed
    /// return true if the item was removed.
    /// decrement _count if the item was removed.
}

template<typename Type>
unsigned int List<Type>::Count() const
{
    /// returns the size from _count.
}

template<typename Type>
Type& List<Type>::Front()
{
    /// returns a reference to the data in the front of the list
}

template<typename Type>
Type List<Type>::Front() const
{
    /// returns a const copy to the data in the front of the list.
}

template<typename Type>
Type& List<Type>::Back()
{
    /// returns a reference to the data in the back of the list.
}

template<typename Type>
Type List<Type>::Back() const
{
    /// returns a const copy to the data in the back of the list
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
    /// provides a pointer to the current item at the _iterator pointer.
    /// moves the iterator pointer to the next item.
}

template<typename Type>
bool List<Type>::AtEnd() const
{
    /// returns if your iterator pointer is at the end of the list
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    /// resets your iterator pointer to the beginning.
}
