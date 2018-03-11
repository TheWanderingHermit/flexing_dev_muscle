#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

#include <iostream>
#include <cstddef>
#include <limits>

template <typename T>
class link {
    public :
        T data;
        link * next_link;
        link( T data ) : data( data ), next_link( nullptr ) {}
};

// head links contain dummy data
class linked_list {
    public :
        link<int> * head_link;
        linked_list( int data ) {
            head_link = new link<int>( data );
        }
        void append( int data ) {
            if( nullptr == head_link ) {
                head_link = new link<int>( data );
                return;
            }
            link<int> * curr_link = head_link;
            while( curr_link->next_link )
                curr_link = curr_link->next_link;
            curr_link->next_link = new link<int>( data );
        }
        void remove( int data ) {
            if( data == head_link->data ) {
                link<int> * del_link = head_link;
                head_link = head_link->next_link;
                delete( del_link );
                return;
            }
            link<int> * curr_link = head_link;
            while( curr_link->next_link ) {
                if( data == curr_link->next_link->data ) {
                    link<int> * next_link = curr_link->next_link->next_link;
                    delete( curr_link->next_link );
                    curr_link->next_link = next_link;
                    return;
                }
                curr_link = curr_link->next_link;
            }
        }
        void print() {
            link<int> * curr_link = head_link->next_link;
            while( curr_link ) {
                std::cout << curr_link->data << std::endl;
                curr_link = curr_link->next_link;
            }
        }
};
void print_list( link<int> * curr_link ) {
    while( curr_link ) {
        std::cout << curr_link->data << std::endl;
        curr_link = curr_link->next_link;
    }
}

#endif
