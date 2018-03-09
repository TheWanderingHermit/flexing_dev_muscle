#include <iostream>
#include <string>

using namespace std;

int replace( string& word, char to_replace ) {
    int write_index = 0;
    for( int i = 0; i < word.size(); i++ ) {
        if( word[ i ] != to_replace ) {
            word[ write_index++ ] = word[ i ];
        }
    }
    return write_index;
}

int main() {
    string word = "modorcailocabocamoca";
    cout << replace( word, 'c' ) << endl;
    cout << word << endl;
}
