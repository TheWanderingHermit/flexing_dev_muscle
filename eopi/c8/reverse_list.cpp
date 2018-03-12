#include "linked_list.h"

link<int> * reverse_list_iter( link<int> * head_link ) {
    link<int> * prev_link = nullptr;
    link<int> * curr_link = head_link;
    link<int> * next_link = nullptr;
    while( nullptr != curr_link ) {
        next_link = curr_link->next_link;
        curr_link->next_link = prev_link;
        prev_link = curr_link;
        curr_link = next_link;
    }
    return prev_link;
}

link<int> * reverse_list_recur( link<int> * head_link ) {
    if( nullptr == head_link || nullptr == head_link->next_link )
        return head_link;
    link<int> * reversed_head_link = reverse_list_recur( head_link->next_link );
    head_link->next_link->next_link = head_link;
    head_link->next_link = nullptr;
    return reversed_head_link;
}
int main() {
    linked_list * list = new linked_list( 0 );
    list->append( 1 );
    list->append( 2 );
    list->append( 3 );
    list->append( 4 );
    list->append( 5 );
    list->append( 6 );
    list->append( 7 );
    list->append( 8 );
    link<int> * iter_reversed_list = reverse_list_iter( list->head_link );
    print_list( iter_reversed_list );
    link<int> * recur_reversed_list = reverse_list_recur( iter_reversed_list );
    print_list( recur_reversed_list );
    return 0;
}
