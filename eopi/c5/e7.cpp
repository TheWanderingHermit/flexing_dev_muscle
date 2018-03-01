#include<iostream>
/*
 * implement x^y
 * understanding the logic
 * x^(1101) = x^(1000).x^(100).x^(1) = x^(2^3)+x^(2^2)+x
 * key: x^(2^y) = x^(2^y-1).x^(2^y-1)
 * */

double pow( double x, int y ) {
    double r = 1;
    long long p = y;
    if( p < 0 ) {
        x = 1 / x;
        p *= -1;
    }
    while( p ) {
        if( p & 1 ) {
            r *= x;
        }
        x *= x; p >>= 1;
    }
    return r;
}

int main() {
    std::cout << pow( 23.12, 5 ) << std::endl;
}
