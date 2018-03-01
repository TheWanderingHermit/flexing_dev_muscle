#include <iostream>
/*
 * check if number is palindrome
 * instead of reversing the whole number, reverse the half and check if its equal to other half
 * */

bool is_num_palindrome( int num ) {
    if( num < 0 || ( num % 10 ) == 0 ) 
        return false;
    int r = 0;
    while( r < num ) {
        r = r * 10 + ( num % 10 );
        num = num / 10;
    }
    if( r == num ) 
        return true;
    else if( ( r / 10 ) == num )
        return true;
    return false;
}

int main() {
    std::cout << is_num_palindrome( 101 ) << std::endl;
    std::cout << is_num_palindrome( 1010 ) << std::endl;
    std::cout << is_num_palindrome( 2002 ) << std::endl;
    std::cout << is_num_palindrome( 10101 ) << std::endl;
    return 0;
}
