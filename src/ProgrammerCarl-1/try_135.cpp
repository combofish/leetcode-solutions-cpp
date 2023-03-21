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

    // function start.
public:
    int candy(vector<int> &ratings) {
        vector<int> candyVec(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
        }

        IC(candyVec);

        for (int i = candyVec.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) candyVec[i] = std::max(candyVec[i], candyVec[i + 1] + 1);
        }

        IC(candyVec);

        return std::accumulate(candyVec.begin(), candyVec.end(), 0);
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> ratings = {1, 0, 2};
    int rel = 5;
    IC(ratings, rel);

    IC(solution->candy(ratings));
    // code end

    delete solution;
    return 0;
}


