#include <iostream>
#include <string>

using namespace std;

string run_length_encoding( string & decode ) {
    string encode;
    int count = 1, curr_idx = 1;
    while( curr_idx <= decode.size() ) {
        if( curr_idx == decode.size() || decode[ curr_idx - 1 ] != decode[ curr_idx ] ) {
            encode += to_string( count ) + decode[ curr_idx - 1 ];
            count = 1;
        }
        else 
            count++;
        curr_idx++;
    }
    return encode;
}
int main() {
    string decode = "aaaabbbccdeeeefffggh";
    cout << decode << endl;
    cout << run_length_encoding( decode ) << endl;
}
