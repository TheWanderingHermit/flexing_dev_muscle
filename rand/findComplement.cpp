#include <iostream>
#include <cmath>

using namespace std;

int findComplement( int num ) {
    int nabi = int( log2( num ) );
    int mask = 1 << ( nabi + 1 );
    return ( num ^ ( mask - 1 ) );
}
int main() {
    int num = 5;
    cout << findComplement( num ) << endl;
    return 0;
}
