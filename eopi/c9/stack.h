#ifndef __STACK_H_
#define __STACK_H_

#include <limits>
class stack {
    private:
        int * container;
        int topidx;
        int cap;
    public :
        stack( int c ) : topidx( -1 ), cap( c ) { container = new int[ c ](); }
        void push( int d ) {
            if( topidx + 1 < cap )
                container[ ++topidx ] = d;
        }
        void pop() {
            if( topidx > -1 )
                topidx--;
        }
        int top() {
            if( topidx > -1 )
                return container[ topidx ];
            return std::numeric_limits<int>::min();
        }
        bool empty() {
            return topidx < 0;
        }
};

#endif
