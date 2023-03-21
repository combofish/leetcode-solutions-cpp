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

    int largestRectangleArea(vector<int> &heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
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
                    int w = right - left - 1;
                    int h = heights[mid];
                    result = std::max(result, h * w);
                    IC(i, heights[i], h, w, result);
                }
                st.push(i);
            }

            out_sta(st);
        }

        return result;

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int rel = 10;
    IC(heights, rel);

    IC(solution->largestRectangleArea(heights) == rel);

    // code end

    delete solution;
    return 0;
}


