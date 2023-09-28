#include <iostream>
#include <vector>
#include <icecream.hpp>
using namespace std;


int main() {
    vector<int> nums = {1, 4, 3, 2};

    int n = nums.size();

    vector<int> ids(n);
    for(int i = 0; i< n; ++i){
        ids[i] = i;
    }
    IC(ids);


    std::sort(ids.begin(), ids.end(),[&nums](int a, int b){
        return nums[a] < nums[b];
    });


    IC(nums, ids);

    for(int i = 0; i< n; ++i){

        if(std::abs(ids[i] - i) % 2 != 0){
            cout<<"NO"<<endl;

            IC(ids[i], i);
        }
    }


    cout<<"YES"<<endl;

   

    // for(int i = 0; i + 1< n; ++i){
    //     if(nums[i] > nums[i+1]){
    //         cout<< "NO"<<endl;
    //     }
    // }

    // cout<<"YES"<<endl;


    return 0;
}