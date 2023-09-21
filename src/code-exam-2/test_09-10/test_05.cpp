#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#include <icecream.hpp>

using namespace std;

bool debug = true;

class Status {
public:
    int val;
    int idx;

    Status(int a, int b) : val(a), idx(b) {}

    bool operator<(const Status &rhs) const {
        return val < rhs.val;
    }
};

inline int gen_next(int val) {
    int idx = 1;
    // auto new_val = val;
    while(true){
        if((val & idx) == 1){
            break;
        }

        idx<<=1;
    }

    IC(val, val - idx);


    return val - idx;
}

int main() {
    int n, k;

    if (debug) {
        n = 2;
        k = 1;
    } else {
        cin >> n >> k;
    }

    vector<int> nums(n);
    if (debug) {
        nums = {8, 7};
    } else {
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
    }

    priority_queue<Status> pqu;
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0)
            pqu.emplace(nums[i], i);
    }

    IC(nums);

    for(int i = 0; i< k; ++i){
        IC(i);

        if(!pqu.empty()){
            auto f = pqu.top();
            pqu.pop();

            auto new_val = gen_next(f.val);
            nums[f.idx] = new_val;

            if(new_val == 0) continue;
            else{
                pqu.emplace(new_val, f.idx);
            }

//            if(new_status.next_val != 0){
//                pqu.emplace(new_status.next_val, -1);
//            }
        }

        IC(nums);
    }

    cout<< std::accumulate(nums.begin(), nums.end(), 0)<<endl;


    //
    //    for(int i = 0; i< k; ++i){
    //        vector<int> new_nums = nums;
    //
    //        int change_idx = 0;
    //        int after_change_val = nums.front();
    //
    //        for(int j = 0; j < n; ++j){
    //            if(new_nums[j] == 0)
    //        }
    //
    //    }


    return 0;
}
