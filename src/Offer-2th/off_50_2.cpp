/**
-- question: 第一个只出现一次的字符
-- method:
 - [ ] unordered_map
 - [*] unordered_map + queue

--result:

-- analyse:
Time: O(n)
Space: O(E)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        auto index = unordered_map<char, int>();
        auto que = queue<pair<char, int>>();
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (index.count(s[i])) {
                index[s[i]] = -1;
                while (!que.empty() && index[que.front().first] == -1) que.pop();
            } else {
                index[s[i]] = i;
                que.emplace(s[i], i);
            }

            IC(i, index);
        }

        if (que.empty()) return ' ';
        else
            return que.front().first;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "abaccdeff";
    char rel = 'b';
    IC(s, rel);
    IC(solution->firstUniqChar(s));
    // code end

    return 0;
}
