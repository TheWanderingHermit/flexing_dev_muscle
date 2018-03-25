#include <iostream>
#include "bst.h"
using namespace std;

bst_node * search( bst_node * t, int k ) {
    while( t ) {
        if( k == t->d )
            return t;
        else if( k < t->d ) {
            t = t->l; }
        else {
            t = t->r; }
    }
    return nullptr;
}

int main() {
    bst_node * t = spawn_test_bst();
    bst_node * a = search( t, 41 );
    cout << a->d << endl;
    return 0;
}
