#include <iostream>
#include <vector>
#include "interval.h"
using namespace std;

void p( vector<marker> & markers ) {
    for( vector<marker>::iterator mitr = markers.begin(); mitr != markers.end(); mitr++ ) {
        cout << mitr->t << " " << mitr->s << endl; 
    }
}
int count_max_conc_events( vector<event> & events ) {
    int max_conc_events = 0, curr_conc_events = 0;
    vector<marker> markers;
    for( vector<event>::iterator eitr = events.begin(); eitr != events.end(); eitr++ ) {
        markers.push_back( marker( eitr->s, true ) );
        markers.push_back( marker( eitr->e, false ) );
    }
    sort( markers.begin(), markers.end() );
    for( vector<marker>::iterator mitr = markers.begin(); mitr != markers.end(); mitr++ ) {
        if( mitr->s ) {
            curr_conc_events++;
            max_conc_events = max( max_conc_events, curr_conc_events );
        }
        else if( curr_conc_events > 0 ){
            curr_conc_events--;
        }
    }
    return max_conc_events;
}
int main() {
    vector<event> events;
    events.push_back(event(1, 5));
    events.push_back(event(2, 7));
    events.push_back(event(4, 5));
    events.push_back(event(6, 10));
    events.push_back(event(8, 9));
    events.push_back(event(9, 17));
    events.push_back(event(11, 13));
    events.push_back(event(12, 15));
    events.push_back(event(14, 15));
    cout << count_max_conc_events( events ) << endl;
    return 0;
}
