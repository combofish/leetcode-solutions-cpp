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
    vector<string> _path;
    vector<vector<string>> _result;
    vector<vector<bool>> _isPalindrome;

    void computePalindrome(const string &s) {
        _isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); j++) {
                if (i == j) {
                    _isPalindrome[i][j] = true;
                } else if (j - i == 1) {
                    _isPalindrome[i][j] == (s[i] == s[j]);
                } else {
                    _isPalindrome[i][j] = (s[i] == s[j] && _isPalindrome[i + 1][j - 1]);
                }
            }
        }
    }

    void backtracking(const string &s, int startIndex) {
        if (startIndex >= s.size()) {
            _result.push_back(_path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (_isPalindrome[startIndex][i]) {
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
    vector<vector<string>> partition(string s) {
        _path.clear();
        _result.clear();
        computePalindrome(s);
        IC(_isPalindrome);
        backtracking(s, 0);
        return _result;
    }
    // function end.
};

class Solution_2 {
private:
    vector<vector<string>> result;
    vector<string> path; // 放已经回文的子串
    vector<vector<bool>> isPalindrome; // 放事先计算好的是否回文子串的结果
    void backtracking(const string &s, int startIndex) {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (startIndex >= s.size()) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome[startIndex][i]) {   // 是回文子串
                // 获取[startIndex,i]在s中的子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            } else {                                // 不是回文，跳过
                continue;
            }
            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
            path.pop_back(); // 回溯过程，弹出本次已经填在的子串
        }
    }

    void computePalindrome(const string &s) {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); j++) {
//                if (j == i) {isPalindrome[i][j] = true;}
//                else if (j - i == 1) {isPalindrome[i][j] = (s[i] == s[j]);}
//                else {isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i+1][j-1]);}

                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (j - i == 1) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                }
            }
        }
    }


public:
    vector<vector<string>> partition(string s) {
        result.clear();
        path.clear();
        computePalindrome(s);
        backtracking(s, 0);
        return result;
    }
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "aab";
    vector<vector<string>> rel = {{"a",  "a", "b"},
                                  {"aa", "b"}};

    IC(s, rel);
    IC(solution->partition(s));


    auto solution_2 = new Solution_2();
    IC(solution_2->partition(s));
    delete solution_2;
    // code end

    delete solution;
    return 0;
}


