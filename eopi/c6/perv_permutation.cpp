#include <iostream>
#include <vector>

using namespace std;

void prev_permutation( vector<int>& permutation ) {
    int k = permutation.size() - 2;
    while( k >= 0 && permutation[ k ] < permutation[ k + 1 ] ) {
        k--;
    }
    if( k < 0 )
        return;
    int l = k + 1;
    while( permutation[ l ] < permutation[ k ] ) {
        l++;
    }
    int temp = permutation[ k ];
    permutation[ k ] = permutation[ l - 1 ];
    permutation[ l - 1 ] = temp;
    reverse( permutation.begin() + k + 1, permutation.end() );
}

int main() {
    vector<int> permutation;
    permutation.push_back( 6 );
    permutation.push_back( 2 );
    permutation.push_back( 3 );
    permutation.push_back( 0 );
    permutation.push_back( 1 );
    permutation.push_back( 4 );
    permutation.push_back( 5 );
    prev_permutation( permutation );
    for( int i = 0; i < permutation.size(); i++ ) {
        cout << permutation[ i ] << endl;
    }
}
