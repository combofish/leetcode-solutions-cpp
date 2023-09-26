#include <iostream>
#include <vector>
#include <icecream.hpp>
using namespace std;

bool debug = true;
int n, k;


int main() {

    if (debug) {
        n = 3;
        k = 2;
    } else {
        cin >> n >> k;
    }

    vector<int> nums_a(n, 0), nums_b(n, 0);

    if (debug) {
        nums_a = {1, 9, 3};
        nums_b = {2, 7, 8};
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> nums_a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> nums_b[i];
        }
    }

    vector<vector<int>> nums(n, vector<int>(n, 0));
    for(int i = 0; i< n; ++i){
        for(int j = 0; j<=i; ++j){
            if(i ==j) continue;
            nums[i][j] = std::abs(nums_a[i] - nums_a[j]) + std::abs(nums_b[i] - nums_b[j]);
        }
    }

    IC(nums);



    vector<bool> used(n, false);

    for(int i = 0; i< n; ++i){
        for(int j = 0; j<= i; ++j){

            
        }
    }






    return 0;
}