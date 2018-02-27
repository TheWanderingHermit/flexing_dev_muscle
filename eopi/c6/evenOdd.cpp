#include <iostream>
#include <vector>

void evenOdd( std::vector< int >& container ) {
    int curr_even = 0, curr_odd = container.size();
    while( curr_even < curr_odd ) {
        if( container[ curr_even ] % 2 == 0 ) {
            curr_even++;
        }
        else {
            int temp = container[ curr_odd ];
            container[ curr_odd ] = container[ curr_even ];
            container[ curr_even ] = temp;
            curr_odd--;
        }
    }
}

int main() {
    std::vector< int > container;
    container.push_back( 2 );
    container.push_back( 1 );
    container.push_back( 5 );
    container.push_back( 6 );
    container.push_back( 7 );
    container.push_back( 0 );
    container.push_back( 2 );
    container.push_back( 1 );
    container.push_back( 10 );
    evenOdd( container );
    for( int i = 0; i < container.size(); i++ ) {
        std::cout << container[ i ] << std::endl;
    }
    return 0;
}
