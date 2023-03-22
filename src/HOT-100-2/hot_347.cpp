/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> ump;
        for (auto &n: nums) ump[n]++;

        auto comparison = [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparison)> pqu(comparison);

        for (auto &item: ump) {
            if (pqu.size() == k) {
                if(item.second > pqu.top().second){
                    pqu.pop();
                    pqu.emplace(item.first, item.second);
                }

            } else {
                pqu.emplace(item.first, item.second);
            }
        }

        vector<int> ans;
        while (!pqu.empty()) {
            ans.emplace_back(pqu.top().first);
            pqu.pop();
        }
        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = {1, 2};

    IC(nums, k, ans);

    IC(solution->topKFrequent(nums, k));

    // code end

    return 0;
}


