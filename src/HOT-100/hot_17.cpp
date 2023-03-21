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

    vector<string> letterCombinations(string digits) {
        result.clear();
        backtracking(digits,0, "");
        return result;
    }

private:
    vector<string> result;
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
    };

    void backtracking(const string &digits, int idx, string cur) {
        if (idx >= digits.size()) {
            result.push_back(cur);
            return;
        }

        for (auto c: letterMap[digits[idx] - '0']) {
//            IC(c);
            backtracking(digits, idx + 1, cur + c);
        }
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start

    string digits = "23";
    vector<string> rel = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    IC(digits, rel);
    IC(solution->letterCombinations(digits));

    // code end

    delete solution;
    return 0;
}


