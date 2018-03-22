#include <iostream>
#include <vector>

using namespace std;
int find_salary_cap( vector<int> & salaries, int total_budget ) {
    double total_unadjusted_salaries = 0;
    for( int i = 0; i < salaries.size(); i++ ) {
        double total_adjusted_salaries = salaries[ i ] * ( salaries.size() - 1 );
        if( total_adjusted_salaries + total_unadjusted_salaries >= total_budget ) {
            return ( total_budget - total_unadjusted_salaries ) / ( salaries.size() - 1 );
        }
        total_unadjusted_salaries += salaries[ i ];
    }
    return -1.0;
}
