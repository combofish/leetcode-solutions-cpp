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
    vector<string> result;

    // [i,j]
    bool isValid(const string &s, int i, int j) {
        if (i > j) return false;
        if (s[i] == '0' && i != j) return false;

        int num = 0;
        for (int k = i; k <= j; k++) {
            if (s[k] > '9' || s[k] < '0') return false;
            num = 10 * num + (s[k] - '0');
            if (num > 255) return false;
        }

        IC(s.substr(i, j - i + 1));
        return true;
    }

    void backtracking(string &s, int startIndex, int partNum) {
        if (partNum == 3) {
            if (isValid(s, startIndex, s.size() - 1))
                result.push_back(s);
            return;
        }

        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                backtracking(s, i + 2, partNum + 1);
                s.erase(s.begin() + i + 1);

            } else {
                break;
            }
        }

    }

public:
    // function start.
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result;
        backtracking(s, 0, 0);
        return result;
    }
    // function end.
};


class Solution_2 {
private:
    vector<string> result;// 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            } else break; // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // 算是剪枝了
        backtracking(s, 0, 0);
        return result;
    }
};

int main() {

    auto solution = new Solution();

    // code start
    string s = "101023";
    vector<string> rel = {"1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"};
    IC(s, rel);

    IC(solution->restoreIpAddresses(s));
    IC(solution->restoreIpAddresses("000256"));


    auto solution_2  = new Solution_2();
    IC(solution_2->restoreIpAddresses("000255"));
    delete solution_2;
    // code end

    delete solution;
    return 0;
}


