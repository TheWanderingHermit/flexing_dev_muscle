#include <iostream>
#include <string>

using namespace std;

string excel_column( unsigned long long column_index ) {
    string column_name;
    while( column_index > 0 ) {
        int remainder = column_index % 26;
        column_index /= 26;
        if( remainder == 0 ) {
            column_index -= 1;
        }
        column_name += remainder == 0 ? 'Z' : 'A' + remainder - 1;
    }
    reverse( column_name.begin(), column_name.end() );
    return column_name;
}
int main() {
    cout << excel_column( 26 ) << endl;
    cout << excel_column( 27 ) << endl;
    cout << excel_column( 28 ) << endl;
    return 0;
}
