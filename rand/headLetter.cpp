#include <iostream>
#include <string>
#include <limits>
#include <cstring>

char headLetter( std::string & word ) {
    int letterCount[ 26 ];
    int headIndex[ 26 ];
    int maxInt = std::numeric_limits<int>::max();
    for( int i = 0; i < 26; i++ ) {
        letterCount[ i ] = 0;
        headIndex[ i ] = maxInt;
    }
    for( int itr = 0; itr < word.size(); itr++ ) {
        letterCount[ word.at( itr ) - 'a' ]++;
        if( headIndex[ word.at( itr ) - 'a' ] == maxInt ) {
            headIndex[ word.at( itr ) - 'a' ] = itr;
        }
    }
    while( true ) {
        int minIdx = -1;
        int minVal = maxInt;
        for( int itr = 0; itr < 26; itr++ ) {
            if( headIndex[ itr ] < minVal ) {
                minVal = headIndex[ itr ];
                minIdx = itr;
            }
        }
        if( minVal == maxInt ) break;
        else if( letterCount[ minIdx ] == 1 ) {
            return 'a' + minIdx;
        }
        else{
            headIndex[ minIdx ] = maxInt;
        }
    }
    return '\0';
}

int main() {
    std::string word = "helloh";
    std::cout << headLetter( word ) << std::endl;
    return 0;
}
