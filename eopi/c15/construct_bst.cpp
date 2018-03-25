#include <iostream>
#include <vector>
#include "bst.h"

using namespace std;

void p( bst_node * t ) {
    if( nullptr == t )
        return;
    cout << t->d << endl;
    p( t->l );
    p( t->r );
}
void construct_bst_helper( bst_node * t, vector<int> & preorder_data, int a, int b ) {
    if( a >= b )
        return;
    int i = a;
    for( ; i <= b; i++ ) {
        if( preorder_data[ i ] > t->d ) 
            break;
    }
    t->l = new bst_node( preorder_data[ a ] );
    t->r = new bst_node( preorder_data[ i ] );
    construct_bst_helper( t->l, preorder_data, a + 1, i - 1 );
    construct_bst_helper( t->r, preorder_data, i, b );
}
bst_node * construct_bst( vector<int> & preorder_data ) {
    bst_node * t = new bst_node( preorder_data[ 0 ] );
    construct_bst_helper( t, preorder_data, 1, preorder_data.size() - 1 );
    return t;
}
int main() {
    vector<int> travel_data;
    travel_data.push_back( 43 );
    travel_data.push_back( 23 );
    travel_data.push_back( 37 );
    travel_data.push_back( 29 );
    travel_data.push_back( 31 );
    travel_data.push_back( 41 );
    travel_data.push_back( 47 );
    travel_data.push_back( 53 );
    bst_node * t = construct_bst( travel_data );
    p( t );
    return 0;
}
