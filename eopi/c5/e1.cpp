#include <iostream>

typedef unsigned int uint;

// count the number of bits set in an unsigned integer
short countBits( uint x ){
    short num_bits = 0;
    for(; x > 0; x >>= 1 ){
        num_bits += x & 0x1;
    }
    return num_bits;
}
int main(){
    std::cout << countBits( 723  ) << std::endl;
    return 0;
}
