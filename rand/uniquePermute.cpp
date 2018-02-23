#include<iostream>
#include<vector>

void vswap( std::vector<char>& a, int i, int j ) {
    char temp = a[ i ];
    a[ i ] = a[ j ];
    a[ j ] = temp;
}
void uniquePermute( std::vector<char>& a, int i ) {
    if( i == ( a.size() - 1 ) ) {
        for( int j = 0; j < a.size(); j++ ) {
            std::cout << a[ j ];
        }
        std::cout << std::endl;
    }
    else {
        uniquePermute( a, i + 1 );
        for( int k = i + 1; k < a.size(); k++ ) {
            vswap( a, i, k );
            uniquePermute( a, i + 1 );
            vswap( a, i, k );
        }
    }
}
int main() {
    std::vector<char> a;
    a.push_back( 'A' );
    a.push_back( 'B' );
    a.push_back( 'C' );
    uniquePermute( a, 0 );
}
