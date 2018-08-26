#ifndef quickSortLL_HPP
#define quickSortLL_HPP

#include "linkedList.hpp"

Node *partition(Node *head, Node *end, Node *&newHead, Node *&newEnd) {
    Node *pivot = end;
    Node *prev = NULL, *current = head, *tail = pivot;
    while (current != pivot) {
        if (current->data < pivot->data) {
            if (newHead==NULL) {
                newHead = current;
            }
            prev = current;
            current = current->next;
        } else {
            if (prev) {
                prev->next = current->next;
            }
            Node *tmp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }

    if (newHead == NULL) {
        newHead = pivot;
    }
    newEnd = tail;

    return pivot;

}

Node *quickSortPrivate(Node *head, Node *end) {
    if (!head || head == end) {
        return head;
    }
 
    Node *newHead = NULL, *newEnd = NULL;
    Node *pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node *tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = NULL;
 
        newHead = quickSortPrivate(newHead, tmp);
 
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    pivot->next = quickSortPrivate(pivot->next, newEnd);
 
    return newHead;
}

void quickSort(Node *&head) {
    head = quickSortPrivate(head, getTail(head));
}

#endif