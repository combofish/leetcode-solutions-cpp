#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
class Solution {
    vector<vector<string>> ans;
    // string path;
    vector<pair<int, int>> path;


    void backtracking(vector<bool> &yu, unordered_set<int> &pu, unordered_set<int> &qu, int cnt, const int tot) {
        IC(path, yu, pu, qu, cnt, tot);


        if (cnt >= tot) {
            vector<string> board(tot, string(tot, '.'));
            // string tmp(tot, '.');
            // board.fill()

            for (auto &item: path) {
                board[item.first][item.second] = 'Q';
            }

            ans.emplace_back(board);
            return;
        }

        // vector<bool> xu, yu;
        // std::tie(xu, yu) = used;

        auto i = cnt;
        for (int j = 0; j < tot; ++j) {
            if (yu[j]) continue;

            // y - j = k(x - i);
            // (1, 2); y - 2 = x - 1; y = x + 1;

            // k = 1
            // y = j - ki
            if (pu.count(j - i) || qu.count(j + i)) continue;

            // record

            // IC(i,j);

            // xu[i] = true;
            yu[j] = true;
            pu.insert(j - i);
            qu.insert(j + i);
            path.emplace_back(i, j);
            backtracking(yu, pu, qu, cnt + 1, tot);
            path.pop_back();
            if (pu.count(j - i)) pu.erase(j - i);
            if (qu.count(j + i)) qu.erase(j + i);
            // xu[i] = false;
            yu[j] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        path.clear();

        vector<bool> xu(n), yu(n);
        unordered_set<int> pu, qu;

        backtracking(yu, pu, qu, 0, n);

        return ans;
    }
};

int main(int argc, char const *argv[]) {

    int n = 4;
    vector<vector<string>> ans =
            {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};

    IC(n, ans);

    Solution sol;
    IC(sol.solveNQueens(n));

    cout << endl;
    cout << 1 << endl;
    cout << string(5, '\n') << endl;
    cout << 1 << endl;

    icecream::ic.disable();
    ans = sol.solveNQueens(9);
    icecream::ic.enable();

    IC(ans);
    IC(ans.size());


    return 0;
}
