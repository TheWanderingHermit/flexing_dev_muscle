#include <iostream>
#include <vector>
#include "interval.h"

using namespace std;

void p( vector<event> & e ) {
    for(vector<event>::iterator vitr = e.begin(); vitr != e.end(); vitr++ ) {
        cout << vitr->s << " " << vitr->e << endl;
    }
}
vector<event> add_intervals( vector<event> & events, event & addon ) {
    vector<event> r;
    vector<event>::iterator eitr = events.begin();
    while( eitr != events.end() ) {
        if( eitr->e < addon.s || eitr->s > addon.e ) {
            r.push_back( *eitr );
            eitr++;
        }
        else {
            int s = min( eitr->s, addon.s ), e = addon.e;
            while( eitr != events.end() && eitr->s < addon.e ) {
                e = max( eitr->e, e );
                eitr++;
            }
            r.push_back( event( s, e ) );
        }
    }
    return r;
}
int main() {
    vector<event> events;
    events.push_back( event( -4, -1 ) );
    events.push_back( event( 0, 2 ) );
    events.push_back( event( 3, 6 ) );
    events.push_back( event( 7, 9 ) );
    events.push_back( event( 11, 12 ) );
    events.push_back( event( 14, 17 ) );
    event addon = event( 1, 8 );
    vector<event> merger = add_intervals( events, addon );
    p( merger );
    return 0;
}
