#include "binary_tree.h"
#include <iostream>
#include <stack>

void nonrecur_inorder( binary_tree_node * root ) {
    std::stack< binary_tree_node * > inorder_call_stack;
    while( !inorder_call_stack.empty() || root ) {
        if( root ) {
            inorder_call_stack.push( root );
            root = root->left;
        }
        else {
            root = inorder_call_stack.top();
            inorder_call_stack.pop();
            std::cout << root->data << std::endl;
            root = root->right;
        }
    }
}
int main() {
    binary_tree_node * test_tree = build_test_binary_tree();
    nonrecur_inorder( test_tree );
    return 0;
}
