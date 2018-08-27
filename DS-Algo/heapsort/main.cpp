#include "heap.hpp"

int main() {

    ds::Heap<int> heap;
    heap.insert(100);
    heap.insert(71);
    heap.insert(65);
    heap.insert(199);
    heap.insert(201);
    heap.insert(55);
    heap.insert(89);
    heap.insert(107);
    heap.insert(58);
    heap.print_heap();
    heap.heap_sort();
    heap.print_heap();

    return 0;
}