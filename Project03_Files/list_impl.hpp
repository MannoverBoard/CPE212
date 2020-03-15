/// IMPLEMENT THE FOLLOWING FUNCTIONS

template<typename Type>
List<Type>::List()
{
    _firstNode      =      NULL;
    _lastNode       =      NULL;
    _iteratorNode   =      NULL;
    _count          =         0;
}

template<typename Type>
List<Type>::~List()
{
    /// delete all data within the list, be sure to account for memory leaks.
    Node<Type> *tmpPtr   =   NULL    ;               // set it to point to the location of first node

    while(_firstNode) {                              // while first node is not at end of list
        tmpPtr      =   _firstNode->nextItem;        // set first node to next node in list
        delete _firstNode; 
        _firstNode  =   tmpPtr;                      // delete data at original first node
    }
}

template<typename Type>
void List<Type>::AppendItem(const Type &data)
{
    /// Append an item correctly into the list
    /// increment _count

    Node<Type> *tmpPtr   =   new Node<Type>(data);    // make a new Node
    _count++;

    if (_lastNode == NULL) {                    // if true then this is the first node

        _firstNode       =       tmpPtr;        // make new node the first node in list
        _lastNode        =       _firstNode;    // first node also is the last node added
    }
    else {
        _lastNode->nextItem    =    tmpPtr; // new node is now linked to last node in list
        _lastNode              =    tmpPtr; // last node is now the newest node
    }
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
    /// remove an item correctly to the list
    /// All items in this project will be equal comparable
    /// return false if the item was not removed
    /// return true if the item was removed.
    /// decrement _count if the item was removed.
    Node<Type> *CurrentLoc  =   _firstNode->nextItem   ;
    Node<Type> *PrevLoc     =   _firstNode             ;
        /*
                               first    Current                         last
                               ------    ------    ------    ------    ------
                        Prev ->|data|    |data|    |data|    |data|    |data|
                               |next| -> |next| -> |next| -> |next| -> |next|
                               ------    ------    ------    ------    ------
        */
    

    if (PrevLoc->localData == data){        // check to first node to see if it should be deleted
        _firstNode  =  CurrentLoc;          // first node is moved to next node in list
        delete            PrevLoc;          // delete node containing data we want to remove
        _count--;                           // decrement item count
        return true;                        // item found, exit function
    


    while (CurrentLoc->nextItem != NULL){
        if (CurrentLoc->localData == data){
            PrevLoc->nextItem = CurrentLoc->nextItem;
            delete CurrentLoc;
            _count--;
            return true;
        }
        PrevLoc = CurrentLoc;
        CurrentLoc = CurrentLoc->nextItem;
    }

    if (CurrentLoc->localData == data){
        _lastNode = PrevLoc;
        _lastNode->nextItem = NULL;
        _count--;
        delete CurrentLoc;
        return true;
    }

    return false;
}

template<typename Type>
unsigned int List<Type>::Count() const
{
    /// returns the size from _count.
    return _count;
}

template<typename Type>
Type& List<Type>::Front()
{
    /// returns a reference to the data in the front of the list
    return _firstNode->localData;
}

template<typename Type>
Type List<Type>::Front() const
{
    /// returns a const copy to the data in the front of the list.
    return _firstNode->localData;
}

template<typename Type>
Type& List<Type>::Back()
{
    /// returns a reference to the data in the back of the list.
    return _lastNode->localData;
}

template<typename Type>
Type List<Type>::Back() const
{
    /// returns a const copy to the data in the back of the list
    return _lastNode->localData;
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
    /// provides a pointer to the current item at the _iterator pointer.
    /// moves the iterator pointer to the next item.
    //if (_firstNode == NULL) { return; }                    // list is empty and there is no need to iterate
    Node<Type> *tmpPtr     =   _iteratorNode          ;
    _iteratorNode         =    _iteratorNode->nextItem;
    return &tmpPtr->localData;

}

template<typename Type>
bool List<Type>::AtEnd() const
{
    /// returns if your iterator pointer is at the end of the list
    if (_iteratorNode == NULL) {
        return true;
    }

    return false;
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    /// resets your iterator pointer to the beginning.
    _iteratorNode = _firstNode;
}
