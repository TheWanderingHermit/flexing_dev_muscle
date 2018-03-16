#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class string_priority {
    public :
        string str;
        int priority;
        string_priority( string str, int priority ) : str( str ), priority( priority ) {}
};
struct string_priority_cmp {
    bool operator()( const string_priority & lhs, const string_priority & rhs ) const {
        return lhs.priority < rhs.priority;
    }
};
priority_queue<string_priority, std::vector<string_priority>, string_priority_cmp > highest_k_frequency_words( vector<string> & word_list, int k ) {
    unordered_map<string, int> word_freq;
    for( vector<string>::iterator vitr = word_list.begin(); vitr != word_list.end(); vitr++ ) {
        if( word_freq.find( *vitr ) == word_freq.end() ) 
            word_freq[ *vitr ] = 1;
        else
            word_freq[ *vitr ]++;
    }
    priority_queue<string_priority, std::vector<string_priority>, string_priority_cmp > k_high_freq_words;
    int processed_elements = 0;
    for( unordered_map<string, int>::iterator mitr = word_freq.begin(); mitr != word_freq.end(); mitr++ ) {
        if( processed_elements < k ) {
            k_high_freq_words.push( string_priority( mitr->first, mitr->second ) );
            processed_elements++;
            continue;
        }
        if( mitr->second > k_high_freq_words.top().priority ) {
            k_high_freq_words.pop();
            k_high_freq_words.push( string_priority( mitr->first, mitr->second ) );
        }
    }
    return k_high_freq_words;
}
