#include "binary_tree.h"

struct record_keeper {
    int height;
    bool is_balanced;
};
record_keeper * check_bin_balanced( binary_tree_node * root ) {

}
int main() {
    binary_tree_node * root = build_test_binary_tree();
    struct record_keeper * reck = ( struct record_keeper * )( malloc( sizeof( struct record_keeper ) ) );
    std::cout << check_bin_balanced( root )->is_balanced << std::endl;
    return 0;
}
