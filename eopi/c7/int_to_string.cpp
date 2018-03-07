#include <iostream>
#include <string>

using namespace std;

string int_to_string( int i ) {
    bool is_neg = false; string s;
    if( i < 0 ) {
        is_neg = true;
        i *= -1;
    }
    do{
        s += '0' + i % 10;
        i /= 10;
    }
    while( i );
    if( is_neg )
        s += '-';
    reverse( s.begin(), s.end() );
    return s;
}
int main() {
    cout << int_to_string( 643 ) << endl;
    cout << int_to_string( -643 ) << endl;
    return 0;
}
