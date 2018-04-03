#include <iostream>

long long GCD( long long x, long long y ) {
    return y == 0 ? x : GCD( y, x % y );
}
int main() {
    std::cout << GCD( 156, 36 ) << std::endl;
    return 0;
}
