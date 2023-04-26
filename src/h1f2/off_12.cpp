/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    bool exist(vector<vector<char>> &board, string word) {
        ans = false;

        int n = board.size();
        int m = board.front().size();
        vector<vector<bool>> used(n, vector<bool>(m, false));
        for (int i = 0; i < n && !ans; i++) {
            for (int j = 0; j < m && !ans; j++) {
                if (board[i][j] == word.front()) {
                    used[i][j] = true;
                    backtracking(board, word, 1, used, i, j);
                    used[i][j] = false;
                }
            }
        }

        return ans;

    }

private:

    bool ans;
    const int dirs[4][2] = {{-1, 0},
                            {0,  -1},
                            {1,  0},
                            {0,  1}};

    void backtracking(const vector<vector<char>> &board, const string &word, int idx, vector<vector<bool>> &used, int i,
                      int j) {
        if (idx >= word.size()) {
            ans = true;
            return;
        }

        IC(used, i, j, board[i][j]);

        int n = board.size();
        int m = board.front().size();

        for (auto dir: dirs) {
            auto nx = i + dir[0];
            auto ny = j + dir[1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !ans && !used[nx][ny] && board[nx][ny] == word[idx]) {
                used[nx][ny] = true;
                backtracking(board, word, idx + 1, used, nx, ny);
                used[nx][ny] = false;
            }
        }

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
    bool ans = true;
    IC(board, word, ans);
    IC(solution->exist(board, word));

    // code end

    return 0;
}