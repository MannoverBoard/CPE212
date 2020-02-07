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
  Node<Type>* node = _firstNode;
  while(node!=nullptr) {
    Node<Type>* deleteme = node;
    if(deleteme==nullptr) { break; }
    node = node->nextItem;
    delete deleteme;
  }
}

template<typename Type>
void List<Type>::AppendItem(const Type &data)
{
  /// Append an item correctly into the list
  /// increment _count
  _count++;
  auto node = new Node<Type>(data);
  node->nextItem = nullptr;
  if(_firstNode==nullptr) {
    //starting from empty list
    _firstNode = node;
    _lastNode = node;
    return;
  }
  if(_lastNode==nullptr) {
    //technically a disallowed state, but we can handle this situation,
    //_lastNode needs to be fixed to be the last by going through the whole list
    auto tmp = _firstNode;
    while(tmp!=nullptr) {
      if(tmp->nextItem==nullptr) {
        //at the end so set _lastNode
        _lastNode = tmp;
        break;
      }
      tmp = tmp->nextItem;
    }
  }
  if(_lastNode==nullptr) {
    //something really weird happened
    //TODO log an error in this case, this would only happen in a multithreaded
    // type situation, locks on updating first and last are necessary
    return;
  }
  _lastNode->nextItem = node;
  _lastNode = node;
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
  /// remove an item correctly to the list
  /// All items in this project will be equal comparable
  /// return false if the item was not removed
  /// return true if the item was removed.
  /// decrement _count if the item was removed.
  bool found = false;
  auto node  = _firstNode;
  decltype(node) prevnode{nullptr};
  while(node!=nullptr) {
    if(node->localData==data) { break; }
    prevnode = node;
    node     = node->nextItem;
  }
  if(node==nullptr) { return false; } //not found
  if(prevnode==nullptr) {
    //found at beginning
    _firstNode = node->nextItem;
    if(_firstNode->nextItem==nullptr) {
      //only 1 item in list, so update _lastNode
      _lastNode = _firstNode;
    }
  } else {
    //found in the  middle or end
    prevnode->nextItem = node->nextItem;
    if(node->nextItem==nullptr) {
      //deleting at the end of the list
      _lastNode = prevnode;
    }
  }
  delete node;
  --_count;
  return true;
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
  //this can throw an exception - you have been warned
  return _firstNode->localData;
}

template<typename Type>
Type List<Type>::Front() const
{
  /// returns a const copy to the data in the front of the list.
  //this can throw an exception - you have been warned
  return _firstNode->localData;
}

template<typename Type>
Type& List<Type>::Back()
{
  /// returns a reference to the data in the back of the list.
  //this can throw an exception - you have been warned
  return _lastNode->localData;
}

template<typename Type>
Type List<Type>::Back() const
{
  /// returns a const copy to the data in the back of the list
  //this can throw an exception - you have been warned
  return _lastNode->localData;
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
  /// provides a pointer to the current item at the _iterator pointer.
  /// moves the iterator pointer to the next item.
  //this can throw an exception - you have been warned
  return &_iteratorNode->localData;
}

template<typename Type>
bool List<Type>::AtEnd() const
{
  /// returns if your iterator pointer is at the end of the list
  return (_iteratorNode==nullptr);
}

template<typename Type>
void List<Type>::ResetIterator() const
{
  /// resets your iterator pointer to the beginning.
  _iteratorNode = _firstNode;
}
