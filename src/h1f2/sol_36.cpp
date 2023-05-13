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
    bool isValidSudoku(vector<vector<char>> &board) {

        for (int i = 0; i < 9; ++i) {
            vector<int> rec(10, 0);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                ++rec[board[i][j] - '0'];

                if (rec[board[i][j] - '0'] > 1) return false;
            }
            //IC(rec);
        }
        //IC();
        IC();

        for (int j = 0; j < 9; ++j) {
            vector<int> rec(10, 0);
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                ++rec[board[i][j]-'0'];

                if (rec[board[i][j]-'0'] > 1) return false;
            }
        }

        IC();

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                vector<int> rec(10, 0);
                for (int k = 0; k < 9; ++k) {
                    auto x = i*3 + k / 3;
                    auto y = j*3 + k % 3;
                    if (board[x][y] == '.') continue;

                    if (rec[board[x][y]-'0']) {
                        IC(i,j);
                        IC(rec);
                        IC(rec[board[x][y] - '0']);
                        IC(x,y, board[x][y]);
                        return false;
                    }
                    ++rec[board[x][y]-'0'];
                }
                // IC(rec);
            }

        }

        return true;


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool ans = true;
    IC(ans);
    IC(board);

    IC(solution->isValidSudoku(board));
    // code end

    return 0;
}