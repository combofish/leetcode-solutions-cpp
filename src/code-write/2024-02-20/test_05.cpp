#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
    vector<string> ans;
    // string path;

    const vector<string> maps = {
            "",
            "",
            "abc", // 2
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"//9
    };

    void backtracking(string &path, const string digits, int idx) {
        IC(path);

        if (idx >= digits.size()) {
            ans.emplace_back(path);
            return;
        }

        IC(digits[idx] - '0');
        IC(maps[digits[idx] - '0']);

        for (auto &c: maps[digits[idx] - '0']) {
            path.push_back(c);

            backtracking(path, digits, idx + 1);
            path.pop_back();
        }
    }

public:
    // 3 ^ (len(digits))

    vector<string> letterCombinations(string digits) {
        ans.clear();
        // path.clear();
        string path;

        backtracking(path, digits, 0);

        return ans;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[]) {

    string digits = "23";
    vector<string> ans = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    IC(digits, ans);


    Solution sol;
    IC(sol.letterCombinations(digits));

    // std::tie(x, y) = {1, 2};

    for(auto &item : {-1, 1}){
        IC(item);
    }

    int n = 4;
    vector<string> board(n, string(n, '.'));
    IC(board);


    return 0;
}
