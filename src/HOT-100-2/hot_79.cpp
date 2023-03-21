/**
-- question: 单词搜索
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    bool exist(vector<vector<char>> &board, string word) {
        ans = false;
        m = board.size();
        n = board.front().size();

        vector<vector<bool>> used(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word.front()) {
                    used[i][j] = true;
                    backtracking(board, used, word, 0, i, j);
                    used[i][j] = false;
                }

        return ans;
    }

private:
    bool ans;
    const int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int m, n;

    void backtracking(const vector<vector<char>> &board, vector<vector<bool>> &used, const string &word, int idx, int x, int y) {
        if (idx >= word.size() - 1) {
            ans = true;
            return;
        }

        for (auto &item: dir) {
            auto nx = x + item[0];
            auto ny = y + item[1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !used[nx][ny] && board[nx][ny] == word[idx + 1]) {
                used[nx][ny] = true;
                backtracking(board, used, word, idx + 1, nx, ny);
                used[nx][ny] = false;
            }
        }
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool ans = true;

    IC(board, word, ans);

    IC(solution->exist(board, word));
    // code end

    return 0;
}
