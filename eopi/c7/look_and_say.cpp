#include <iostream>
#include <string>

using namespace std;

string next_number( string s ) {
    string r;
    for( int i = 0; i < s.size(); i++ ) {
        int count = 1;
        while( i + 1 < s.size() && s[ i ] == s[ i + 1 ] ) {
            i++;
            count++;
        }
        r += to_string( count ) + s[ i ];
    }
    return r;
}
string look_and_say( int n ) {
    string s = "1";
    for( int i = 1; i < n; i++ ) {
        s = next_number( s );
    }
    return s;
}
int main() {
    cout << look_and_say( 12 ) << endl;
    return 0;
}
