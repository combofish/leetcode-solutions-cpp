#include <iostream>
#include <vector>
#include <icecream.hpp>

using namespace std;


int main(){

    vector<long long> cnts(26, 0);


    cnts['b' - 'a'] = 1;

    for(int i = 2; i< 26; ++i){
        cnts[i] = 1 + cnts[i-1] * 2;
    }


    IC(cnts);

    vector<long long> lens(26, 0);
    lens[0] = 1;
    lens[1] = 2;

    
    for(int i = 2; i< 26; ++i){
        lens[i] = 2 * lens[i-1];
    }

    IC(lens);




    return 0;
}