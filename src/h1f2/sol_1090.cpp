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
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> id(n);
        IC(id);
        iota(id.begin(), id.end(), 0);

        IC(id);

        sort(id.begin(), id.end(), [&](int i, int j) {
            return values[i] > values[j];
        });

        IC(id);

        int ans = 0, choose = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n && choose < numWanted; ++i) {
            int label = labels[id[i]];
            if (cnt[label] == useLimit) {
                continue;
            }
            ++choose;
            ans += values[id[i]];
            ++cnt[label];
        }
        return ans;
    }


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> values = {5, 4, 3, 2, 1}, labels = {1, 1, 2, 2, 3};
    int numWanted = 3, useLimit = 1, ans = 9;

    IC(values, labels, numWanted, useLimit, ans);

    IC(solution->largestValsFromLabels(values, labels, numWanted, useLimit));


    int **p = new int * ;
    int a = 1;
    *p = &a;

    IC(**p);

    delete p;

    // std::move()

    // code end

    return 0;
}