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
public:
    // function start.
    vector<vector<int>> generateMatrix(int n) {
        mat_t res(n, vec_t(n, 0));

        // idx
        int i = 0;
        int j = 0;
        int line_length = n;

        // cnt
        int cnt = 1;
        int loop = n / 2;
        int max_cnt = n * n;


        while (loop--) {


            int start_j = j;
            int start_i = i;

            //IC(start_i, start_j);

            for (; j < start_j + line_length - 1; j++)
                res[i][j] = cnt++;

            for (; i < start_i + line_length - 1; i++)
                res[i][j] = cnt++;


            for (; j > start_j; j--)
                res[i][j] = cnt++;


            for (; i > start_i; i--)
                res[i][j] = cnt++;

            // out_mat(res);

            i = start_i + 1;
            j = start_j + 1;
            line_length -= 2;


            // debug++;
            // if(debug == 2) break;
        }

        if (n % 2 == 1)
            res[i][j] = cnt++;

        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 2;
    // mat_t res1 = solution->generateMatrix(n);
    // out_mat(res1);

    for (; n < 11; n++) {
        mat_t res = solution->generateMatrix(n);
        IC(n);
        out_mat(res);
    }


    // code end

    delete solution;
    return 0;
}
