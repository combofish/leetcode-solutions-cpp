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
    int trap(vector<int> &height) {
        int n = height.size();
        if (n <= 1) return 0;

        int ans = 0;
        auto sta = stack<int>();
        sta.push(0);

        for (int i = 1; i < n; i++) {
            if (height[i] < height[sta.top()]) sta.push(i);
            else if (height[i] == height[sta.top()]) {
                sta.pop();
                sta.push(i);
            } else {
                // height[i] > height[sta.top()]

                // outStack(sta);
                // IC(i, sta, ans);

                while (!sta.empty() && height[i] > height[sta.top()]) {
                    auto mid = sta.top();
                    sta.pop();
                    if (!sta.empty()) {
                        int w = i - sta.top() - 1;
                        auto h = std::min(height[i], height[sta.top()]) - height[mid];

                        ans += w * h;

                        outStack(sta);
                        IC(w, h, w * h, ans);
                    }
                }
                sta.push(i);
            }
        }

        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int ans = 6;

    vector<int> height = {4, 2, 0, 3, 2, 5};
    int ans = 9;

    IC(height, ans);

    IC(solution->trap(height));

    // code end

    return 0;
}
