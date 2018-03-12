#include "link.h"
#include "stack.h"

void print_reverse_linked_list( link * head_link ) {
    stack * reverse_values = new stack( 10 );
    while( head_link ) {
        reverse_values->push( head_link->data );
        head_link = head_link->next_link;
    }
    while( ! reverse_values->empty() ) {
        std::cout << reverse_values->top() << std::endl;
        reverse_values->pop();
    }
}
int main() {
    link * head_link = new link( 0 );
    head_link->append( 1 );
    head_link->append( 2 );
    head_link->append( 3 );
    head_link->append( 4 );
    head_link->append( 5 );
    head_link->append( 6 );
    head_link->append( 7 );
    head_link->append( 8 );
    print_reverse_linked_list( head_link );
    return 0;
}
