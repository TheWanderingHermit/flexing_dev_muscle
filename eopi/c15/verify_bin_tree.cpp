#include <iostream>
#include <limits>
#include <queue>
#include "bst.h"

using namespace std;
bool verify_bin_tree_helper( bst_node * t, int rmin, int rmax ) {
    if( nullptr == t )
        return true;
    return ( t->d >= rmin ) 
        && ( t->d <= rmax ) 
        && verify_bin_tree_helper( t->l, rmin, t->d ) 
        && verify_bin_tree_helper( t->r, t->d, rmax );
}
bool verify_bin_tree( bst_node * t ) {
    int rmin = numeric_limits<int>::min();
    int rmax = numeric_limits<int>::max();
    return verify_bin_tree_helper( t, rmin, rmax );
}
struct query_entry {
    bst_node * c;
    int lb, rb;
    query_entry( bst_node * c, int lb, int rb ) : c( c ), lb( lb ), rb( rb ) {}
};
bool verify_bin_tree_bfs( bst_node * t ) {
    queue<query_entry> BFS_queue;
    BFS_queue.push( query_entry( t, numeric_limits<int>::min(), numeric_limits<int>::max() ) );
    while( ! BFS_queue.empty() ) {
        query_entry curr_query_entry = BFS_queue.front();
        if( nullptr != curr_query_entry.c ) {
            if( curr_query_entry.c->d < curr_query_entry.lb || curr_query_entry.c->d > curr_query_entry.rb ) 
                return false;
            BFS_queue.push( query_entry( curr_query_entry.c->l, curr_query_entry.lb, curr_query_entry.c->d ) );
            BFS_queue.push( query_entry( curr_query_entry.c->r, curr_query_entry.c->d, curr_query_entry.rb ) );
        }
        BFS_queue.pop();
    }
    return true;
}
int main() {
    cout << verify_bin_tree( spawn_test_bst() ) << endl;
    cout << verify_bin_tree( spawn_test_bad_bst() ) << endl;
    cout << verify_bin_tree_bfs( spawn_test_bst() ) << endl;
    cout << verify_bin_tree_bfs( spawn_test_bad_bst() ) << endl;
    return 0;
}
