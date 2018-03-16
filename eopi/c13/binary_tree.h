#ifndef __BINARY_TREE_H_
#define __BINARY_TREE_H_
#include <cstddef>
class binary_tree_node {
    public :
        int data;
        binary_tree_node * parent;
        binary_tree_node * left, * right;
        binary_tree_node( int data ) : data( data ), parent( nullptr ), left( nullptr ), right( nullptr ) {}
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
    root->left->parent           = root;
    root->right->parent          = root;
    root->left->left->parent     = root->left;
    root->left->right->parent    = root->left;
    root->right->left->parent    = root->right;
    root->right->right->parent    = root->right;
    root->left->left->left->parent = root->left->left;
    root->left->left->left->left->parent = root->left->left->left;
    return root;
}

// inorder traversal to find bintree node
binary_tree_node * find_node( binary_tree_node * root, int d ) {
    if( nullptr == root )
        return nullptr;
    else if( d == root->data ) 
        return root;
    binary_tree_node * left_s = find_node( root->left, d );
    if( nullptr != left_s )
        return left_s;
    else {
        return find_node( root->right, d );
    }
    return nullptr;
}
#endif
