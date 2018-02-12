#include <iostream>
#include <limits>

int max_crossing_sum( int * A, int l, int m, int h ) {
    int l_sum = std::numeric_limits< int >::min();
    int r_sum = l_sum;
    for( int i = m, sum = 0; i >= l; i-- ) {
        sum = sum + A[ i ];
        if( sum > l_sum ) { l_sum = sum; }
    }
    for( int i = m + 1, sum = 0; i <= h; i++ ) {
        sum = sum + A[ i ];
        if( sum > r_sum ) { r_sum = sum; }
    }
    return l_sum + r_sum;
}

int max_subarray_sum( int * A, int l, int h ) {
    if( l == h ) return A[ l ];
    else if( l > h ) return 0; // this branch does not contribute to the sum
    int m = ( l + h ) / 2;
    int ls = max_subarray_sum( A, l, m );
    int rs = max_subarray_sum( A, m + 1, h );
    int cs = max_crossing_sum( A, l, m, h );
    if( ls > rs && ls > cs ) {
        return ls;
    }
    else if( rs > cs ) {
        return rs;
    }
    return cs;
}

int main() {
    int array [] = { -5, -3, -2, -1, -7, -5, -1, -2 };
    int size     = sizeof( array ) / sizeof( array[ 0 ] );
    std::cout << max_subarray_sum( array, 0, size - 1 ) << std::endl;
    return 0;
}
