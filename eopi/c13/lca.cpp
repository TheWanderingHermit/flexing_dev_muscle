#include <iostream>
#include <unordered_set>
#include "binary_tree.h"

using namespace std;

binary_tree_node * lca( binary_tree_node * root, int a, int b ) {
    unordered_set< binary_tree_node * > visited_nodes;
    binary_tree_node * t1 = find_node( root, a );
    binary_tree_node * t2 = find_node( root, b );
    while( t1 || t2 ) {
        if( t1 ) {
            if( visited_nodes.find( t1 ) != visited_nodes.end() )
                return t1;
            visited_nodes.insert( t1 );
            t1 = t1->parent;
        }
        if( t2 ) {
            if( visited_nodes.find( t2 ) != visited_nodes.end() )
                return t2;
            visited_nodes.insert( t2 );
            t2 = t2->parent;
        }
    }
    return nullptr;
}
int main() {
    binary_tree_node * root = build_test_binary_tree();
    binary_tree_node * lcan = lca( root, 27, 7 );
    if( nullptr != lcan ) {
        cout << lcan->data << endl;
    }
    return 0;
}
