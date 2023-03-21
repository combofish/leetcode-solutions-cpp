/**
-- question: 最小的k个数
-- method:
 - [ ] 排序
 - [*] 堆
 - [ ] 快排思想

--result:

-- analyse:
Time: O(nlogn)
Space: O(k)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <queue>


void outPqu(std::priority_queue<int> qu);

class Solution {

    // function start.
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        if (!k) return vector<int>();

        std::priority_queue<int> qu;
        for (const auto &n: arr) {
            if (qu.size() < k) {
                qu.push(n);
            } else if (qu.top() > n) {
                qu.pop();
                qu.push(n);
            }
        }

        auto result = vector<int>();
        while (!qu.empty()) {
            result.emplace_back(qu.top());
            qu.pop();
        }
        return result;
    }

private:
    // function end.
};

void outPqu(std::priority_queue<int> qu) {
    auto result = vector<int>();
    while (!qu.empty()) {
        result.emplace_back(qu.top());
        qu.pop();
    }
    IC(result);
}

void forTest() {
    vector<int> nums = {2, 32, 4, 6, 20, 34, 13, 5, 72, 100, 7, 29, 18, 12, 23};

    auto qu = std::priority_queue<int>();
    for (const auto &n: nums) {
        qu.push(n);
        outPqu(qu);
    }
}
int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> arr = {3, 2, 1};
    int k = 2;
    string rel = "输出：[1,2] 或者 [2,1]";
    IC(arr, k, rel);
    IC(solution->getLeastNumbers(arr, k));

    forTest();
    // code end

    return 0;
}
