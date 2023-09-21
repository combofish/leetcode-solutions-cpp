#include <iostream>
#include <vector>
#include <icecream.hpp>

using namespace std;

bool debug = true;
int n = 0;

int main(){
    if(debug){
        n = 5;
    }else{
        cin>>n;
    }

    vector<int> nums(n, 0);
    if(debug){
        nums = {1,4,2,3,5};
    }else{
        for(int i = 0;i < n; ++i){
            cin>>nums[i];
        }
    }

    vector<int> ans = {0};

    for(int i = 0; i<n; ++i){
        IC(ans, nums[i], ans.back());
        if(nums[i] == (ans.back() + 1)){
            ans.emplace_back(nums[i]);
        }
    }

    IC(ans);

    return 0;
}