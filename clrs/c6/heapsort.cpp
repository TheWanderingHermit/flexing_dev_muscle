#include <iostream>

class MaxHeap {
    private :
        int * container;
        int capacity;
        int tail;
    public :
        MaxHeap( int c = 10 ) : capacity( c ) { container = new int [c]; }
        // get parent element
        inline int parent( int i ) { return ( i - 1 ) / 2; }
        // get left element
        inline int left( int i ) { return ( i * 2 ) + 1; }
        // get right element
        inline int right( int ) { return ( i * 2 ) + 2; }
        // extract the max element from the heap
        int extractMax();
        // return( not remove ) the max element from heap
        int getMax();
        // increase the key at an index to a given new value
        void increaseKey( int, int );
        // delete the key at index i
        void del( int );
        // insert new key into the heap
        void insert( int );
        // heapify the container starting at the given index
        void heapify( int );
        // construct max heap structure with the given array
        void buildHeap( int *, int );
};
