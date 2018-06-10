#include<iostream>
#include<vector>

using namespace std;

int ugly( int n ) {
    int s[ n ];
    int mul2idx = 0;
    int mul3idx = 0;
    int mul5idx = 0;
    int mul2    = 2;
    int mul3    = 3;
    int mul5    = 5;
    s[ 0 ] = 1;
    for( int i = 1; i < n; i++ ) {
        s[ i ] = min( mul2, min( mul3, mul5 ) );
        if( s[ i ] == mul2 ) {
            mul2idx++;
            mul2 = s[ mul2idx ] * 2;
        }
        else if( s[ i ] == mul3 ) {
            mul3idx++;
            mul3 = s[ mul3idx ] * 3;
        }
        else{
            mul5idx++;
            mul5 = s[ mul5idx ] * 5;
        }
    }
    return s[ n - 1 ];
}
int main() {
    cout << ugly( 150 ) << endl;
    return 0;
}
