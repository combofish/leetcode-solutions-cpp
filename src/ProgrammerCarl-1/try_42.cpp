/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int trap(vector<int> &height) {
        int result = 0;
        stack<int> sta;
        sta.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[sta.top()] > height[i]) {
                sta.push(i);
            } else if (height[sta.top()] == height[i]) {
                sta.pop();
                sta.push(i);
            } else {
                while (!sta.empty() && height[sta.top()] < height[i]) {
                    int mid = sta.top();
                    sta.pop();
                    if (!sta.empty()) {
                        int h = std::min(height[i], height[sta.top()]) - height[mid];
                        int w = i - sta.top() - 1;
                        result += h * w;
                    }
                }

                sta.push(i);
            }

            out_sta(sta);
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int rel = 6;
    IC(height, rel);
    IC(solution->trap(height) == rel);

    // code end

    delete solution;
    return 0;
}


