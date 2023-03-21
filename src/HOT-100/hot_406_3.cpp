/**
-- question: 根据身高重建队列
-- method:
 - [ ] 从低到高考虑
 - [ ] 从高到低考虑
 - [*] 从高到低考虑, list 
 
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
            return a.front() > b.front() || (a.front() == b.front() && a.back() < b.back());
        });

        list<vector<int>> res;
        for (const auto &item: people) {
            int position = item.back();
            auto it = res.begin();
            while (position) {
                ++it;
                --position;
            }

            res.insert(it, item);
        }
        return vector<vector<int>>(res.begin(), res.end());
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
