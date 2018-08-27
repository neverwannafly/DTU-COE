#ifndef heaps_hpp
#define heaps_hpp

#include <algorithm>
#include <iostream>
#include <vector>

namespace ds {
    template <class data_type>
    class Heap {
    public:
        // Constructors ->
        Heap(bool is_heap_max_heap=true);
        Heap(int size, bool is_heap_max_heap=true);
        Heap(std::vector<data_type> arr, bool is_heap_max_heap=true);
        Heap(data_type *arr, int size, bool is_heap_max_heap=true);
        // Methods ->
        void insert(data_type data);
        void delete_first_element();
        void delete_last_element();
        void heap_sort(bool is_order_ascending=true);
        void print_heap();
        std::vector<data_type> return_heap_as_vector();
        data_type *return_heap_as_array();
        // Destructors ->
        ~Heap();
    private:
        bool is_capacity_of_heap_full();
        void swap_elements(int i, int j);
        void max_heapify(int index, int size);
        void min_heapify(int index, int size);
        void build_heap();
        bool is_heap_max_heap;
        int size, end_index;
        std::vector<data_type> heap;
    };

    // Constructors ->
    template <class data_type>
    Heap<data_type>::Heap(bool is_heap_max_heap=false) {
        this->is_heap_max_heap = is_heap_max_heap;
        this->size = 0;
        this->end_index = 0;
    }
    template <class data_type>
    Heap<data_type>::Heap(int size, bool is_heap_max_heap=false) {
        this->is_heap_max_heap = is_heap_max_heap;
        std::vector<data_type> new_heap(size);
        this->heap = new_heap;
        this->size = size;
        this->end_index = 0;
    }
    template <class data_type>
    Heap<data_type>::Heap(std::vector<data_type> arr, bool is_heap_max_heap) {
        this->is_heap_max_heap = is_heap_max_heap;
        this->heap = arr;
        this->size = arr.size();
        this->end_index = 0;
        build_heap();
    }
    template <class data_type>
    Heap<data_type>::Heap(data_type *arr, int size, bool is_heap_max_heap) {
        this->is_heap_max_heap = is_heap_max_heap;
        std::vector<data_type> new_heap(size);
        for (int i=0; i<size; i++) {
            new_heap[i] = arr[i];
        }
        this->heap = new_heap;
        this->size = size;
        this->end_index = 0;
        build_heap();
    }

    // Methods ->
    template <class data_type>
    bool Heap<data_type>::is_capacity_of_heap_full() {
        return size == heap.size();
    }
    template <class data_type>
    void Heap<data_type>::swap_elements(int i, int j) {
        heap[i] += heap[j];
        heap[j] = heap[i] - heap[j];
        heap[i] = heap[i] - heap[j];
    }
    template <class data_type>
    void Heap<data_type>::insert(data_type data) {
        if (is_capacity_of_heap_full()) {
            size++;
            heap.push_back(data);
        }
        else {
            heap[end_index] = data;
            end_index++;
        }
        build_heap();
    }
    template <class data_type>
    void Heap<data_type>::delete_first_element() {
        swap_elements(0, heap.size()-1);
        heap.resize(heap.size()-1);
        size--;
        build_heap();
    }
    template <class data_type>
    void Heap<data_type>::delete_last_element() {
        heap.resize(heap.size()-1);
        size--;
        build_heap();
    }
    template <class data_type>
    void Heap<data_type>::heap_sort(bool is_order_ascending) {
        int temp_size = heap.size();
        if (is_order_ascending) {
            if (is_heap_max_heap) {
                while (temp_size!=1) {
                    swap_elements(0, --temp_size);
                    max_heapify(0, temp_size);
                }
            }
            else {
                while (temp_size!=1) {
                    swap_elements(0, --temp_size);
                    max_heapify(0, temp_size);
                }
                std::reverse(heap.begin(), heap.end());
            }
        }
        else {
            if (is_heap_max_heap) {
                while (temp_size!=1) {
                    swap_elements(0, --temp_size);
                    min_heapify(0, temp_size);
                }
                std::reverse(heap.begin(), heap.end());
            }
            else {
                while (temp_size!=1) {
                    swap_elements(0, --temp_size);
                    min_heapify(0, temp_size);
                }
            }
        }
    }
    template <class data_type>
    void Heap<data_type>::print_heap() {
        for (int i=0; i<heap.size(); i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << "\n";
    }
    template <class data_type>
    std::vector<data_type> Heap<data_type>::return_heap_as_vector() {
        return heap;
    }
    template <class data_type>
    data_type *Heap<data_type>::return_heap_as_array() {
        data_type *arr = new data_type[heap.size()];
        for (int i=0; i<heap.size(); i++) {
            arr[i] = heap[i];
        }
        return arr;
    }
    template <class data_type>
    void Heap<data_type>::max_heapify(int index, int size) {
        if (2*index+1<size && 2*index+2<size) {
            if (heap[index]<heap[2*index+1] || heap[index]<heap[2*index+2]) {
                if (heap[2*index+1]<heap[2*index+2]) {
                    swap_elements(2*index+2, index);
                    if (2*index+2<(size-1)/2)
                        max_heapify(2*index+2, heap.size());
                }
                else {
                    swap_elements(2*index+1, index);
                    if (2*index+1<(size-1)/2)
                        max_heapify(2*index+1, heap.size());
                }
            }
        }
        else if (2*index+1<size) {
            if (heap[index]<heap[2*index+1]) {
                swap_elements(2*index+1, index);
                if (2*index+1<(size-1)/2)
                    max_heapify(2*index+1, heap.size());
            }
        }
    }
    template <class data_type>
    void Heap<data_type>::min_heapify(int index, int size) {
        if (2*index+1<size && 2*index+2<size) {
            if (heap[index]>heap[2*index+1] || heap[index]>heap[2*index+2]) {
                if (heap[2*index+1]>heap[2*index+2]) {
                    swap_elements(2*index+2, index);
                    if (2*index+2<(size-1)/2)
                        min_heapify(2*index+2, heap.size());
                }
                else {
                    swap_elements(2*index+1, index);
                    if (2*index+1<(size-1)/2)
                        min_heapify(2*index+1, heap.size());
                }
            }
        }
        else if (2*index+1<size) {
            if (heap[index]>heap[2*index+1]) {
                swap_elements(2*index+1, index);
                if (2*index+1<(size-1)/2)
                    min_heapify(2*index+1, heap.size());
            }
        }
    }
    template <class data_type>
    void Heap<data_type>::build_heap() {
        for (int i=(size-2)/2; i>=0; i--) {
            if (is_heap_max_heap)
                max_heapify(i, heap.size());
            else
                min_heapify(i, heap.size());
        }
    }

    // Destructors ->
    template <class data_type>
    Heap<data_type>::~Heap() {
        this->heap.resize(0);
    }
}

#endif
