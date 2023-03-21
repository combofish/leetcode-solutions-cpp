/**
-- question: 根据身高重建队列
-- method:
 - [*] 从低到高考虑
 - [ ] 从高到低考虑, vector insert
 - [ ] 从高到低考虑, list insert
 
--result:

-- analyse:
Time: O(n^2)
Space: O(logn)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        std::sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front() || (a.front() == b.front() && a.back() > b.back());
        });

        IC(people);
        int n = people.size();
        auto res = vector<vector<int>>(n);

        for (const auto &item: people) {
            int spaces = item.back() + 1;
            for (int i = 0; i < n; ++i) {
                if (res[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        res[i] = item;
                        break;
                    }
                }
            }

            IC(res);
        }
        return res;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}, rel = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    IC(people, rel);

    IC(solution->reconstructQueue(people));
    // code end

    return 0;
}
