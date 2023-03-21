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
    vector<vector<string>> _result;
    vector<string> _path;

    bool isPalindrome(const string &s, int i, int j) {
        for (; i < j; i++, j--)
            if (s[i] != s[j])
                return false;

        return true;
    }

    void backtracking(const string &s, int startIndex) {
        if (startIndex >= s.size()) {
            _result.push_back(_path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                string tmp = s.substr(startIndex, i - startIndex + 1);
                _path.push_back(tmp);
            } else {
                continue;
            }
            backtracking(s, i + 1);
            _path.pop_back();
        }
    }

public:
    // function start.
    vector<vector<string>> partition(string s) {
        _result.clear();
        _path.clear();
        backtracking(s, 0);
        return _result;
    }


private:


public:
    vector<vector<bool>> _isPalindrome;

    void computePalindrome(const string &s) {
        _isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                cout << "(" << i << "," << j << ")" << ":" << s.substr(i, j - i + 1) << " ";
                if (j == i) _isPalindrome[i][j] = true;
                else if (j - i == 1) _isPalindrome[i][j] == (s[i] == s[j]);
                else _isPalindrome[i][j] = (s[i] == s[j] && _isPalindrome[i + 1][j - 1]);
            }

            out_line();
        }
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "aab";
    vector<vector<string>> rel = {{"a",  "a", "b"},
                                  {"aa", "b"}};

    IC(s, rel);
    IC(solution->partition(s));
    // code end

    IC();
    solution->computePalindrome(s);
    IC(solution->_isPalindrome);
    delete solution;
    return 0;
}


