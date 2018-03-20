#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

pair<int, int> longest_distinct_subarray( vector<char> & chars ) {
    pair<int, int> r = make_pair( -1, -1 );
    unordered_map<char, int> most_recent;
    int s = 0, e = 0;
    for( ; e < chars.size(); e++ ) {
        if( most_recent.find( chars[ e ] ) != most_recent.end() && most_recent[ chars[ e ] ] >= s ) {
            if( e - s > r.second - r.first ) {
                r.second = e;
                r.first  = s;
            }
            s = most_recent[ chars[ e ] ] + 1;
        }
        most_recent[ chars[ e ] ] = e;
    }
    if( e - s > r.second - r.first ) {
        r.first  = s;
        r.second = e;
    }
    return r;
}
int main() {
    vector<char> chars;
    chars.push_back( 'a' );
    chars.push_back( 'a' );
    chars.push_back( 'c' );
    chars.push_back( 'd' );
    chars.push_back( 'e' );
    chars.push_back( 'f' );
    chars.push_back( 'g' );
    chars.push_back( 'h' );
    chars.push_back( 'i' );
    pair<int, int> r = longest_distinct_subarray( chars );
    cout << r.first << endl;
    cout << r.second << endl;
    return 0;
}
