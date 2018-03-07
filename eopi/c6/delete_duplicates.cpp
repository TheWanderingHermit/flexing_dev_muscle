#include<iostream>
#include<vector>
using namespace std;

void delete_duplicates( vector<int>* operands ) {
    vector<int>& A = *operands;
    int next_clean = 1;
    for( int i = 1; i < A.size(); i++ ) {
        if( A[ next_clean - 1 ] != A[ i ] ) {
            A[ next_clean ] = A[ i ];
            next_clean++;
        }
    }
}
int main() {
    vector<int> operands;
    operands.push_back( 0 );
    operands.push_back( 10 );
    operands.push_back( 10 );
    operands.push_back( 10 );
    operands.push_back( 10 );
    operands.push_back( 20 );
    operands.push_back( 20 );
    delete_duplicates( &operands );
    for( int i = 0; i < operands.size(); i++ ) {
        cout << operands[ i ] << endl;
    }
}
