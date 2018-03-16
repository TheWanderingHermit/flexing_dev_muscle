#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class contact {
    public :
        vector< string > contact_strings;
        bool operator==( const contact & compare_this_contact ) {
            return unordered_set< string >( contact_strings.begin(), contact_strings.end() ) ==
                unordered_set< string >( compare_this_contact.contact_strings.begin(), compare_this_contact.contact_strings.end() );
        }
};
