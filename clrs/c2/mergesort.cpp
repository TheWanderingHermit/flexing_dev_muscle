#include <iostream>

void merge( int A[], int p, int q, int r ) {
    int numL = q - p + 1, numR = r - q;
    int L[ numL ], R[ numR ];
    for( int i = 0; i < numL; i++ ) { L[ i ] = A[ p + i ]; }
    for( int j = 0; j < numR; j++ ) { R[ j ] = A[ q + j + 1 ]; }
    int a = 0, b = 0, c = p;
    while( a < numL && b < numR ) {
        if( L[ a ] <= R[ b ] ) { 
            A[ c ] = L[ a ]; 
            a++; 
        }
        else{
            A[ c ] = R[ b ]; 
            b++; 
        }
        c++;
    }
    while( a < numL ) {
        A[ c ] = L[ a ];
        a++;
        c++;
    }
    while( b < numR ) {
        A[ c ] = R[ b ];
        b++;
        c++;
    }
}

void sort( int A[], int l, int h ) {
    if( l >= h ) return;
    int m = ( l + h ) / 2;
    sort( A, l, m );
    sort( A, m + 1, h );
    merge( A, l, m, h );
}

int main() {
    int array [] = { 5, 6, 2, 4, 7, 2, 1, 0 };
    int size     = sizeof( array ) / sizeof( array[ 0 ] );
    sort( array, 0, size - 1 );
    for( int i = 0; i < size; i++ ) {
        std::cout << array[ i ] << std::endl;
    }
    return 0;
}
