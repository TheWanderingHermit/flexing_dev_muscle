#include "link.h"

/*
 *     k
 * <------>
 * -------|-----------|
 *        |           |
 *        |-----------|
 *       cycle length = c
 *
 * when slow_link moves k, fast_link moves 2k, which means its k in c already as slow_link reaches the cycle start.
 * let slow_link S meet fast_link F at n
 * */
link * search_cycle( link * head_link ) {
    link * slow_link = head_link;
    link * fast_link = head_link;
    while( slow_link && fast_link && fast_link->next_link ) {
        if( slow_link == fast_link ) {
            break;
        }
        slow_link = slow_link->next_link;
        fast_link = fast_link->next_link->next_link;
    }
    slow_link = head_link;
    while( slow_link != fast_link ) {
        slow_link = slow_link->next_link;
        fast_link = fast_link->next_link;
    }
    return fast_link;
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
    link * curr_link = head_link;
    while( nullptr != curr_link->next_link ) {
        curr_link = curr_link->next_link;
    }
    curr_link->next_link = head_link->next_link->next_link->next_link;
    std::cout << search_cycle( head_link )->data << std::endl;
    return 0;
}
