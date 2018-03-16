#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void find_anagrams( vector<string>& dictionary ) {
    unordered_map< string, vector< string > > anagrams;
    for( vector<string>::iterator vitr = dictionary.begin(); vitr != dictionary.end(); vitr++ ) {
        string s = *vitr;
        string k( s );
        std::sort( k.begin(), k.end() );
        anagrams[ k ].push_back( s );
    }
    for( unordered_map< string, vector< string > >::iterator mitr = anagrams.begin(); mitr != anagrams.end(); mitr++ ) {
        std::cout << "anagrams of sort key " << mitr->first << std::endl;
        vector<string>& s = mitr->second;
        for( vector< string >::iterator vitr = s.begin(); vitr != s.end(); vitr++ ) {
            std::cout << *vitr << std::endl;
        }
    }
}

int main() {
    vector< string > dictionary;
    dictionary.push_back( string( "abc" ) );
    dictionary.push_back( string( "bac" ) );
    dictionary.push_back( string( "def" ) );
    dictionary.push_back( string( "dfe" ) );
    dictionary.push_back( string( "mot" ) );
    dictionary.push_back( string( "toa" ) );
    find_anagrams( dictionary );
    return 0;
}
