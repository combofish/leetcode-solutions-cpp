/**
-- question: 柱状图中最大的矩形
-- method:
 - [ ] 单调栈

--result:

-- analyse:
Time: O(N)
Space: O(N)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    int largestRectangleArea(vector<int> &heights) {
        int ans = 0;
        heights.insert(heights.cbegin(), 0);
        heights.push_back(0);
        stack<int> st;
        st.push(0);

        for (int i = 1; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                outStack(st);

                auto mid = st.top();
                st.pop();

                auto w = i - st.top() - 1;
                auto h = heights[mid];
                ans = std::max(ans, w * h);

                IC(w, h, ans);
            }
            st.push(i);
        }

        outStack(st);

        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    //     vector<int> heights = {2, 1, 5, 6, 2, 3};
    vector<int> heights = {2, 3, 3};
    int ans = 10;

    IC(heights, ans);
    IC(solution->largestRectangleArea(heights));
    // code end

    return 0;
}
