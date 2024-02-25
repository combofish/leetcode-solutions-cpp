#include <bits/stdc++.h>
#include<icecream.hpp>


using namespace std;



int main(int argc, char const *argv[])
{

    int n = 5, m = 4;

    vector<int> nums(n+1);

    for(int i = 1; i<=n; ++i) nums[i] = 1;

    IC(nums);

    int cnt = n;
    int sum = 0;
    int i = 1;
    bool move_left = true;

    while(cnt > 1){
        if(nums[i] != 0) {
            ++sum;

            if(sum == m){
                // nums[i] = 0;

                nums.erase(nums.begin() + i);
                sum = 0;
                --cnt;
                if(cnt == 1) break;
            }

            IC(nums, i, sum, move_left);
        }

        if(cnt == 2){
            cnt = 2;
        }

        if(move_left){
            ++i;
            if(i == nums.size() - 1 ) move_left = false;
            // if(i == n) move_left = false;
        }else{
            --i;
            if(i == 1) move_left = true;
        }


        
        // if(sum > 2*m) break;
    }

    IC(nums);
    for(int i = 1; i<=n; ++i){
        if(nums[i] != 0){
            cout<<i<<endl;
        }
    }
    
    
    cout<<"hello"<<endl;
    return 0;
}
