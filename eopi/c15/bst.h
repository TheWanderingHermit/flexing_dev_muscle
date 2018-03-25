#ifndef _BST_H_
#define _BST_H_
#include <cstddef>
class bst_node {
    public :
        int d;
        bst_node * l, * r;
        bst_node( int d ) : d( d ), l( nullptr ), r( nullptr ) {}
};
bst_node * spawn_test_bst() {
    bst_node * t     = new bst_node( 19 );
    t->l             = new bst_node( 7 );
    t->l->l          = new bst_node( 3 );
    t->l->l->l       = new bst_node( 2 );
    t->l->l->r       = new bst_node( 5 );
    t->l->r          = new bst_node( 11 );
    t->l->r->r       = new bst_node( 17 );
    t->l->r->r->l    = new bst_node( 13 );
    t->r             = new bst_node( 43 );
    t->r->l          = new bst_node( 23 );
    t->r->l->r       = new bst_node( 37 );
    t->r->l->r->l    = new bst_node( 29 );
    t->r->l->r->l->r = new bst_node( 31 );
    t->r->l->r->r    = new bst_node( 41 );
    t->r->r          = new bst_node( 47 );
    t->r->r->r       = new bst_node( 53 );
    return t;
}
bst_node * spawn_test_bad_bst() {
    bst_node * t     = new bst_node( 19 );
    t->l             = new bst_node( 7 );
    t->l->l          = new bst_node( 3 );
    t->l->l->l       = new bst_node( 2 );
    t->l->l->r       = new bst_node( 5 );
    t->l->r          = new bst_node( 11 );
    t->l->r->r       = new bst_node( 17 );
    t->l->r->r->l    = new bst_node( 13 );
    t->r             = new bst_node( 43 );
    t->r->l          = new bst_node( 23 );
    t->r->l->r       = new bst_node( 37 );
    t->r->l->r->l    = new bst_node( 39 ); // bad node
    t->r->l->r->l->r = new bst_node( 31 );
    t->r->l->r->r    = new bst_node( 41 );
    t->r->r          = new bst_node( 47 );
    t->r->r->r       = new bst_node( 53 );
    return t;
}
bst_node * spawn_test_bst_with_duplicates() {
    bst_node * t     = new bst_node( 108 );
    t->l             = new bst_node( 108 );
    t->l->l          = new bst_node( -10 );
    t->l->l->l       = new bst_node( -14 );
    t->l->l->r       = new bst_node( 2 );
    t->l->r          = new bst_node( 108 );
    t->r             = new bst_node( 285 );
    t->r->l          = new bst_node( 243 );
    t->r->r          = new bst_node( 285 );
    t->r->r->r       = new bst_node( 401 );
    return t;
}
#endif
