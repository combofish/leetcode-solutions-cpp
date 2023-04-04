/**
-- question:
-- method:
 - [-] 从低到高考虑
 - [ ] 从高到低考虑

--result:

-- analyse:
Time: O(n^2)
Space: O( log(n) )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        std::sort(people.begin(), people.end(), [](const auto &a, const auto &b) {
            return a.front() < b.front() || (a.front() == b.front() && a.back() > b.back());
        });

        IC(people);

        int n = people.size();
        vector<vector<int>> ans(n);

        for (const auto &item: people) {
            auto spaces = item.back() + 1;
            for (int i = 0; i < n; i++) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = item;
                        break;
                    }
                }
            }
            IC(ans);
        }

        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}},
            ans = {{5, 0},
                   {7, 0},
                   {5, 2},
                   {6, 1},
                   {4, 4},
                   {7, 1}};

    IC(people, ans);

    IC(solution->reconstructQueue(people));


    // code end

    return 0;
}
