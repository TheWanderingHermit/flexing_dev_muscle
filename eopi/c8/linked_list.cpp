#include "linked_list.h"

int main() {
    linked_list * list = new linked_list( 0 );
    list->append( 1 );
    list->append( 2 );
    list->append( 3 );
    list->append( 4 );
    list->append( 5 );
    list->append( 6 );
    list->append( 7 );
    list->append( 8 );
    list->append( 9 );
    list->remove( 3 );
    list->print();
    return 0;
}
