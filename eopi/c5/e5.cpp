#include <iostream>
/*
 * program to perform x * y using only addition and bit shift
 * Here we use the idea that y can be represented as 2^a + 2^b + 2^c... for some a, b, c...
 * x*2^a is equivalent to x << a
 * this is a variation of the original problem in the book
 * */

int multiply( int x, int y ) {
    int c = 0;
    int r = 0;
    while( y ) {
        if( y & 1 ) {
            r += x << c;
        }
        c++; y >>= 1;
    }
    return r;
}
int main() {
    std::cout << multiply( 2, 3 ) << std::endl;
}
