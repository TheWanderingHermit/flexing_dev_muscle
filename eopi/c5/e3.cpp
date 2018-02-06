#include <iostream>

//This method swaps bits i + 1 and j + 1 positions
unsigned int s1( unsigned int x, unsigned int i, unsigned int j ){
    unsigned int mi = 1 << i, mj = 1 << j;
    unsigned int bi = ( ( x & mi ) >> i ) << j, bj = ( ( x & mj ) >> j ) << i;
    return ( ( x & ~( mi | mj ) ) | ( bi | bj ) );
}
// swap bits the smart way
// premise -
//  toggle bits only if they are different. 
//  1 XOR x toggles x

unsigned int s2( unsigned int x, unsigned int i, unsigned int j ){
    if( ( ( x >> i ) & 1 ) != ( ( x >> j ) & 1 ) ) {
        x ^= ( 1 << i ) | ( 1 << j );
    }
    return x;
}

int main(){
    std::cout << s1( 20, 4, 3 ) << std::endl;
    std::cout << s2( 20, 4, 3 ) << std::endl;
    return 0;
}
