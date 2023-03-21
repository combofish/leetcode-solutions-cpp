/**
-- question: 替换空格
-- method:
 - [ ] 遍历添加
 - [*] 原地修改
 
--result:

-- analyse:
Time: O(n)
Space: O(1)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    string replaceSpace(string s) {
        int count = 0;
        for (const auto &c: s)
            if (c == ' ') ++count;
        int n = s.size();
        s.resize(n + 2 * count);

        // i j
        for (int i = n - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ') s[j] = s[i];
            else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }

        return s;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string s = "We are happy.", rel = "We%20are%20happy.";
    IC(s, rel);
    IC(solution->replaceSpace(s) == rel);

    // code end

    return 0;
}
