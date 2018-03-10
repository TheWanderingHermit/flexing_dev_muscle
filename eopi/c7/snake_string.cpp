#include <iostream>
#include <string>

using namespace std;
string snake_string( string& v ) {
    string r;
    for( int i = 1; i < v.size(); i += 4 ) {
        r += v[ i ];
    }
    for( int i = 0; i < v.size(); i += 2 ) {
        r += v[ i ];
    }
    for( int i = 3; i < v.size(); i += 4 ) {
        r += v[ i ];
    }
    return r;
}
int main() {
    string v = "Hello_World";
    cout << snake_string( v ) << endl;
}
