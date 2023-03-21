/**
-- question: 单词搜索
-- method: 回溯
 - []

--result:

-- analyse:
Time: O( mn * 3^L )
Space: O(mn)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board.front().size();
        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.front()) {
                    used[i][j] = true;
                    bool result = backtracking(m, n, board, word, 1, i, j, used);
                    if (result) return true;
                    used[i][j] = false;
                }
            }
        }
        return false;

    }

private:
    const int directions[4][2] = {{-1, 0},
                                  {0,  -1},
                                  {0,  1},
                                  {1,  0}};

//    const vector<array<int, 2>> d = {{-1, 0},
//                                     {0,  -1},
//                                     {0,  1},
//                                     {1,  0}};

    bool backtracking(
            const int m, const int n,
            const vector<vector<char>> &board, const string &word,
            int idx, int i, int j,
            vector<vector<bool>> &used
    ) {
        if (idx == word.size()) {
            return true;
        }

        for (const auto &item: directions) {
            int ni = i + item[0];
            int nj = j + item[1];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                if (!used[ni][nj] && board[ni][nj] == word[idx]) {
                    used[ni][nj] = true;
                    bool result = backtracking(m, n,
                                               board,
                                               word,
                                               idx + 1, ni, nj, used);
                    if (result) return true;
                    used[ni][nj] = false;
                }

            }
        }

        return false;

    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool rel = true;

    IC(solution->exist(board, word) == rel);

    // code end

    return 0;
}


