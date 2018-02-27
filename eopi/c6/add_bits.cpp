#include <iostream>
#include <vector>

using namespace std;

vector<int> add_bits( vector<int> a, vector<int> b ) {
    int i = a.size() - 1, j = b.size() - 1;
    int l = i > j ? i : j, c = 0;
    l = l + 1;
    vector<int> sum( l + 1, 0 );
    while( i >= 0 || j >= 0 ) {
        int cs = 0;
        if( i >= 0 ) cs += a[ i ];
        if( j >= 0 ) cs += b[ j ];
        switch( cs ) {
            case 0:
                sum[ l ] = c;
                c = 0;
                break;
            case 1:
                if( c == 0 ) {
                    sum[ l ] = 1;
                    c = 0;
                }
                else {
                    sum[ l ] = 0;
                    c = 1;
                }
                break;
            case 2:
                if( c == 0 ) {
                    sum[ l ] = 0;
                    c = 1;
                }
                else {
                    sum[ l ] = 1;
                    c = 1;
                }
                break;
        }
        i--; j--; l--;
    }
    sum[ l ] = c;
    return sum;
}
int main() {
    vector<int> a;
    vector<int> b;
    a.push_back( 1 );
    a.push_back( 0 );
    a.push_back( 1 );
    b.push_back( 1 );
    b.push_back( 1 );
    vector< int > r = add_bits( a, b );
    for( int i = 0; i < r.size(); i++ ) {
        cout << r[ i ] << endl;
    }
}
