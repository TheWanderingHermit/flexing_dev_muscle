#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int stock_buy_sell_twice( vector< int >& prices ) {
    int min_price_so_far = std::numeric_limits<int>::max(), max_profit_so_far = 0;
    vector< int > profits;
    for(vector< int >::iterator vitr = prices.begin(); vitr != prices.end(); vitr++ ) {
        int price = *vitr;
        max_profit_so_far = max( max_profit_so_far, price - min_price_so_far );
        profits.push_back( max_profit_so_far );
        min_price_so_far = min( min_price_so_far, price );
    }
    int max_price_this_back = 0, max_profit_selling_twice = 0;
    for( unsigned int itr = prices.size() - 1; itr > 0; itr-- ) {
        max_profit_selling_twice = max( max_price_this_back - prices[ itr ] + profits[ itr - 1 ],  max_profit_so_far );
        max_price_this_back = max( prices[ itr ], max_price_this_back );
    }
    return max_profit_selling_twice;
}
int main() {
    vector< int > prices;
    prices.push_back( 12 );
    prices.push_back( 11 );
    prices.push_back( 13 );
    prices.push_back( 9 );
    prices.push_back( 12 );
    prices.push_back( 8 );
    prices.push_back( 14 );
    prices.push_back( 13 );
    prices.push_back( 15 );
    cout << stock_buy_sell_twice( prices ) << endl;
    return 0;
}
