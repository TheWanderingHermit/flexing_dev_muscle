#include<iostream>

void sort( int* array, int size ){
    for( int i = 1; i < size; i++ ) {
        int c = array[ i ];
        int j = i - 1;
        while( j >= 0 && array[ j ] > c ) {
            array[ j + 1 ] = array[ j ];
            j--;
        }
        array[ j + 1 ] = c;
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
