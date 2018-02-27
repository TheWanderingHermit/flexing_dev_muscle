#include <iostream>
#include <vector>
using namespace std;

void swap( vector< int >& elements, int i, int j ) {
    int temp = elements[ i ];
    elements[ i ] = elements[ j ];
    elements[ j ] = temp;
}
void dutchFlag1( vector< int >& elements, int pivot ) {
    for( int i = 0; i < elements.size(); i++ ) {
        for( int j = i + 1; j < elements.size(); j++ ) {
            if( elements[ j ] < pivot ) {
                swap( elements, i, j );
                break;
            }
        }
    }
    // the elements[ x ] >= pivot just stops the un-necessary iterations 
    // it has no bearing on the final results
    for( int i = elements.size() - 1; i >= 0 && elements[ i ] >= pivot; i-- ) {
        for( int j = i - 1; j >= 0 && elements[ j ] >= pivot; j-- ) {
            if( elements[ j ] > pivot ) {
                swap( elements, i, j );
                break;
            }
        }
    }
}

void dutchFlag2( vector< int >& elements, int pivot ) {
    int s = 0;
    for( int i = 0; i < elements.size(); i++ ) {
        if( elements[ i ] < pivot ) {
            swap( elements, s, i );
            s++;
        }
    }
    int l = elements.size() - 1;
    for( int j = elements.size() - 1; j >= 0 && elements[ j ] >= pivot; j-- ) {
        if( elements[ j ] > pivot ) {
            swap( elements, l, j );
            l--;
        }
    }
}

void dutchFlag3( vector< int >& elements, int pivot ) {
    int smaller = 0, equal = 0, larger = elements.size();
    while( equal < larger ) {
        if( elements[ equal ] < pivot ) {
            swap( elements, smaller, equal );
            smaller++;
            equal++;
        }
        else if( elements[ equal ] == pivot ) {
            equal++;
        }
        else {
            larger--;
            swap( elements, equal, larger );
        }
    }
}

int main() {
    vector< int > elements;
    elements.push_back( 7 );
    elements.push_back( 8 );
    elements.push_back( 3 );
    elements.push_back( 2 );
    elements.push_back( 5 );
    elements.push_back( 6 );
    elements.push_back( 9 );
    elements.push_back( 5 );
    elements.push_back( 11 );
    elements.push_back( 5 );
    vector< int > param1 = elements;
    dutchFlag1( param1, 5 );
    for( int i = 0; i < elements.size(); i++ ) {
        cout << param1[ i ] << endl;
    }
    vector< int > param2 = elements;
    dutchFlag2( param2, 5 );
    for( int i = 0; i < elements.size(); i++ ) {
        cout << param2[ i ] << endl;
    }
    vector< int > param3 = elements;
    dutchFlag3( param3, 5 );
    for( int i = 0; i < elements.size(); i++ ) {
        cout << param3[ i ] << endl;
    }
}
