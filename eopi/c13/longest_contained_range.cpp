#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longest_contained_range( vector<int> & nums ) {
    unordered_set<int> seen;
    int s = 0;
    for( int i = 0; i < nums.size(); i++ ) {
        seen.insert( nums[ i ] );
    }
    while(!seen.empty()){
        int n = 1;
        int a = *seen.begin();
        n++;
        seen.erase(a);
        int l = a - 1;
        while(seen.find(l)!=seen.end()){
            n++;
            seen.erase(l);
            l--;
        }
        int u = a + 1;
        while(seen.find(u)!=seen.end()){
            n++;
            seen.erase(u);
            u--;
        }
        s = max( s, n );
    }
    return s;
}
int main() {
    vector<int> nums;
    nums.push_back( -5 );
    nums.push_back( -2 );
    nums.push_back( -1 );
    nums.push_back( -0 );
    nums.push_back( -1 );
    cout << longest_contained_range( nums ) << endl;
    return 0;
}
