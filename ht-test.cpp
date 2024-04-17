#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
int main()
{
    DoubleHashProber<std::string, MyStringHash > dh;
    HashTable<
        std::string, 
        int, 
        DoubleHashProber<std::string, MyStringHash >, 
        std::hash<std::string>, 
        std::equal_to<std::string> > ht(0.7, dh);

    // This is just arbitrary code. Change it to test whatever you like about your 
    // hash table implementation.
    for(size_t i = 0; i < 5; i++){
        std::stringstream ss;
        ss << "hi" << i;
        ht.insert({ss.str(), i});
    }
    cout << "HT size: " << ht.size() << endl << endl;
    if( ht.find("hi1") != nullptr ){
        cout << "Found hi1" << endl;
        ht["hi1"] += 1;
        cout << "Incremented hi1's value to: " << ht["hi1"] << endl;
    }

    ht.reportAll(cout);
    ht.remove("hi3");
    ht.remove("hi4");
    cout << "HT size: " << ht.size() << endl << endl;

    for(size_t i = 5; i < 10; i++){
        std::stringstream ss;
        ss << "hi" << i;
        ht.insert({ss.str(), i});
    }

    ht.reportAll(cout);

    // cout << "HT size: " << ht.size() << endl;
    // if( ht.find("hi9") != nullptr ){
    //     cout << "Found hi9" << endl;
    // }
    // else {
    //     cout << "Did not find hi9" << endl;
    // }
    // ht.insert({"hi7",17});
    // cout << "size: " << ht.size() << endl;
    return 0;
}
