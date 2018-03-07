#include <iostream>
#include <vector>

using namespace std;

// possible permutation: 6 2 1 5 4 3 0
void next_permutation( vector<int>& permutation ) {
    int k = permutation.size() - 2;
    while( k >= 0 && permutation[ k ] > permutation[ k + 1 ] ) {
        k--;
    }
    if( k < 0 )
        return;
    int l = permutation.size() - 1;
    while( k < l && permutation[ l ] < permutation[ k ] ) {
        l--;
    }
    int temp = permutation[ k ];
    permutation[ k ] = permutation[ l ];
    permutation[ l ] = temp;
    reverse( permutation.begin() + k + 1, permutation.end() );
}

int main() {
    vector<int> permutation;
    permutation.push_back( 6 );
    permutation.push_back( 2 );
    permutation.push_back( 1 );
    permutation.push_back( 5 );
    permutation.push_back( 4 );
    permutation.push_back( 3 );
    permutation.push_back( 0 );
    next_permutation( permutation );
    for( int i = 0; i < permutation.size(); i++ ) {
        cout << permutation[ i ] << endl;
    }
}
