#include <iostream>

// n - 1 steps are need to bubble n elements in an array
void sort( int * array, int size ) {
    for( int i = 0; i < size - 1; i++ ) {
        for( int j = 0; j < size -i - 1; j++ ) {
            if( array[ j ] > array[ j + 1 ] ) {
                int t = array[ j ];
                array[ j ] = array[ j + 1 ];
                array[ j + 1 ] = t;
            }
        }
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
