#include <iostream>
#include <vector>
using namespace std;

/*
 * check if the end of array can be reached
 * A = [ a, b, c, d... ] A[ i ] number of positions that can be jumped from index i
 * Insight: index that can be reached from position i = i + A[ i ]
 * index that can be reached from current position = max( index that can be reached from previous position, i + A[ i ] )
 * */

bool is_reachable( vector<int>& jump_array ) {
    int i = 0, max_reachable = 0;
    while( i <= max_reachable && max_reachable < jump_array.size() ) {
        max_reachable = max( max_reachable, i + jump_array[ i ] );
        i++;
    }
    return max_reachable >= jump_array.size();
}

int main() {
    vector<int> a;
    a.push_back( 3 );
    a.push_back( 3 );
    a.push_back( 1 );
    a.push_back( 0 );
    a.push_back( 2 );
    a.push_back( 0 );
    a.push_back( 1 );
    std::cout << is_reachable( a ) << std::endl;
    return 0;
}
