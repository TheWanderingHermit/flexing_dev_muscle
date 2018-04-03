#include <iostream>

long long tower_of_hanoi( int n ) {
    if( n == 0 || n == 1 )
        return n;
    return 1 + 2 * tower_of_hanoi( n - 1 );
}
int main() {
    std::cout << tower_of_hanoi( 5 ) << std::endl;
}
