/**
-- question: 文字题解
-- method:
 - [ ] 单调栈

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
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        // 单调栈
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        IC(ans);
        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = {1, 1, 4, 2, 1, 1, 0, 0};

    IC(temperatures, ans);

    IC(solution->dailyTemperatures(temperatures));

    // code end

    return 0;
}


