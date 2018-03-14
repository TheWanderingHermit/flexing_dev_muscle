#include "binary_tree.h"
#include <iostream>

int height( binary_tree_node * root ) {
    if( nullptr == root )
        return 0;
    return 1 + std::max( height( root->left ), height( root->right ) );
}
int main() {
    binary_tree_node * root = build_test_binary_tree();
    std::cout << height( root ) << std::endl;
    return 0;
}
