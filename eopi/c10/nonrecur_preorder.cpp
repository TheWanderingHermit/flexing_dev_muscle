#include "binary_tree.h"
#include <iostream>
#include <stack>

void nonrecur_preorder( binary_tree_node * root ) {
    std::stack< binary_tree_node * > preorder_call_stack;
    preorder_call_stack.push( root );
    while( !preorder_call_stack.empty() ) {
        binary_tree_node * curr = preorder_call_stack.top();
        preorder_call_stack.pop();
        std::cout << curr->data << std::endl;
        if( nullptr != curr->right )preorder_call_stack.push( curr->right );
        if( nullptr != curr->left )preorder_call_stack.push( curr->left );
    }
}
int main() {
    binary_tree_node * test_tree = build_test_binary_tree();
    nonrecur_preorder( test_tree );
    return 0;
}
