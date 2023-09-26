#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
bool debug = true;
const long long MOD = 1e10 + 7;

unordered_map<int,vector<int>> ump;

inline int one_process(int n, int k){
    if(ump.count(n)){
        auto ans = 0;
        unordered_set<int> uet;

        for(auto item : ump[n]){

        }

    }else{

    }
}

int main(){

    int T;
    cin>>T;

    while(T-- > 0){
        int n, k;

        if(debug) {
            n = 2;
            k = 1;
        }else{
            cin>>n>>k;
        }

        cout<< one_process(n,k)<<endl;
    }


//    vector<vector<int>> nums(T,vector<int>(2, 0));
//
//    for(int i = 0; i< T; ++i){
//        cin>>nums[i][0]>>nums[i][1];
//    }








    return 0;
}
