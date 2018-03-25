#include "bst.h"

class BinarySearchTree {
    public :
        bst_node * root;
        BinarySearchTree() : root( nullptr ) {}
        void insert( int k );
        void remove( int k );
};
void BinarySearchTree::insert( int k ) {
    if( nullptr == root )
        root = new bst_node( k );
    else {
        bst_node * parent = nullptr;
        bst_node * curr   = root;
        while( curr ) {
            parent = curr;
            if( curr->d > k ) 
                curr = curr->l;
            else
                curr = curr->r;
        }
        if( parent->d > k )
            parent->l = new bst_node( k );
        else 
            parent->r = new bst_node( k );
    }
}
void BinarySearchTree::remove( int k ) {
    bst_node * parent = nullptr;
    bst_node * curr   = root;
    while( curr && curr->d != k ) {
        parent = root;
        if( curr->d > k )
            curr = curr->l;
        else
            curr = curr->r;
    }
    if( curr->d == k ) {
        if( nullptr == curr->l && nullptr == curr->r ) {
            if( parent->l == curr ) 
                parent->l = nullptr;
            else
                parent->r = nullptr;
            delete curr;
        }
        else if( nullptr == curr->l ) {
            if( parent->l == curr ) 
                parent->l = curr->r;
            else
                parent->r = curr->r;
            delete curr;
        }
        else if( nullptr == curr->r ) {
            if( parent->l == curr ) 
                parent->l = curr->l;
            else
                parent->r = curr->l;
            delete curr;
        }
        else {
            bst_node * inspa = curr;
            bst_node * insuc = curr->r;
            while( insuc->l ) {
                inspa = insuc;
                insuc = insuc->l;
            }
            int temp = curr->d; curr->d = insuc->d; insuc->d = temp;
            inspa->l = insuc->r;
            delete insuc;
        }
    }
}
