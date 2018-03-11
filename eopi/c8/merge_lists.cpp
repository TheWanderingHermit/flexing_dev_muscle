#include "linked_list.h"

link<int> * merge_lists( linked_list * a, linked_list * b ) {
    link<int> * ca = a->head_link;
    link<int> * cb = b->head_link;
    link<int> * head_link   = nullptr;
    if( ca->data < cb->data ) {
        head_link = ca; ca = ca->next_link; }
    else {
        head_link = cb; cb = cb->next_link; }
    link<int> * tail_link = head_link;
    while( ca && cb ) {
        if( ca->data < cb->data ) {
            tail_link->next_link = ca; ca = ca->next_link; }
        else {
            tail_link->next_link = cb; cb = cb->next_link; }
        tail_link = tail_link->next_link;
    }
    tail_link->next_link = ca ? ca : cb;
    return head_link;
}

int main() {
    linked_list * a = new linked_list( 0 );
    a->append( 2 );
    a->append( 4 );
    a->append( 6 );
    a->append( 8 );
    linked_list * b = new linked_list( 1 );
    b->append( 3 );
    b->append( 5 );
    b->append( 7 );
    b->append( 9 );
    b->append( 10 );
    b->append( 11 );
    link<int> * merged_head = merge_lists( a, b );
    print_list( merged_head );
    return 0;
}
