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

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        std::sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a.front() == b.front()) return a.back() < b.back();
            else return a.front() > b.front();
        });

        IC(people);

        std::list<vector<int>> que;
        for (auto &rec: people) {
            int position = rec.back();
            auto it = que.begin();
            while(position--)
                it++;

            que.insert(it, rec);

            IC(que, rec.back());
        }

        return vector<vector<int>>(que.begin(), que.end());
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};
    vector<vector<int>> rel = {{5, 0},
                               {7, 0},
                               {5, 2},
                               {6, 1},
                               {4, 4},
                               {7, 1}};


    IC(people, rel);
    IC(solution->reconstructQueue(people));
    // code end

    delete solution;
    return 0;
}


