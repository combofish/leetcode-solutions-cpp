/**
-- question: 柱状图中最大的矩形
-- method: 单调栈
 - []

--result:

-- analyse:
Time: O(n)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    int largestRectangleArea(vector<int> &heights) {
        // keypoint
        heights.push_back(0);
        heights.insert(heights.begin(), 0);

        stack<int> st;
        st.push(0);

        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            } else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();

                    int left = st.top();
                    int right = i;

                    int h = heights[mid];
                    int w = right - left - 1;
                    int area = h * w;
                    if (area > result) result = area;

                    IC(i, left, right, h, w, area);
                }
                st.push(i);
            }

            outStack(st);
        }

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int rel = 10;

    IC(heights, rel);
    IC(solution->largestRectangleArea(heights) == rel);
    // code end

    return 0;
}


