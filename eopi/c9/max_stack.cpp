#include "stack.h"

#include <iostream>

class max_stack {
    private :
        stack * data_stack;
        stack * comp_stack;
    public :
        max_stack( int c ) {
            data_stack = new stack( c );
            comp_stack = new stack( c );
        }
        void push( int d ) {
            data_stack->push( d );
            if( comp_stack->empty() ) {
                // error if data stack is not empty
                comp_stack->push( d );
            }
            else {
                if( comp_stack->top() < data_stack->top() )
                    comp_stack->push( d );
            }
        }
        void pop() {
            if( comp_stack->top() == data_stack->top() )
                comp_stack->pop();
            data_stack->pop();
        }
        int top() {
            return data_stack->top();
        }
        int max() {
            return comp_stack->top();
        }
};
int main() {
    max_stack * test_stack = new max_stack( 9 );
    test_stack->push( 3 );
    test_stack->push( 1 );
    test_stack->push( 4 );
    test_stack->push( 2 );
    test_stack->push( 8 );
    test_stack->push( 0 );
    std::cout << test_stack->top() << " | " << test_stack->max() << std::endl;
    test_stack->pop();
    test_stack->pop();
    std::cout << test_stack->top() << " | " << test_stack->max() << std::endl;
    return 0;
}
