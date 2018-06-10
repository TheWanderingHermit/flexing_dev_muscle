#include<iostream>
#include<vector>

using namespace std;
long long fibonacci( int n ) {
    vector<long long> solutions;
    solutions.push_back( 0 );
    solutions.push_back( 1 );
    for( int i = 2; i <= n; i++ ) {
        solutions.push_back( solutions[ i - 1 ] + solutions[ i - 2 ] );
    }
    return solutions.back();
}

int main() {
    cout << fibonacci( 100 ) << endl;
}
