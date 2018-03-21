#include<iostream>

using namespace std;

void merge( int * a, int * b, int fi, int sa, int sb ) {
    int nfi = sa - 1;
    int ea = fi, eb = sb - 1;
    while( ea >= 0 && eb >= 0 ) {
        if( a[ ea ] >= b[ eb ] ) {
            a[ nfi ] =  a[ ea ];
            nfi--; ea--;
        }
        else{
            a[ nfi ] = b[ eb ];
            nfi--; eb--;
        }
    }
    int so, * t;
    if( ea == 0 ) {
        so = eb;
        t = b;
    }
    else {
        so = ea;
        t = a;
    }
    while( so >= 0 ) {
        a[ nfi ] = t[ so ];
        nfi--;
        so--;
    }
}

int main() {
    int a [] = { 0, 3, 5, 7, 0, 0, 0, 0 };
    int b [] = { 1, 3, 6 };
    merge( a, b, 3, 8, 3 );
    for( int i = 0; i < 8; i++ ) {
        cout << a[ i ] << endl;
    }
    return 0;
}
