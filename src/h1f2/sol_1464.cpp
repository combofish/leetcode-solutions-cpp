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
#include <queue>

void out_pqu_int(std::priority_queue<int> pqu) {
    vector<int> nums;
    while (!pqu.empty()) {
        nums.emplace_back(pqu.top());
        pqu.pop();
    }

    IC(nums);
}

void out_pqu_int(std::priority_queue<int, vector<int>, std::greater<int>> pqu) {
    vector<int> nums;
    while (!pqu.empty()) {
        nums.emplace_back(pqu.top());
        pqu.pop();
    }

    IC(nums);
}

class Solution {

    // function start.
public:
    int maxProduct(vector<int> &nums) {

        std::priority_queue<int, vector<int>, std::greater<int>> pqu;

        for (const auto &ele: nums) {
            if (pqu.size() < 2) {
                pqu.push(ele);
            } else {
                if (ele > pqu.top()) {
                    pqu.pop();
                    pqu.push(ele);
                }
            }

            out_pqu_int(pqu);
        }

        auto prev = pqu.top();
        pqu.pop();

        return (pqu.top() - 1) * (prev - 1);
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {3, 4, 5, 2};
    int ans = 12;
    IC(nums, ans);

    IC(solution->maxProduct(nums));

    // code end

    return 0;
}