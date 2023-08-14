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

    const int directions[4][2] = {{-1,0}, {0, -1}, { 1, 0}, {0,1}};

    void expand(vector<vector<char>> &board, int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = 'A';

            int m = board.size();
            int n = board.front().size();

            for(const auto &direction: directions){
                auto nx = i + direction[0];
                auto ny = j + direction[1];

                if(nx >= 0 && nx < m && ny >=0 && ny < n){
                    expand(board, nx, ny);
                }
            }

        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;

        int n = board.front().size();

        for(int i = 0; i< m; ++i){
            expand(board, i, 0);
            expand(board, i, n-1);
        }

        for(int j = 1; j< n-1; ++j){
            expand(board, 0, j);
            expand(board, m-1, j);
        }

        for(int i = 0; i< m; ++i){
            for(int j = 0; j< n; ++j){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}},
            ans = {{'X','X','X','X'},{'X','X','X','X'},{'X','X','X','X'},{'X','O','X','X'}};

            IC(board,ans);

    solution->solve(board);

    IC(board);

    // code end

    return 0;
}