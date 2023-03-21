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

    // function end.
};

void showq(queue<int> gq) {
    queue<int> g = gq;
    while (!g.empty()) {
        cout << "\t" << g.front();
        g.pop();
    }
    out_line();
}

int main() {

    auto solution = new Solution();

    // code start

    vec_t nums = {6, 3, 1, 7, 5, 8, 9, 2, 4};
    IC(nums);

    queue<int> rec;

    for (auto &n: nums)
        rec.push(n);

    showq(rec);

    vec_t res;
    while (!rec.empty()) {
        res.emplace_back(rec.front());
        rec.pop();

        rec.push(rec.front());
        rec.pop();
    }

    IC(res);


    // test
    queue<int> qu;
    qu.push(9);
    IC(qu, qu.front(), qu.back());


    IC(5 / 2, 5 / 2 - 1);
    // code end

    delete solution;
    return 0;
}
