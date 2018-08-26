#ifndef linkedList_HPP
#define linkedList_HPP

#include <iostream>

struct Node {
    int data;
    Node *next;
};

Node* addToHead(Node *head, int data) {
    Node *tempNode = new Node;
    tempNode->next = NULL;
    tempNode->data = data;
    if (head==NULL) {
        head = tempNode;
    }
    else {
        tempNode->next = head;
        head = tempNode;
    }
    return head;
}

Node* getTail(Node *current) {
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    return current;
}


void printListPrivate(Node *head) {
    std::cout << head->data << " ";
    if (head->next!=NULL) {
        printListPrivate(head->next);
    }
}

void printList(Node *head) {
    printListPrivate(head);
    std::cout << "\n";
}

#endif