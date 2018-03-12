#ifndef __LINK_H_
#define __LINK_H_

#include <iostream>
#include <cstddef>
#include <limits>

class link {
    public :
        int data;
        link * next_link;
        link() : data( std::numeric_limits<int>::min() ), next_link( nullptr ) {}
        link( int data ) : data( data ), next_link( nullptr ) {}
        void append( int data ) {
            link * curr_link = this;
            while( nullptr != curr_link->next_link ) {
                curr_link = curr_link->next_link;
            }
            curr_link->next_link = new link( data );
        }
};
void list( link * curr_link ) {
    while( curr_link ) {
        std::cout << curr_link->data << std::endl;
        curr_link = curr_link->next_link;
    }
}
#endif
