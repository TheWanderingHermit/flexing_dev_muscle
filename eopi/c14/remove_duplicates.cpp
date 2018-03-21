#include<iostream>
#include<vector>

using namespace std;

int remove_duplicates( vector<int> & awd ) {
    sort( awd.begin(), awd.end() );
    int write_idx = 1, i = 1;
    while( i < awd.size() ) {
        if( awd[ i - 1 ] != awd[ i ] ) {
            awd[ write_idx ] = awd[ i ];
            write_idx++;
        }
        i++;
    }
    return write_idx;
}
int main() {
    vector<int> a;
    a.push_back( 1 );
    a.push_back( 1 );
    a.push_back( 2 );
    a.push_back( 2 );
    a.push_back( 3 );
    a.push_back( 1 );
    a.push_back( 1 );
    int i = remove_duplicates( a );
    cout << i << endl;
    for( int j = 0; j < a.size(); j++ ) {
        cout << a[ j ] << endl;
    }
    return 0;
}
