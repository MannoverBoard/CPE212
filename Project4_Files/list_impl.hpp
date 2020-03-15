template<typename Type>
List<Type>::List()
{
    /**
     * Insert the content for the constructor
     */
    _firstNode      =       NULL ;
    _lastNode       =       NULL ;
    _iteratorNode   =       NULL ;
    _count          =       0    ;
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
    Node<Type> *newNode            ;
    Node<Type> *prevLoc            ;
    Node<Type> *currLoc            ;
    bool        moreToSearch       ;
 
    prevLoc     =       NULL       ;
    currLoc     =       _firstNode ;

    if (_firstNode == NULL) {
        newNode                 =       new Node<Type> ;
        newNode->localData      =       data           ;
        newNode->nextItem       =       NULL           ;
        _firstNode              =       newNode        ;
        _lastNode               =       newNode        ;
        _count++;
    }

    moreToSearch = (currLoc != NULL);

    // Find insertion point
    // ----------------------------------------------------
    while (moreToSearch)
    {
        if (data > currLoc->localData) {
            prevLoc             =       currLoc           ;
            currLoc             =       currLoc->nextItem ;
            moreToSearch        =       (currLoc != NULL) ;
        } 
 
        if (data < currLoc->localData) { 
            moreToSearch        =       false             ;
        }
    }

    //Prep node for insertion
    // -----------------------------------------------------
    newNode                     =       new Node<Type> ;
    newNode->localData          =       data           ;

    // Insert node
    // -----------------------------------------------------
    if (currLoc = NULL) {
        newNode->nextItem       =       NULL    ;
        prevLoc->nextItem       =       newNode ;
        _lastNode               =       newNode ;
        _count++;
    }

    else {
        newNode->nextItem       =       currLoc ;
        prevLoc->nextItem       =       newNode ;
        _count++;
    }

}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
    /**
     * Deletes a provided item from the list
     */
    Node<Type>          *currLoc    ;
    Node<Type>          *prevLoc    ;
    bool                itemRemoved ;

    currLoc     =       _firstNode  ;
    prevLoc     =       NULL        ;

    // List is empty
    // --------------------------------------------------------
    if (currLoc == NULL) {return false;}

    while (currLoc != NULL) 
    {
        if (currLoc == data) {
            // first node is being deleted
            // ---------------------------------------------------
            if (currLoc == _firstNode) {
                prevLoc             =       currLoc           ;
                currLoc             =       currLoc->nextItem ;

                delete prevLoc; 

                _firstNode          =       currLoc           ;

                _count--    ;
                return true ;
            }
            // last node is being deleted
            // ---------------------------------------------------
            if (currLoc == _lastNode) {
                prevLoc->nextItem   =       NULL              ;
                _lastNode           =       prevLoc           ;

                delete currLoc ;
                _count--       ;
                return true    ;
            }
            // node somewhere in the middle is being deleted
            // ---------------------------------------------------
            else {
                prevLoc->nextItem   =       currLoc->nextItem ;

                delete currLoc ;
                _count--       ;
                return true    ;
            }
        }
        // Advance pointers
        // ----------------------------------------------------
        prevLoc                     =       currLoc           ;
        currLoc                     =       currLoc->nextItem ;
    }
}

template<typename Type>
unsigned int List<Type>::Count() const
{
    /**
     * Returns the number of items in the list
     */
    return _count;
}

template<typename Type>
Type& List<Type>::Front()
{
    /**
     * Returns the reference to the item at the front of the list
     */
    return _firstNode;
}

template<typename Type>
Type List<Type>::Front() const
{
    /**
     * Returns a const copy to the data that is at the front of the list
     */
    return _firstNode;
}

template<typename Type>
Type& List<Type>::Back()
{
    /**
     * Returns a reference to the item at the back of the list
     */
    return _lastNode;
}

template<typename Type>
Type List<Type>::Back() const
{
    /**
     * Returns a const copy to the item at the back of the list
     */
    return _lastNode;
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
    /**
     * Provides a pointer to the current item at the _iterator pointer.
     * It moves the iterator pointer to the next item in the list.
     */
    Node<Type>          *temp         ;         // create a temporary pointer
    temp        =       _iteratorNode ;         // set temp pointer to point to iterator pointer

    // List is empty
    // -------------------------------------------------------------
    if (_iteratorNode == NULL) {return &temp->localData;}       // iterator at end of the list

    // return current location of iterator, advance iterator
    // -------------------------------------------------------------
    _iteratorNode = _iteratorNode->nextItem;                    // advance the iterator pointer

    return &temp->localData;                                    // return data from previous location of iterator
}

template<typename Type>
bool List<Type>::AtEnd() const
{
    /**
     * Returns if the iterator pointer is at the end of the list
     */
    
    // Iterator is at end of list
    // ------------------------------------------------------
    if (_iteratorNode == NULL) {return true;}

    // Iterator not at end of list
    // ------------------------------------------------------
    else {return false;}
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    /**
     * Resets the iterator pointer to the beginning of the list
     */
    _iteratorNode = _firstNode;
}

template<typename Type>
Type List<Type>::PopFront()
{
    /**
     * Method that will Pop the first item off of the front of the list.
     * This will remove the item from the list and return its value to the caller.
     */

    if (_firstNode == NULL) {return NULL;}

    Type info;      // create a variable to store the data from the first node
    Node<Type>              *tmp                 ;      // create a temporary node pointer

    tmp             =       _firstNode           ;      // point temp at first node
    info            =       tmp->localData       ;      // store data from first node in info
    _firstNode      =       _firstNode->nextItem ;      // designate 2nd node as first

    delete tmp  ;     // delete old first node
    _count--    ;
    return info ;    // return the data from the top of the list
    
}

