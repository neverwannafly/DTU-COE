#include "StacksAndQueues.hpp"

// ******	QUEUE CLASS ***** //
//Public Member Functions
// -> Constructor

template <class type>
Node<type>::Node(type data) {
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}

// ******	QUEUE CLASS ***** //
// Private Member Functions
// -> Modifier Member Functions

template <class type>
/** This function creates a new Node and returns a Node pointer **/
/** pointing to the new Node created.                           **/
Node<type> *Queue<type>::createNode(type data) {
    ++size;
    Node<type> *newPtr = new Node<type>(data);
    return newPtr;
}
template <class type>
/** This function adds an element to the Queue**/
void Queue<type>::enqueuePrivate(type data, Node<type> *&nodePtrHead, Node<type> *&nodePtrTail) {
    if(isUnderFlow()) {
        nodePtrHead = createNode(data);
        nodePtrTail = nodePtrHead;
    }
    else {
        Node<type> *newPtr = createNode(data);
        newPtr->prev = nodePtrTail;
        nodePtrTail->next = newPtr;
        nodePtrTail = newPtr;
    }
}
template <class type>
/** This function removes an element from the Queue**/
void Queue<type>::dequeuePrivate(Node<type> *&nodePtrHead, Node<type> *&nodePtrTail) {
    if(!isUnderFlow()) {
        if(returnSize()>1) {
            --size;
            Node<type> *tempPtr = nodePtrHead;
            nodePtrHead = nodePtrHead->next;
            nodePtrHead->prev = NULL;
            tempPtr->next = NULL;
            delete tempPtr;
        } else {
            --size;
            delete nodePtrHead;
            nodePtrHead = NULL;
            nodePtrTail = NULL;
        }
    } else {
        throw "UnderFlow error\n";
    }
}
template <class type>
/** This function adds an element to the Queue and returns **/
/** the element added                                      **/
type Queue<type>::enqueueAndReturnDataPrivate(type data, Node<type> *&nodePtrHead, Node<type> *&nodePtrTail) {
    enqueuePrivate(data, nodePtrHead, nodePtrTail);
    return data;
}
template <class type>
/** This function removes an element from the Queue and returns **/
/** the element deleted.                                        **/
type Queue<type>::dequeueAndReturnDataPrivate(Node<type> *&nodePtrHead, Node<type> *&nodePtrTail) {
    if(!isUnderFlow()) {
        int dataToBeDeleted;
        if(returnSize()>1) {
            --size;
            Node<type> *tempPtr = nodePtrHead;
            nodePtrHead = nodePtrHead->next;
            nodePtrHead->prev = NULL;
            tempPtr->next = NULL;
            dataToBeDeleted = tempPtr->data;
            delete tempPtr;
        } else {
            --size;
            dataToBeDeleted = nodePtrHead->data;
            delete nodePtrHead;
            nodePtrHead = NULL;
            nodePtrTail = NULL;
        }
        return dataToBeDeleted;
    } else {
        throw "UnderFlow error\n";
    }
}

// -> Accessor Member Functions

template <class type>
/** Returns an element from the Queue.       **/
type Queue<type>::returnPrivate(Node<type> *nodePtr) const {
    if(!isUnderFlow())
        return nodePtr->data;
    else
        throw "UnderFlow error\n";
}
template <class type>
/** Checks if the Queue is empty or not.           **/
bool Queue<type>::isUnderFlowPrivate(Node<type> *nodePtr) const {
    return nodePtr==NULL ? true : false;
}
template <class type>
/** Returns the Size of the Queue 				**/
long long Queue<type>::returnSizePrivate() {
    return size;
}
template <class type>
/** Prints the current Queue **/
void Queue<type>::printPrivate(Node<type> *nodePtr, bool isPrintDirectionHead) const {
    if(isPrintDirectionHead) {
        Node<type> *tempPtr = nodePtr;
        while(tempPtr!=NULL) {
            std::cout << tempPtr->data << " ";
            tempPtr = tempPtr->next;
        }
        std::cout << std::endl;
    }
    else {
        Node<type> *tempPtr = nodePtr;
        while(tempPtr!=NULL) {
            std::cout << tempPtr->data << " ";
            tempPtr = tempPtr->prev;
        }
        std::cout << std::endl;
    }
}

// Public Member Functions
// -> Constructor and Destructor

template <class type>
Queue<type>::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}
template <class type>
Queue<type>::~Queue() {
    while(!isUnderFlow())
        dequeue();
}

// -> Modifier Member Functions

template <class type>
void Queue<type>::enqueue(type data) {
    enqueuePrivate(data, head, tail);
}
template <class type>
void Queue<type>::dequeue() {
    try {
        dequeuePrivate(head, tail);
    }
    catch(...) {
        std::cerr << "Queue Already Empty\n";
    }
}

template <class type>
type Queue<type>::enqueueAndReturnData(type data) {
    return enqueueAndReturnDataPrivate(data, head, tail);
}
template <class type>
type Queue<type>::dequeueAndReturnData() {
    try {
        return dequeueAndReturnDataPrivate(head, tail);
    }
    catch(...) {
        std::cerr << "Queue Already Empty\n";
        return 0;
    }
}

