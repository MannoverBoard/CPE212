template<typename T>
List<T>::List() {
    *head     =   NULL;
    *tail     =   NULL;
    *iterator =   NULL;
    count     =   0   ;

}

template<typename T>
void List<T>::addItem   (const T &data) {
    Node<T> *tmpPtr;
    tmpPtr              =     new Node<T>;

    if (isEmpty() == true) {
        head            =   tmpPtr;
        head->next      =   NULL;
        head->localData =   data;
        tail            =   head;

        count++;
    }

    else {
        tmpPtr->next      = head;
        tmpPtr->localData = data;
        head              = tmpPtr;     // new node is now new head

        count++;
    }
    
}

template<typename T>
void List<T>::Print() {
    iterator = head;
    while (iterator->next != NULL) {
        std::cout << iterator->localData << std::endl;
    }
}

template<typename T>
bool List<T>::removeItem(const T &data) {

}

template<typename T>
bool List<T>::isEmpty   () {

}