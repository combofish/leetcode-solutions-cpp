/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "../combofish_utils.hpp"
#include <algorithm>

class MyComparison {
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    // function start.
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        for (auto n: nums) umap[n]++;

        IC(umap);

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, MyComparison> pri_que;
        for (auto &_umap: umap) {
            pri_que.push(_umap);
            if (pri_que.size() > k) pri_que.pop();
        }

        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }

        return res;

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> rel = {1, 2};
    IC(nums, k, rel);

    vector<int> res = solution->topKFrequent(nums, k);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}


