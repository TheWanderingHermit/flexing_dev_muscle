#include <iostream>

void sort( int * array, int size ) {
    for( int i = 0; i < size - 1; i++ ) {
        int m = i;
        for( int j = i + 1; j < size; j++ ) {
            if( array[ m ] > array[ j ] ) {
                m = j;
            }
        }
        int t = array[ i ];
        array[ i ] = array[ m ];
        array[ m ] = t;
    }
}
int main() {
    int array [] = { 5, 6, 2, 4, 7, 2, 1, 0 };
    int size     = sizeof( array ) / sizeof( array[ 0 ] );
    sort( array, size );
    for( int i = 0; i < size; i++ ) {
        std::cout << array[ i ] << std::endl;
    }
    return 0;
}
