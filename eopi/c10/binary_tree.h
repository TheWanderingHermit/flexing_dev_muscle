#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_
#include <cstddef>
class binary_tree_node {
    public :
        int data;
        binary_tree_node * left, * right;
        binary_tree_node( int data ) : data( data ), left( nullptr ), right( nullptr ) {}
};

binary_tree_node * build_test_binary_tree() {
    binary_tree_node * root      = new binary_tree_node( 23 );
    root->left                   = new binary_tree_node( 25 );
    root->right                  = new binary_tree_node( 27 );
    root->left->left             = new binary_tree_node( 1 );
    root->left->right            = new binary_tree_node( 32 );
    root->right->left            = new binary_tree_node( 19 );
    root->right->right           = new binary_tree_node( 18 );
    root->left->left->left       = new binary_tree_node( 2 );
    root->left->left->left->left = new binary_tree_node( 7 );
    return root;
}
#endif
