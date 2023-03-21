/*
 * @Author: combofish combofish@139.com
 * @Date: 2022-12-04 08:25:41
 * @LastEditors: combofish combofish@139.com
 * @LastEditTime: 2022-12-04 08:42:57
 * @FilePath: /Leetcode-Solution-Cpp/src/HOT-100/hot_347.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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

// class Compare {
// public:
//     bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
//         return a.second > b.second;
//     }
// };

class Solution {

    // function start.
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        for (const auto &item: nums) {
            umap[item]++;
        }

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comparsion)> qu(comparsion);
        for (const auto &item: umap) {
            if (qu.size() == k) {
                if (qu.top().second < item.second) {
                    qu.pop();
                    qu.emplace(item.first, item.second);
                }
            } else {
                qu.emplace(item.first, item.second);
            }
        }


        vector<int> result;
        while (!qu.empty()) {
            result.emplace_back(qu.top().first);
            qu.pop();
        }

        return result;
    }

private:
    static bool comparsion(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> rel = {1, 2};

    IC(nums, k, rel);
    IC(solution->topKFrequent(nums, k));

    // code end

    return 0;
}
