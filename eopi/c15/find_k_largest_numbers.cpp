#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

void find_k_largest_numbers( bst_node * t, int k, vector<int> & nums ) {
        if( nullptr != t && nums.size() < k ) {
            find_k_largest_numbers( t->r, k, nums );
            if( nums.size() < k ) {
                nums.push_back( t->d );
                find_k_largest_numbers( t->l, k, nums );
            }
        }
}
int main() {
    vector<int> nums;
    find_k_largest_numbers( spawn_test_bst(), 4, nums );
    for( int i = 0; i < nums.size(); i++ ) {
        cout << nums[ i ] << endl;
    }
    return 0;
}
