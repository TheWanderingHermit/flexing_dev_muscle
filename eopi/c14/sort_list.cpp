#include <iostream>
#include <cstddef>

using namespace std;
struct link {
    int d;
    link * next_link;
    link( int d ) : d( d ), next_link( nullptr ) {}
};
link * find_mid( link * head ) {
    link * slow = head;
    link * fast = head;
    while( slow && fast && fast->next_link ) {
        slow = slow->next_link;
        fast = fast->next_link->next_link;
    }
    return slow;
}
link * merge( link * a, link * b ) {
    if( nullptr == a || nullptr == b )
        return nullptr == a ? b : a;
    link * h = nullptr;
    link * t = nullptr;
    if( a->d < b->d ) {
        h = a;
        a = a->next_link;
    } else {
        h = b;
        b = b->next_link;
    }
    t = h;
    while( a && b ) {
        if( a->d < b->d ) {
            t->next_link = a;
            a = a->next_link;
            t = t->next_link;
        } else {
            t->next_link = b;
            b = b->next_link;
            t = t->next_link;
        }
    }
    t->next_link = nullptr == a ? b : a;
    return h;
}
link * mergesort( link * h ) {
    if( nullptr == h || nullptr == h->next_link )
        return h;
    link * m = find_mid( h );
    link * n = m->next_link;
    if( nullptr == n ) {
        if( h->d > m->d ) {
            int t = h->d;
            h->d  = m->d;
            m->d  = t;
        }
        return h;
    }
    m->next_link = nullptr;
    link * a = mergesort( h );
    link * b = mergesort( n );
    return merge( a, b );
}
int main() {
    link * head = new link( 8 );
    link * curr = head;
    curr->next_link = new link( 6 );
    curr = curr->next_link;
    curr->next_link = new link( 7 );
    curr = curr->next_link;
    curr->next_link = new link( 5 );
    curr = curr->next_link;
    curr->next_link = new link( 3 );
    curr = curr->next_link;
    curr->next_link = new link( 9 );
    curr = curr->next_link;
    curr->next_link = new link( 1 );
    curr = curr->next_link;
    curr->next_link = new link( 2 );
    curr = curr->next_link;
    link * h = mergesort( head );
    while( nullptr != h ) {
        cout << h->d << endl;
        h = h->next_link;
    }
    return 0;
}
