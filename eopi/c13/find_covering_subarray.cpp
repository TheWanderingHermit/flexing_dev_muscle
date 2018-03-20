#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

pair<int, int> find_covering_subarray( vector<string> & paragraph, vector<string> & keywords ) {
    pair<int, int> result = make_pair( -1, -1 );
    unordered_map<string, int> keyword_freq;
    int remaining_keywords = keywords.size();
    for( vector<string>::iterator kitr = keywords.begin(); kitr != keywords.end(); kitr++ ) {
        keyword_freq[*kitr] = 0;
    }
    for( int l = 0, r = 0; r != paragraph.size(); r++ ) {
        if( keyword_freq.find( paragraph[ r ] ) != keyword_freq.end() ) {
            keyword_freq[ paragraph[ r ] ]++;
            if( keyword_freq[ paragraph[ r ] ] == 1 ) {
                remaining_keywords--;
            }
        }
        while( remaining_keywords == 0 ) {
            if( ( result.first == -1 && result.second == -1 ) || ( ( r - l ) < ( result.second - result.first ) ) ) {
                result.first  = l;
                result.second = r;
            }
            if( keyword_freq.find( paragraph[ l ] ) != keyword_freq.end() ) {
                keyword_freq[ paragraph[ l ] ]--;
                if( keyword_freq[ paragraph[ l ] ] == 0 ) {
                    remaining_keywords++;
                }
            }
            l++;
        }
    }
    return result;
}
int main() {
    vector<string> paragraph;
    paragraph.push_back( "mary" );
    paragraph.push_back( "mary" );
    paragraph.push_back( "lamb" );
    paragraph.push_back( "mary" );
    paragraph.push_back( "mary" );
    paragraph.push_back( "mary" );
    paragraph.push_back( "had" );
    paragraph.push_back( "lamb" );
    paragraph.push_back( "mary" );
    vector<string> keywords;
    keywords.push_back( "mary" );
    keywords.push_back( "had" );
    keywords.push_back( "lamb" );
    pair<int, int> r = find_covering_subarray( paragraph, keywords );
    cout << r.first << endl;
    cout << r.second << endl;
    return 0;
}
