#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class isbn_cache {
    private :
        size_t capacity;
        list< int > isbn_l;
        unordered_map< int, pair< int, list< int >::iterator > > isbn_t;
        void incr_priority( unordered_map< int, pair< int, list< int >::iterator > >::iterator );
    public  :
        int  lookup( int isbn );
        void insert( int isbn, int price );
        void remove( int isbn );
};

void isbn_cache::incr_priority( unordered_map< int, pair< int, list< int >::iterator > >::iterator ten ) {
    int isbn = ten->first;
    isbn_l.erase( ten->second.second );
    isbn_l.push_front( isbn );
    ten->second.second = isbn_l.begin();
}
int isbn_cache::lookup( int isbn ) {
    unordered_map< int, pair< int, list< int >::iterator > >::iterator titr = isbn_t.find( isbn );
    if( titr == isbn_t.end() )
        return -1;
    incr_priority( titr );
    return isbn_l.front();
}
void isbn_cache::insert( int isbn, int price ) {
    unordered_map< int, pair< int, list< int >::iterator > >::iterator titr = isbn_t.find( isbn );
    if( titr != isbn_t.end() )
        incr_priority( titr );
    else {
        if( isbn_l.size() == capacity ) {
            int invalid_isbn = isbn_l.back();
            isbn_l.pop_back();
            isbn_t.erase( invalid_isbn );
        }
        isbn_l.push_front( isbn );
        isbn_t[ isbn ] = make_pair( price, isbn_l.begin() );
    }
}
void isbn_cache::remove( int isbn ) {
    unordered_map< int, pair< int, list< int >::iterator > >::iterator titr = isbn_t.find( isbn );
    isbn_l.erase( titr->second.second );
    isbn_t.erase( titr );
}
