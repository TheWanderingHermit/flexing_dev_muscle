#include <iostream>
#include <vector>

using namespace std;

vector< int > compute_primes( int n ) {
    vector< bool > candidate_primes( n + 1, true );
    candidate_primes[ 0 ] = false, candidate_primes[ 1 ] = false;
    vector< int > primes;
    for( int i = 2; i <= n; i++ ) {
        if( candidate_primes[ i ] == true ) 
            primes.push_back( i );
        for( int j = i; j <= n; j += i ) 
            candidate_primes[ j ] = false;
    }
    return primes;
}
int main() {
    vector< int > primes = compute_primes( 31 );
    for( int i = 0; i < primes.size(); i++ ){
        cout << primes[ i ] << endl;
    }
    return 0;
}
