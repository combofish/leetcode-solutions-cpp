#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        IC(dq.empty());

        vector<int> ans = {nums[dq.front()]};

        for (int i = k; i < nums.size(); ++i) {

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            IC(dq.empty(), dq.front(), dq.back(), dq.size());

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);


            ans.emplace_back(nums[dq.front()]);
        }

        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> inputs = {1, -1};
    int k = 1;
    vector<int> ans = {1, -1};


    IC(inputs, k, ans);

    Solution sol;

    IC(sol.maxSlidingWindow(inputs, k));


    deque<int> dq = {1, 2, 3};

    dq.pop_front();
    dq.pop_front();
    dq.pop_front();

    IC(dq.empty(), dq.front(), dq.back());


    return 0;
}
