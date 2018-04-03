#include <iostream>

template<size_t rows, size_t cols>
void print_2d_array( int (&array)[rows][cols] ) {
    for( size_t i = 0; i < rows; i++ ) {
        for( size_t j = 0; j < cols; j++ ) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template<size_t rows, size_t cols>
bool verify_arrangement( int (&array)[rows][cols], int prow, int pcol ) {
    for( int i = 0; i < pcol; i++ ) {
        if( array[ prow ][ i ] )
            return false;
    }
    for( int i = prow, j = pcol; i >= 0 && j >= 0; i--, j-- ) {
        if( array[ i ][ j ] )
            return false;
    }
    for( int i = prow, j = pcol; i < rows && j >= 0; i++, j-- ) {
        if( array[ i ][ j ] )
            return false;
    }
    return true;
}
template<size_t rows, size_t cols>
bool solve_n_queen( int (&array)[rows][cols], int c ) {
    if( c >= rows ) 
        return true;
    for( int i = 0; i < rows; i++ ) {
        if( verify_arrangement( array, i, c ) ) {
            array[ i ][ c ] = 1;
            if( solve_n_queen( array, c + 1 ) ) 
                return true;
            array[ i ][ c ] = 0;
        }
    }
    return false;
}
int main() {
    int board[ 4 ][ 4 ] = { { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 },
                            { 0, 0, 0, 0 } };
    if( solve_n_queen( board, 0 ) == false ) {
        std::cout << "Arrangement is not possible" << std::endl;
        return 0;
    }
    print_2d_array( board );
    return 0;
}
