#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply_ints( vector<int>& a, vector<int>& b ) {
    int sign_a = a[0] < 0 ? -1 : 1;
    int sign_b = b[0] < 0 ? -1 : 1;
    a[0] *= sign_a; b[0] *= sign_b;
    vector<int> r ( a.size() + b.size(), 0 );
    for( int i = a.size() - 1; i >= 0; i-- ) {
        for( int j = b.size() - 1; j >= 0; j-- ) {
            r[ i + j + 1 ] += a[ i ] * b [ j ];
            r[ i + j ] += r [ i + j + 1 ] / 10;
            r[ i + j + 1 ] %= 10;
        }
    }
    for( int i = 0; i < r.size(); i++ ) {
        if( r[ i ] != 0 ) {
            r[ i ] *= sign_a * sign_b;
            break;
        }
    }
    return r;
}
int main() {
    vector<int> a;
    vector<int> b;
    a.push_back( -7 );
    a.push_back( 2 );
    b.push_back( 1 );
    b.push_back( 2 );
    vector<int> r = multiply_ints( a, b ); 
    for( int i = 0; i < r.size(); i++ ) {
        std::cout << r[i] << std::endl;
    }
    return 0;
}
