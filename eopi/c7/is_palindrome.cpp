#include <iostream>
#include <string>

using namespace std;

bool is_palindrome( const string& w ) {
    for( int i = 0, j = w.size() - 1; i < j; i++, j-- ) {
        if( w[ i ] != w[ j ] )
            return false;
    }
    return true;
}

int main() {
    string pal = "abcdedcba";
    string npa = "abcdcb";

    cout << is_palindrome( pal ) << endl;
    cout << is_palindrome( npa ) << endl;
    return 0;
}
