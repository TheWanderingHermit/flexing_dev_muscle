#include <iostream>

bool is_rect_overlap( int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22 ) {
    return y22<y11||y12<y21||x22<x11||x12<x21;
}
