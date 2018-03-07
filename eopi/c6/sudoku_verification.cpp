#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

bool verify_partial_assignemnt( vector< vector< int > >& sudoku, int start_row, int end_row, int start_col, int end_col ) {
    set<int> checked_assignments;
    for( int i = start_row; i < end_row; i++ ) {
        for( int j = start_col; j < end_col; j++ ) {
            if( checked_assignments.find( sudoku[ i ][ j ] ) != checked_assignments.end() )
                return false;
            checked_assignments.insert( sudoku[ i ][ j ] );
        }
    }
    return true;
}
bool verify_sudoku( vector< vector< int > >& sudoku ) {
    for( int i = 0; i < sudoku.size(); i++ ) 
        if( ! verify_partial_assignemnt( sudoku, i, i + 1, 0, sudoku.size() ) )
            return false;
    for( int j = 0; j < sudoku.size(); j++ )
        if( ! verify_partial_assignemnt( sudoku, 0, sudoku.size(), j, j + 1 ) )
            return false;
    int regions = int( sqrt( sudoku.size() ) );
    for( int k = 0; k < regions; k++ ) {
        for( int l = 0; l < regions; k++ ) {
            if( ! verify_partial_assignemnt( sudoku, regions * k, regions * ( k + 1 ), regions * l, regions * ( l + 1 ) ) )
                return false;
        }
    }
    return true;
}
