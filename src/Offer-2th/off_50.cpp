/**
-- question: 第一个只出现一次的字符
-- method:
 - [*] unordered_map
 - [ ] unordered_map + queue

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
        auto cache = unordered_map<char, int>();
        for (const auto &c: s) {
            ++cache[c];
        }
        for (const auto &c: s) {
            if (cache[c] == 1) return c;
        }
        return ' ';
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
