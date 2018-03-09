#include <iostream>
#include <string>

using namespace std;

bool is_valid( string s ) {
    if( s.size() > 3 )
        return false;
    if( s.front() == '0' && s.size() > 1 )
        return false;
    int val = stoi( s );
    return val <= 255 && val >= 0;
}
void get_valid_ip_addresses( const string& candidate_ip_addresses ) {
    for( int i = 1 ; i < 4; i++ ) {
        string comp1 = candidate_ip_addresses.substr( 0, i );
        if( !is_valid( comp1 ) )
                continue;
        for( int j = 1; j < 4 && i + j < candidate_ip_addresses.size(); j++ ) {
            string comp2 = candidate_ip_addresses.substr( i, j );
            if( !is_valid( comp2 ) )
                continue;
            for( int k = 1; k < 4 && i + j + k < candidate_ip_addresses.size(); k++ ) {
                string comp3 = candidate_ip_addresses.substr( i + j, k );
                string comp4 = candidate_ip_addresses.substr( i + j + k );
                if( !is_valid( comp3 ) || !is_valid( comp4 ) )
                    continue;
                cout << comp1 << '.' << comp2 << '.' << comp3 << '.' << comp4 << endl;
            }
        }
    }
}
int main() {
    string candidate_ip_addresses = "19216811";
    get_valid_ip_addresses( candidate_ip_addresses );
    return 0;
}
