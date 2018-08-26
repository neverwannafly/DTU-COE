#include <iostream>
#include "quickSortLL.hpp"

int main() {

    Node *head = NULL;
    head = addToHead(head, 56);
    head = addToHead(head, 21);
    head = addToHead(head, 23);
    head = addToHead(head, 81);
    head = addToHead(head, 90);
    printList(head);
    quickSort(head);
    printList(head);

    return 0;
}