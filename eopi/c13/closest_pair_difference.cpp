#include<iostream>
#include<unordered_map>
#include<limits>
#include<vector>

using namespace std;

int closest_pair_difference( vector<string> & paragraph ) {
    int closest_distance = numeric_limits<int>::max();
    unordered_map<string, int> last_seen_index;
    for( int citr = 0; citr < paragraph.size(); citr++ ) {
        string & curr_word = paragraph[ citr ];
        if( last_seen_index.find( curr_word ) == last_seen_index.end() ) {
            last_seen_index[ curr_word ] = citr;
        }
        else {
            closest_distance = min( closest_distance, citr - last_seen_index[ curr_word ] );
            last_seen_index[ curr_word ] = citr;
        }
    }
    return closest_distance;
}

int main() {
    vector<string> paragraph;
    paragraph.push_back( "mary" );
    paragraph.push_back( "had" );
    paragraph.push_back( "a" );
    paragraph.push_back( "had" );
    paragraph.push_back( "mary" );
    cout << closest_pair_difference( paragraph ) << endl;
    return 0;
}
