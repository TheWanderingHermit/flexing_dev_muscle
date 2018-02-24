#include <iostream>

class MaxHeap {
    private :
        int * container;
        int capacity;
        int tail;
    public :
        MaxHeap( int c = 10 ) : capacity( c ) { container = new int[ c ]; }
        // get parent element
        inline int parent( int i ) { return ( i - 1 ) / 2; }
        // get left element
        inline int left( int i ) { return ( i * 2 ) + 1; }
        // get right element
        inline int right( int i ) { return ( i * 2 ) + 2; }
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
void swap( int * c, int i, int j ) {
    int temp = c[ i ];
    c[ i ] = c[ j ];
    c[ j ] = temp;
}
int MaxHeap::extractMax() {
    int m = container[ 0 ];
    container[ 0 ] = container[ tail ];
    tail--;
    heapify( 0 );
    return m;
}
int MaxHeap::getMax() {
    return container[ 0 ];
}
void MaxHeap::increaseKey( int k, int v ) {
    container[ k ] = v;
    while( k != 0 && container[ parent( k ) ] > container[ k ] ) {
        swap( container, parent( k ), k );
        k = parent( k );
    }
}
void MaxHeap::del( int k ) {
    increaseKey( k, std::numeric_limits<int>::max() );
    extractMax();
}
void MaxHeap::insert( int v ) {
    if( tail + 1 > capacity ) { return; }
    else {
        tail++;
        increaseKey( tail, v );
    }
}
void MaxHeap::heapify( int k ) {
    int l = left( k );
    int r = right( k );
    int m = container[ k ] < container[ l ] ? ( container[ l ] < container[ r ] : r ? l ) : ( container[ k ] < container[ r ] ? r : k );
    if( m != k ) {
        swap( container, m, k );
        heapify( k );
    }
}
