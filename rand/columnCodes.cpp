#include <iostream>
#include <string>
#include <algorithm>

std::string columnCode( long columnIndex ) {
    std::string code;
    while( columnIndex > 0 ) {
        int leadChar = columnIndex % 26;
        if( leadChar == 0 ) {
            code.append( 1u, 'Z' );
            columnIndex = ( columnIndex / 26 ) - 1;
        }
        else {
            code.append( 1u, 'A' + leadChar - 1 );
            columnIndex = columnIndex / 26;
        }
    }
    std::reverse( code.begin(), code.end() );
    return code;
}

int main() {
    std::cout << columnCode( 26 ) << std::endl;
    std::cout << columnCode( 51 ) << std::endl;
    std::cout << columnCode( 52 ) << std::endl;
    std::cout << columnCode( 80 ) << std::endl;
    std::cout << columnCode( 676 ) << std::endl;
    std::cout << columnCode( 702 ) << std::endl;
    std::cout << columnCode( 705 ) << std::endl;
    return 0;
}
