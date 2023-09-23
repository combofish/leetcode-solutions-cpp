#include <iostream>
#include <vector>
#include <icecream.hpp>

using namespace std;

int max_sum;
vector<int> max_path;

void backtracking(vector<int> &nums, vector<int> &used, int sum_val, int idx, int n){
    if(idx >= n){
        if(sum_val > max_sum){
            max_sum = sum_val;
            max_path = used;
            
        }
        return;
    }

    for(int i = idx; i< n; ++i){

        if(!used[i]){
            used[i] = true;
            backtracking(nums, used, sum_val + nums[i], i + 2, n);
            used[i] = false;


            if(i + 1 < n){
                used[i+1] = true;
                backtracking(nums, used, sum_val + nums[i + 1], i + 1 + 2, n);
                used[i + 1] = false;
            }
        }

    }

    
}

int main(){
    vector<int> nums = {1,2,3,4,5};

    int n = nums.size();

    vector<int> used(n, false);
    max_sum = 0;
    
    backtracking(nums, used, 0, 0, n);

    IC(max_sum, max_path);


    for(int i = 0; i< n; ++i){
        cout<< i<<" ";
    }
    cout<<endl;
    cout<< max_sum <<endl;






    return 0;
}