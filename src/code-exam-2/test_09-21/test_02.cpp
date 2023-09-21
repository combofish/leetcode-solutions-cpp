#include <iostream>
#include <vector>
#include <icecream.hpp>
using namespace std;


int main(){
    vector<int> nums = {1,2,3,5};

    int maxL = 9;

    vector<int> dp(maxL + 1, 1e9);
    dp.front() = 0;


    for(auto &curr_length : nums){
        for(int j = curr_length; j <= maxL; ++j){
            if(dp[j-curr_length] == 1e9) continue;


            if(dp[j] == 1e9){
                dp[j] = dp[j-curr_length] + 1;
            }else{
                dp[j] = std::min(dp[j], dp[j-curr_length] + 1);
            }
        }
    }

    IC(dp);

    if(dp.back() == 1e9){
        cout<<-1<<endl;
        return 0;
    }else{
        cout<< dp.back()<<endl;
        return 0;
    }




    return 0;
}