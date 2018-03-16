#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool permuted_palindrome( string& word ) {
    unordered_map< char, int > letter_count;
    for( int i = 0; i < word.size(); i++ ) {
        if( letter_count.find( word[ i ] ) == letter_count.end() ) {
            letter_count[ word[ i ] ] = 1;
        }
        else {
            letter_count[ word[ i ] ]++;
        }
    }
    int odd_count = 0;
    for( unordered_map< char, int >::iterator mitr = letter_count.begin(); mitr != letter_count.end(); mitr++ ) {
        if( mitr->second % 2 != 0 )
            odd_count++;
    }
    if( odd_count > 1 ) {
        return false;
    }
    return true;
}
int main() {
    string word = "edified";
    cout << permuted_palindrome( word ) << endl;
    return 0;
}
