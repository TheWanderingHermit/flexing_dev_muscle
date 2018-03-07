#include <iostream>
#include <string>

using namespace std;

string convert_base( const string& num, int base1, int base2 ) {
    unsigned long long i = 0;
    bool is_neg = num.front() == '-' ? true : false;
    int msb_idx = is_neg ? 1 : 0;
    string r;
    for( int j = msb_idx; j < num.size(); j++ ) {
        i *= base1;
        i += num[ j ] - '0';
    }
    do {
        r += ( i % base2 ) + '0';
        i /= base2;
    }
    while( i );
    if( is_neg )
        r += '-';
    reverse( r.begin(), r.end() );
    return r;
}
int main() {
    cout << convert_base( "102", 3, 4 ) << endl;
    return 0;
}
