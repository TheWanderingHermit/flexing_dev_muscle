#include<iostream>
#include<vector>
using namespace std;

vector<int> find_intersection(vector<int> & a, vector<int> & b) {
    vector<int> r;
    for( int i = 0, j = 0; i < a.size() && j < b.size(); ) {
        if( a[ i ] == b[ j ] ) {
            r.push_back( a[ i ] );
            i++; j++;
        }
        else if( a[ i ] < b[ j ] ) {
            i++;
        }
        else {
            j++;
        }
    }
    return r;
}
int main() {
    vector<int> a;
    vector<int> b;
    a.push_back( 1 );
    a.push_back( 2 );
    a.push_back( 4 );
    a.push_back( 6 );
    a.push_back( 8 );
    a.push_back( 9 );
    a.push_back( 10 );
    a.push_back( 12 );
    b.push_back( 2 );
    b.push_back( 4 );
    b.push_back( 7 );
    b.push_back( 8 );
    b.push_back( 10 );
    b.push_back( 11 );
    vector<int> r = find_intersection( a, b );
    for( int i = 0; i < r.size(); i++ ) {
        cout << r[ i ] << endl;
    }
}
