/**
-- question: 栈的压入、弹出序列
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
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int n = pushed.size();
        if (!n) return true;

        auto st = stack<int>();
        int idx = 0;
        for (const auto &n: pushed) {
            st.push(n);
            while (!st.empty() && st.top() == popped[idx]) {
                ++idx;
                st.pop();
            }

            IC(st.empty());
            //            IC(st.empty(), st.top());
        }

        return idx == n;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    bool rel = true;

    IC(pushed, popped, rel);

    IC(solution->validateStackSequences(pushed, popped) == rel);
    // code end

    return 0;
}
