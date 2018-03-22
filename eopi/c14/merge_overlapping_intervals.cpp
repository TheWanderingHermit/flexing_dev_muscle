#include <iostream>
#include <vector>

#include "interval.h"

using namespace std;

void p( vector<event> & events ) {
    for(vector<event>::iterator eitr = events.begin(); eitr != events.end(); eitr++ ) {
        cout << eitr->s << " " << eitr->e << endl;
    }
}
vector<event> merge_overlapping_intervals( vector<event> & events ) {
    vector<event> result;
    sort( events.begin(), events.end() );
    vector<event>::iterator vitr = events.begin();
    int cs = vitr->s, ce = vitr->e; vitr++;
    while( vitr != events.end() ) {
        if( vitr->s > ce ) {
            result.push_back( event( cs, ce ) );
            cs = vitr->s;
            ce = vitr->e;
        }
        else{
            ce = max( vitr->e, ce );
        }
        vitr++;
    }
    result.push_back( event( cs, ce ) );
    return result;
}
int main() {
    vector<event> events;
    events.push_back(event(1, 5));
    events.push_back(event(4, 5));
    events.push_back(event(6, 10));
    events.push_back(event(8, 9));
    events.push_back(event(9, 17));
    events.push_back(event(11, 13));
    events.push_back(event(12, 15));
    events.push_back(event(14, 15));
    vector<event> r = merge_overlapping_intervals( events );
    p( r );
    return 0;
}
