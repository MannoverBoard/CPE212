template<typename Type>
List<Type>::List()
{
    /**
     * Insert the content for the constructor
     */
}

template<typename Type>
List<Type>::~List()
{
    /**
     * Insert the content for the destructor
     */
}

template<typename Type>
void List<Type>::AddItemSorted(const Type &data)
{
    /**
     * Insert the items in the list in ascending order
     */
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
    /**
     * Deletes a provided item from the list
     */
}

template<typename Type>
unsigned int List<Type>::Count() const
{
    /**
     * Returns the number of items in the list
     */
}

template<typename Type>
Type& List<Type>::Front()
{
    /**
     * Returns the reference to the item at the front of the list
     */
}

template<typename Type>
Type List<Type>::Front() const
{
    /**
     * Returns a const copy to the data that is at the front of the list
     */
}

template<typename Type>
Type& List<Type>::Back()
{
    /**
     * Returns a reference to the item at the back of the list
     */
}

template<typename Type>
Type List<Type>::Back() const
{
    /**
     * Returns a const copy to the item at the back of the list
     */
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
    /**
     * Provides a pointer to the current item at the _iterator pointer.
     * It moves the iterator pointer to the next item in the list.
     */
}

template<typename Type>
bool List<Type>::AtEnd() const
{
    /**
     * Returns if the iterator pointer is at the end of the list
     */
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    /**
     * Resets the iterator pointer to the beginning of the list
     */
}

template<typename Type>
Type List<Type>::PopFront()
{
    /**
     * Method that will Pop the first item off of the front of the list.
     * This will remove the item from the list and return its value to the caller.
     */
}

