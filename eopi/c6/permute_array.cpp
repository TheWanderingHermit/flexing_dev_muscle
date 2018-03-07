#include <iostream>
#include <vector>

using namespace std;

void swap( vector<char>& alphabet, int i, int j ) {
    int temp = alphabet[ i ];
    alphabet[ i ] = alphabet[ j ];
    alphabet[ j ] = temp;
}
void permute( vector<char>& alphabet, vector< int >& permutation ) {
    for( unsigned int i = 0; i < permutation.size(); i++ ) {
        int j = i;
        while( permutation[ j ] > 0 ) {
            swap( alphabet, j, permutation[ j ] );
            int temp = permutation[ j ];
            permutation[ j ] = -1;
            j = temp;
        }
    }
}
int main() {
    vector<char> alphabet;
    alphabet.push_back( 'a' );
    alphabet.push_back( 'b' );
    alphabet.push_back( 'c' );
    alphabet.push_back( 'd' );
    vector<int> permutation;
    permutation.push_back( 3 );
    permutation.push_back( 2 );
    permutation.push_back( 1 );
    permutation.push_back( 0 );
    permute( alphabet, permutation );
    for( int i = 0; i < permutation.size(); i++ ) {
        cout << alphabet[ i ] << endl;
    }
    return 0;
}
