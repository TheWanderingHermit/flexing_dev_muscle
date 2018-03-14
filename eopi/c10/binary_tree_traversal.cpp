#include "binary_tree.h"

#include <iostream>

void inorder( binary_tree_node * root ) {
    if( nullptr == root )
        return;
    inorder( root->left );
    std::cout << root->data << std::endl;
    inorder( root->right );
}
void preorder( binary_tree_node * root ) {
    if( nullptr == root )
        return;
    std::cout << root->data << std::endl;
    preorder( root->left );
    preorder( root->right );
}
void postorder( binary_tree_node * root ) {
    if( nullptr == root )
        return;
    std::cout << root->data << std::endl;
    postorder( root->right );
    postorder( root->left );
}
int main() {
    binary_tree_node * test_tree = build_test_binary_tree();
    std::cout << "------" << std::endl;
    inorder( test_tree );
    std::cout << "------" << std::endl;
    preorder( test_tree );
    std::cout << "------" << std::endl;
    postorder( test_tree );
    std::cout << "------" << std::endl;
    return 0;
}
