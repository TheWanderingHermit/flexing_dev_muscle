#include<iostream>
#include<vector>

using namespace std;

int lcs( vector<int> & a, vector<int> & b ) {
    int solution[ a.size() + 1 ][ b.size() + 1 ];
    for( int i = 0; i <= a.size(); i++ ) {
        for( int j = 0; j <= b.size(); j++ ) {
            if( i == 0 || j == 0 ) {
                solution[ i ][ j ] = 0;
            }
            else if( i != j && a[ i ] == b[ j ] ) {
                solution[ i ][ j ] = 1 + solution[ i - 1 ][ j - 1];
            }
            else{
                solution[ i ][ j ] = max( solution[ i ][ j - 1 ], solution[ i - 1 ][ j ] );
            }
        }
    }
    return solution[ a.size() ][ b.size() ];
}
int main() {
    vector<int> a;
    a.push_back( 1 );
    a.push_back( 3 );
    a.push_back( 3 );
    a.push_back( 4 );
    a.push_back( 1 );
    a.push_back( 2 );
    cout << lcs( a, a ) << endl;
    return 0;
}
