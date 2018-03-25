#include <iostream>
#include "bst.h"

using namespace std;

bst_node * find_first_gt_k( bst_node * t, int k) {
    bst_node * first_so_far = nullptr;
    while( t ) {
        if( k < t->d ) {
            first_so_far = t;
            t = t->l;
        } else {
            t = t->r;
        }
    }
    return first_so_far;
}
int main() {
    bst_node * a = find_first_gt_k( spawn_test_bst(), 21 );
    if( nullptr != a ) {
        cout << a->d << endl;
    } else {
        cout << numeric_limits<int>::min() << endl;
    }
    return 0;
}
