#include <iostream>

typedef unsigned long ulong;
typedef unsigned int uint;

#define BAD_SIZEOF(x) ((&x + 1) - &x)               //
#define SIZEOF(x) ((char *)(&x + 1) - (char *)&x)   // pointer arithmetic works on units of type being pointed to

uint sizeLong() {
    uint n = 0;
    for( ulong x = 0x1L; x != 0; x <<= 1 ) {
        n++;
    }
    return n / 8;
}

// Brute force parity check
short p1( ulong x ) {
    short p = 0;
    for( ; x > 0; x >>= 1 ) {
        p ^= ( x & 0x1 ); 
    }
    return p;
}

// Unset lowest bit of a number
// x - 1 toggles the lowest set bit 
// 01 - 01 = 00
// 10 - 01 = 01
// 11 - 01 = 10

inline ulong u( ulong x ) {
    return ( x & ( x - 1 ) );
}
// I tried using p = ~p inside the loop. The answer was -1!
short p2( ulong x ) {
    short p = 0;
    for( ; x > 0; x = u( x ) ) {
        p ^= 1;
    }
    return p;
}
// 2 bit parity lookup table
// 0 0 0
// 0 1 1
// 1 0 1
// 1 1 0
const short t[] = { 0, 1, 1, 0 };
short p3( uint x ) {
    short p = 0;
    uint m = 0x0003;
    for( ; x > 0; x >>= 2 ) {
        p ^= t[ x & m ];
    }
    return p;
}
short p4( ulong x ){
    uint  s = 4 * SIZEOF( x );
    for( ; s >= 1; s = s / 2 ){
        x ^= x >> s;
    }
    return x & 0x1;
}
int main() {
    std::cout << p1( 948342534 ) << std::endl;
    std::cout << p2( 948342534 ) << std::endl;
    std::cout << p3( 948342534 ) << std::endl;
    std::cout << p4( 948342534 ) << std::endl;
    return 0;
}
