#include "binary_tree.h"
#include <iostream>

bool root_to_leaf_sum( binary_tree_node * root, int sum, int curr_sum ) {
    if( nullptr == root )
        return false;
    curr_sum = curr_sum + root->data;
    if( curr_sum == sum && nullptr == root->left && nullptr == root->right )
        return true;
    return root_to_leaf_sum( root->left, sum, curr_sum ) || root_to_leaf_sum( root->right, sum, curr_sum );
}
int main() {
    binary_tree_node * test_tree = build_test_binary_tree();
    std::cout << root_to_leaf_sum( test_tree, 81, 0 ) << std::endl;
    return 0;
}
