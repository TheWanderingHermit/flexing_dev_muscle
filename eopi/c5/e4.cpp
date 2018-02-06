#include <iostream>

char swap( char x, int i, int j ) {
    if( ( ( x >> i ) & 0x1 ) != ( ( x >> j ) & 0x1 ) ) {
        x ^= ( 0x1 << i ) | ( 0x1 << j );
    }
    return x;
}
char reverse1( char x ) {
    for( int i = 0, j = -1 + sizeof( char ) * 8; i <= j / 2; i++ ) {
        x = swap( x, i, j - i );
    }
    return x;
}
const char lookup[] = { 0, 2, 1, 3 };
char reverse2( char x ) {
    char r = 0;
    for( char m = 0x3, c = -1 + sizeof( char ) * ( 8 / 2 ); x > 0; x >>= 2, c-- ) {
        r |= lookup[ x & m ] << ( c * 2 );
    }
    return r;
}
int main() {
    std::cout << ( unsigned int )reverse1( char( 10 ) ) << std::endl;
    std::cout << ( unsigned int )reverse2( char( 10 ) ) << std::endl;
    return 0;
}
