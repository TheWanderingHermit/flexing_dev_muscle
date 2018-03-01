#include <iostream>
/*
 * Implementing x/y
 * */

int divide( int x, int y ) {
    int r = 0;
    int p = sizeof( int ) * 8;
    unsigned long long d = static_cast< unsigned long long >( y ) << p;
    while( x >= y ) {
        while( d > x ) {
            d >>= 1;
            --p;
        }
        r += 1U << p;;
        x -= d;
    }
    return r;
}
int main() {
    std::cout << divide( 6, 3 ) << std::endl;
}
