#include <iostream>
#include <vector>
#include <string>

using namespace std;

void compute_mnemonic( vector< int >& phone_number, int next_num_idx, string partial_mnemonic ) {
    if( phone_number.size() == next_num_idx ) {
        cout << partial_mnemonic << endl;
        return;
    }
    if( phone_number[ next_num_idx ] == 0 || phone_number[ next_num_idx ] == 1 ) {
        partial_mnemonic += '0' + phone_number[ next_num_idx ];
        compute_mnemonic( phone_number, next_num_idx + 1, partial_mnemonic ); 
    }
    else {
        for( int i = 0; i < 3; i++ ) {
            string next_partial_mnemonic = partial_mnemonic;
            next_partial_mnemonic += 'A' + ( 3 * ( phone_number[ next_num_idx ] - 2 ) ) + i;
            compute_mnemonic( phone_number, next_num_idx + 1, next_partial_mnemonic  );
        }
    }
}
void init( vector< int >& phone_number ) {
    compute_mnemonic( phone_number, 0, string() );
}
int main() {
    vector< int > phone_number;
    phone_number.push_back( 5 );
    phone_number.push_back( 1 );
    phone_number.push_back( 8 );
    phone_number.push_back( 2 );
    phone_number.push_back( 6 );
    phone_number.push_back( 8 );
    phone_number.push_back( 0 );
    phone_number.push_back( 1 );
    phone_number.push_back( 0 );
    phone_number.push_back( 9 );
    init( phone_number );
    return 0;
}
