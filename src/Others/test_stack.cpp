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
public:
    // function start.

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s1 = "abzba";
    int len = s1.size();
    int mid = len / 2 - 1;
    int next;

    stack<int> sta;
    for (int i = 0; i <= mid; i++)
        sta.push(s1[i]);

    if (len % 2 == 0) {
        next = mid + 1;
    } else {
        next = mid + 2;
    }

    for (int i = next; i < len; i++) {
        if (s1[i] != sta.top()) {
            break;
        }
        sta.pop();
    }

    if (sta.empty())
        IC("Yes");
    else
        IC("No");

    // code end

    delete solution;
    return 0;
}
