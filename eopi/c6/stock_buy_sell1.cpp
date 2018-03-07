#include<iostream>
#include<vector>

using namespace std;

// substracting min from max won't work because min can occur after max
// maintain a current min price and max profit seen thus far

int max_profit( vector<int>& prices ) {
    int curr_min = prices[ 0 ];
    int max_profit_so_far = 0;
    for( int i = 0; i < prices.size(); i++ ) {
        int curr_profit = prices[ i ] - curr_min;
        if( curr_profit > max_profit_so_far )
            max_profit_so_far = curr_profit;
        if( prices[ i ] < curr_min )
            curr_min = prices[ i ];
    }
    return max_profit_so_far;
}
int main() {
    vector<int> prices;
    prices.push_back( 310 );
    prices.push_back( 315 );
    prices.push_back( 275 );
    prices.push_back( 295 );
    prices.push_back( 260 );
    prices.push_back( 270 );
    prices.push_back( 290 );
    prices.push_back( 230 );
    prices.push_back( 255 );
    prices.push_back( 250 );
    cout << max_profit( prices ) << endl;
}