// -> Accessor Member Functions

template <class type>
type Queue<type>::returnFirst() const {
    try {
        return returnPrivate(head);
    }
    catch(...) {
        std::cerr << "Queue is Empty\n";
        return 0;
    }
}
template <class type>
type Queue<type>::returnLast() const {
    try {
        return returnPrivate(tail);
    }
    catch(...) {
        std::cerr << "Queue is empty\n";
        return 0;
    }
}
template <class type>
bool Queue<type>::isUnderFlow() const {
    return isUnderFlowPrivate(head);
}
template <class type>
long long Queue<type>::returnSize() {
    return returnSizePrivate();
}
template <class type>
void Queue<type>::print() const {
    printPrivate(head, true);
}
template <class type>
void Queue<type>::printReverse() const {
    printPrivate(tail, false);
}

// ***** STACK CLASS ***** //
// Private Member Functions
// -> Modifier Member Functions

template <class type>
/** Creates a new Node and returns a pointer pointing to **/
/** the new Node created. 								 **/
Node<type> *Stack<type>::createNode(type data) {
    size++;
    Node<type> *newNode = new Node<type>(data);
    return newNode;
}
template <class type>
/** Adds an element to the Stack.				**/
void Stack<type>::pushPrivate(type data, Node<type> *&nodePtr) {
    if(isUnderFlow())
        nodePtr = createNode(data);
    else {
        Node<type> *newNode = createNode(data);
        newNode->next = nodePtr;
        nodePtr = newNode;
    }
}
template <class type>
/** Removes an element from the Stack.			**/
void Stack<type>::popPrivate(Node<type> *&nodePtr) {
    if(!isUnderFlow()) {
        Node<type> *tempPtr;
        tempPtr = nodePtr;
        nodePtr = nodePtr->next;
        tempPtr->next = NULL;
        size--;
        delete tempPtr;
    }
    else {
        throw "UnderFlow Error\n";
    }
}
template <class type>
/** Adds an element to the Stack and return it's value **/
type Stack<type>::pushAndReturnDataPrivate(type data, Node<type> *&nodePtr) {
    pushPrivate(data, nodePtr);
    return data;
}
template <class type>
/** Removes an element from the Stack and return it's value **/
type Stack<type>::popAndReturnDataPrivate(Node<type> *&nodePtr) {
    if(!isUnderFlow()) {
        Node<type> *tempPtr;
        tempPtr = nodePtr;
        nodePtr = nodePtr->next;
        tempPtr->next = NULL;
        type dataToBeDeleted = tempPtr->data;
        size--;
        delete tempPtr;
        return dataToBeDeleted;
    } 
    else {
        throw "UnderFlow Error\n";
    }
}

// -> Access Member Functions

template <class type>
/** Returns an element from the Stack **/
type Stack<type>::returnTopPrivate(Node<type> *nodePtr) const {
    return nodePtr->data;
}
template <class type>
/** Checks if the Stack is empty **/
bool Stack<type>::isUnderFlowPrivate(Node<type> *nodePtr) const {
    return nodePtr==NULL ? true : false;
}
template <class type>
/** Returns the current size of Stack **/
long long Stack<type>::returnSizePrivate() const {
    return size;
}
template <class type>
/** Prints the current Stack **/
void Stack<type>::printPrivate(Node<type> *nodePtr) const {
    Node<type> *tempPtr = nodePtr;
    while(tempPtr!=NULL) {
        std::cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    std::cout << std::endl;
}

// Public Member Functions
// -> Constructor and Destructor

template <class type>
Stack<type>::Stack() {
    head = NULL;
    size = 0;
}
template <class type>
Stack<type>::~Stack() {
    while(!isUnderFlow())
        pop();
}

// -> Modifier Member Functions

template <class type>
void Stack<type>::push(type data) {
    pushPrivate(data, head);
}
template <class type>
void Stack<type>::pop() {
    try {
        popPrivate(head);
    }
    catch(...) {
        std::cerr << "Stack is already empty\n";
    }
}
template <class type>
type Stack<type>::pushAndReturnData(type data) {
    return pushAndReturnDataPrivate(data, head);
}
template <class type>
type Stack<type>::popAndReturnData() {
    try {
        return popAndReturnDataPrivate(head);
        return 0;
    }
    catch(...) {
        std::cerr << "Stack is already empty\n";
        return 0;
    }
}

// -> Access Member Functions

template <class type>
type Stack<type>::returnTop() const {
    try {
        return returnTopPrivate(head);
    }
    catch(...) {
        std::cerr << "Stack is already empty\n";
        return 0;
    }
}
template <class type>
bool Stack<type>::isUnderFlow() const {
    return isUnderFlowPrivate(head);
}
template <class type>
long long Stack<type>::returnSize() const {
    return returnSizePrivate();
}
template <class type>
void Stack<type>::print() const {
    printPrivate(head);
}