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
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
        int n = reward1.size();
        vector<int> diff(n);
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }

        std::sort(diff.begin(), diff.end());

        for (int i = 1; i <= k; ++i) {
            ans += diff[n - i];
        }

        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<int> reward1 = {1, 4, 4, 6, 4};
    vector<int> reward2 = {6, 5, 3, 6, 1};
    int k = 1;

    IC(reward1, reward2, k);
    IC(solution->miceAndCheese(reward1, reward2, k));


    std::priority_queue<int, vector<int>, std::greater<int>> pqu;

    pqu.emplace(9);
    pqu.emplace(4);
    pqu.emplace(14);
    pqu.emplace(24);
    pqu.emplace(44);


    while(!pqu.empty()){
        IC(pqu.top());
        pqu.pop();
    }
    // code end

    return 0;
}