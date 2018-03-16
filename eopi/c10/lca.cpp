#include "binary_tree.h"
#include <iostream>

class rec {
    public :
        int c;
        binary_tree_node * a;
        rec( int c, binary_tree_node * a ) : c( c ), a( a ) {};
};
rec * lca( binary_tree_node * root, binary_tree_node * t1, binary_tree_node * t2 ) {
    if( nullptr == root )
        new rec( 0, nullptr );
    rec * l = lca( root->left, t1, t2 );
    if( l->c == 2 )
        return l;
    rec * r = lca( root->right, t1, t2 );
    if( r->c == 2 )
        return r;
    int c = l->c + r->c + (root == t1) + (root == t2);
    return new rec( c, c == 2 ? root : nullptr );
}
int main() {
    binary_tree_node * test_tree = build_test_binary_tree();
    binary_tree_node * t1        = find_node( test_tree, 2 );
    binary_tree_node * t2        = find_node( test_tree, 32 );
    std::cout << lca( test_tree, t1, t2 ) << std::endl;
    return 0;
}
