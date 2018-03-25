#include <iostream>
#include "bst.h"

using namespace std;
bst_node * lca( bst_node * t, int a, int b ) {
    int c = min( a, b );
    int d = max( a, b );
    while( t ) {
        if( t->d >= c && t->d <= d ) {
            return t;
        } else if( t->d > c && t->d > d ) {
            t = t->l;
        } else {
            t = t->r;
        }
    }
    return nullptr;
}
int main() {
    bst_node * result = lca( spawn_test_bst(), 3, 17 );
    cout << result->d << endl;
    return 0;
}
