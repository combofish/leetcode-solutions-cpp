#include <iostream>
#include <vector>
#include <icecream.hpp>

using namespace std;

bool debug = true;

long long max_gas = 0;
int n;

void backtracking(const vector<int> & nums, vector<bool> &used, long long curr_val, long long acc_val, int steps){
    IC(used, curr_val, steps);

    if(steps >= nums.size()){
        if(acc_val > max_gas){
            max_gas = acc_val;
        }

        return;
    }

    for(int i = 0; i<n; ++i) {
        if(used[i]) continue;

        // used[i] = false;

        used[i] = true;
        long long new_val, new_acc_val = acc_val;

        if(curr_val < nums[i]){
//            new_val = curr_val + nums[i] - curr_val;
            new_val = nums[i];
            new_acc_val += new_val - curr_val;
        }else{
            new_val = nums[i];
        }

//        auto new_val = curr_val < nums[i] ? curr_val + nums[i] - curr_val : nums[i];
//        acc_val += new_val - curr_val > 0 ? new_val - curr_val : 0;

        backtracking(nums, used, new_val, new_acc_val, steps + 1);
        used[i] = false;
    }
}

int main(){

    //int n;



    if(debug){
        n = 3;
    }else{
        cin>>n;
    }

    vector<int> nums(n,0);

    if(debug){
        nums = {1,2,2};
    }else{
        for(int i = 0; i<n; ++i){
            cin>>nums[i];
        }
    }


    vector<bool> used(n, false);

    backtracking(nums, used, 0, 0, 0);

    cout<<max_gas<<endl;






















    return 0;
}
