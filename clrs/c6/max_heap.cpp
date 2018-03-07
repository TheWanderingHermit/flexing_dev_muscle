#include<iostream>
#include<cstring>

class max_heap {
    private:
        int *elem, cap, curr_sz;
        inline int parent( int i ) { return ( int ) ( i + 1 ) / 2; }
        inline int l_child( int i ) { return 2 * i + 1; }
        inline int r_child( int i ) { return 2 * i + 2; }
    public:
        max_heap( int );
        void build( int );
        void fill_and_build( int *, int );
        void insert( int );
        int get_max();
};
max_heap::max_heap( int c ) {
    elem = new int( c );
    cap  = c;
    curr_sz = 0;
}
void max_heap::build( int i ) {
    if( i > curr_sz / 2 ) { return; }
    int l = l_child( i );
    int r = r_child( i );
    int m = i;
    if( l <= curr_sz && elem[ l ] > elem[ i ] ) { m = l; }
    else if( r <= curr_sz && elem[ r ] > elem[ i ] ) { m = r; }
    if( m != i ) {
        int temp = elem[ m ];
        elem[ m ] = elem[ i ];
        elem[ i ] = elem[ temp ];
    }
    build( m );
}
void max_heap::fill_and_build( int * a, int s ) {
    curr_sz = s;
    std::memcpy( elem, a, s );
    for( int i = curr_sz / 2; i >= 0; i-- ) {
        build( i );
    } 
}
