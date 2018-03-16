#include "binary_tree.h"
#include <iostream>
class record_keeper {
    public :
        int height;
        bool is_balanced;
        record_keeper( int h, bool b ) : height( h ), is_balanced( b ) {};
};
record_keeper * check_bin_balanced( binary_tree_node * root ) {
    if( nullptr == root ) {
        return new record_keeper( 0, true );
    }
    record_keeper * right_record = check_bin_balanced( root->right );
    if( ! right_record->is_balanced )
        return new record_keeper( 0, false );
    record_keeper * left_record = check_bin_balanced( root->left );
    if( ! left_record->is_balanced )
        return new record_keeper( 0, false );
    bool is_balanced = abs( left_record->height - right_record->height ) <= 1;
    int height = 1 + std::max( left_record->height, right_record->height );
    return new record_keeper( height, is_balanced );
}
int main() {
    binary_tree_node * root = build_test_binary_tree();
    struct record_keeper * reck = ( struct record_keeper * )( malloc( sizeof( struct record_keeper ) ) );
    std::cout << check_bin_balanced( root )->is_balanced << std::endl;
    return 0;
}
