/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class MyQueue {
public:
    void pop(int value) {
        if (!_deq.empty() && value == _deq.front())
            _deq.pop_front();
    }

    void push(int value) {
        while (!_deq.empty() && value > _deq.back())
            _deq.pop_back();

        _deq.push_back(value);
    }

    int front() {
        return _deq.front();
    }

private:
    std::deque<int> _deq;
};

class Solution {
public:
    // function start.
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++) que.push(nums[i]);

        res.push_back(que.front());
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> rel = {3, 3, 5, 5, 6, 7};

    vector<int> res = solution->maxSlidingWindow(nums, k);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}


