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
private:
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

    void backtracking(vector<string> &results, const string &res, string &digits, int l, int targetLength) {
        if (res.size() == targetLength) {
            results.push_back(res);
            return;
        }


        string tmp = letterMap[digits[l] - '0'];
        IC(tmp);
        for (auto c: tmp) {
            //res.push_back(c);
            backtracking(results, res + c, digits, l + 1, targetLength);
            //res.pop_back();
        }
    }

public:
    // function start.
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        string str;
        if(digits.size() == 0) return results;
        backtracking(results, str, digits, 0, digits.size());
        return results;
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


