/**
-- question: 接雨水
-- method: 单调栈

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
        if (height.size() <= 1) return 0;

        stack<int> st;
        st.push(0);
        int result = 0;

        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            } else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[st.top()] < height[i]) {
                    int mid = st.top();
                    st.pop();
                    out_sta(st);

                    if (!st.empty()) {
                        int min_h = std::min(height[i], height[st.top()]) - height[mid];
                        int l = i - st.top() - 1;
                        int area = min_h * l;
                         result += area;
                    }
                }

                st.push(i);
            }
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int rel = 6;

    IC(height, rel);

    IC(solution->trap(height) == rel);
    // code end

    return 0;
}


