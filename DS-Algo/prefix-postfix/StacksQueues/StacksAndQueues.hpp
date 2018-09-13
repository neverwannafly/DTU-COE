#ifndef StacksAndQueues_hpp
#define StacksAndQueues_hpp

//This file contains the declarations of various classes necessary
//to implement the Stack ADT and Queue ADT.

#include <iostream>

//Friend functions declarations

template<class type>
class Stack;

template<class type>
class Queue;

//Class declarations
// -> Node Class
//		Node Class will implement the cells/nodes/segments of a stack
//		and queue. 

template <class type>
class Node {
    friend class Queue<type>;
    friend class Stack<type>;
public:
    Node(type data);
private:
    Node *next;
    Node *prev;
    type data;
};

// ->Queue Class
//		Queue Class will implement the Queue ADT.

template <class type>
class Queue {
public:
    Queue();
    ~Queue();
    
    void enqueue(type data);
    void dequeue();
    type enqueueAndReturnData(type data);
    type dequeueAndReturnData();
    
    type returnFirst() const;
    type returnLast() const;
    bool isUnderFlow() const;
    long long returnSize();
    void print() const;
    void printReverse() const;
private:
    Node<type> *createNode(type data);
    void enqueuePrivate(type data, Node<type> *&nodePtrHead, Node<type> *&nodePtrTail);
    void dequeuePrivate(Node<type> *&nodePtrHead, Node<type> *&nodePtrTail);
    type enqueueAndReturnDataPrivate(type data, Node<type> *&nodePtrHead, Node<type> *&nodePtrTail);
    type dequeueAndReturnDataPrivate(Node<type> *&nodePtrHead, Node<type> *&nodePtrTail);
    
    type returnPrivate(Node<type> *nodePtr) const;
    bool isUnderFlowPrivate(Node<type> *nodePtr) const;
    long long returnSizePrivate();
    void printPrivate(Node<type> *nodePtr, bool isPrintDirectionHead) const;
    
    Node<type> *head;
    Node<type> *tail;
    type data;
    long long size;
};

// -> Stack Class
//		Stack Class will implement the stack ADT.

template <class type>
class Stack {
public:
    Stack();
    ~Stack();
    
    void push(type data);
    void pop();
    type pushAndReturnData(type data);
    type popAndReturnData();
    
    type returnTop() const;
    bool isUnderFlow() const;
    long long returnSize() const;
    void print() const;
private:
    Node<type> *createNode(type data);
    void pushPrivate(type data, Node<type> *&nodePtr);
    type pushAndReturnDataPrivate(type data, Node<type> *&nodePtr);
    void popPrivate(Node<type> *&nodePtr);
    type popAndReturnDataPrivate(Node<type> *&nodePtr);
    
    type returnTopPrivate(Node<type> *nodePtr) const;
    bool isUnderFlowPrivate(Node<type> *nodePtr) const;
    long long returnSizePrivate() const;
    void printPrivate(Node<type> *nodePtr) const;
    
    Node<type> *head;
    long long size;
};

#endif