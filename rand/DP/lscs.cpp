#include<iostream>
#include<vector>

using namespace std;

int lscs( vector<int> & a ) {
    int curr_max = 0, over_max = 0;
    for( vector<int>::iterator vitr = a.begin(); vitr != a.end(); vitr++ ) {
        curr_max += *vitr;
        if( curr_max < 0 )
            curr_max = 0;
        over_max = max( over_max, curr_max );
    }
    return over_max;
}
int main() {
    vector<int> a;
    a.push_back( -2 );
    a.push_back( -3 );
    a.push_back( 4 );
    a.push_back( -1 );
    a.push_back( -2 );
    a.push_back( 1 );
    a.push_back( 5 );
    a.push_back( -3 );
    cout << lscs( a ) << endl;
    return 0;
}
