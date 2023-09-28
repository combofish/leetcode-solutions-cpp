#include <iostream>
#include <vector>
#include <icecream.hpp>
using namespace std;


int main() {
    vector<int> nums = {1, 4, 3, 2};

    int n = nums.size();

    bool changed = true;

    while(changed){
        changed = false;
        
        for(int i = 0; i + 2 < n; ++i){
            if( nums[i] > nums[(i + 2) % n]){
                swap(nums[i], nums[(i+2)%n]);
                changed = true;
            }
        }

        IC(nums);
    }

    for(int i = 0; i + 1< n; ++i){
        if(nums[i] > nums[i+1]){
            cout<< "NO"<<endl;
        }
    }

    cout<<"YES"<<endl;


    return 0;
}