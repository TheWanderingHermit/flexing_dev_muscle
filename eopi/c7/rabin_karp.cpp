#include <iostream>
#include <string>
#include <cmath>

using namespace std;

unsigned long init_hash( string & search_string ) {
    unsigned long code = 0;
    int curr_index     = 0;
    while( curr_index < search_string.size() ) {
        code *= 26;
        code += search_string[ curr_index ] - 'A' + 1;
        curr_index++;
    }
    return code;
}
unsigned long next_hash( unsigned long code, int strlen, char prev_char, char next_char ) {
    static unsigned long dist = ( unsigned long )( pow( 26, strlen - 1 ) );
    code = code - ( dist * ( prev_char - 'A' + 1 ) );
    code *= 26;
    code += next_char - 'A' + 1;
    return code;
}
int search( string & text, string & search_string ) {
    unsigned long search_digest = init_hash( search_string );
    int bidx = 0, eidx = search_string.size();
    string init_text = text.substr( bidx, eidx );
    unsigned long text_digest = init_hash( init_text );
    while( eidx < text.size() ) {
        if( text_digest == search_digest )
            break;
        text_digest = next_hash( text_digest, search_string.size(), text[ bidx ], text[ eidx ] );
        bidx++;
        eidx++;
    }
    if( eidx == text.size() )
        return -1;
    return bidx;
}
int main() {
    string text = "ABCDEHUNDSHASJHDUEKHNLNLJNSDJGLNLJNLUHAKHHLAIEJNHKHCNKQPLEUXGEXYJKKABNM<XCVBNMSDFGHJKOIUYTREDFGHNMNBVCFGHIJKLMNOPQRSTUVWXYZABDMAZZFT";
    string search_string = "QPLEUXGEXYF";
    cout << search( text, search_string ) << endl;
    return 0;
}
