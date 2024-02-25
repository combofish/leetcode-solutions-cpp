#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;


int main(int argc, char const *argv[]) {

    // 2 1 2 3 0 3
    //   1     3   = 4

    vector<int> nums = {3, 2, 1, 2, 3, 0, 3}; /// 1 3 3 = 7

    // // 3 2 1 2 |   2 1 2 = 1 
    // // 3 2 2 3 |   2   2 r 3 = 0
    // // 3 2 3   |   3 2  3   = 3 

    // // --    ---
    // // --- -----
    // // ------- 

    // //    top * w = area;
    // // {3, 2, 1, 2, 3, 0, 3};
    // 21 
    // -  ///
    
    // 14 

    // = 7 
    // // 1 2 3 0 3 0
    // - 2 - 1 - 3 = 

    //  3 

    //  2 1 2 3 0 3  = 1 + 3 = 4
    //  1 1 1 0 0 0 = 3
    //  11

    //  18 - 11 - 3 = 4




    stack<int> st;
    // st.push(-1);

    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {// 1 2
            // 可以储水
            auto bottom = nums[st.top()];
            st.pop();

            if (st.empty()) {
                break;
            }
            auto high = std::min(nums[i], nums[st.top()]);


            int w = i - st.top() - 1;

            IC(w, high, bottom, high - bottom);

            ans += w * (high - bottom);
        }
        st.push(i);
        // IC(st);
    }

    IC(ans);


    return 0;
}
