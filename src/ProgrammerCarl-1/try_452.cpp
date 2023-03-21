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
    /**
     * err
     * @param points
     * @return
     */
    int findMinArrowShots(vector<vector<int>> &points) {
        std::sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.front() < b.front();
        });

        IC(points);

        int ans = 0;
        for (int i = 0; i < points.size();) {
            int first_end = points[i].back();
            ans++;
            i++;

            while (i < points.size() && points[i].front() <= first_end && points[i].back() >= first_end) {
                i++;
            }

        }

        return ans;
    }

    /**
     * err
     * @param points
     * @return
     */
    int findMinArrowShots_2(vector<vector<int>> &points) {
        std::sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a.front() == b.front()) return a.back() < b.back();
            else return a.front() < b.front();
        });

        IC(points);

        int ans = 0;
        for (auto it = points.begin(); it != points.end();) {
            int first_end = it->back();
            if (it != points.end()) IC(*it, first_end);
            ans++;
            it++;

            while (it != points.end() && it->front() <= first_end && first_end <= it->back())
                it++;
        }

        return ans;
    }

    int findMinArrowShots_3(vector<vector<int>> &points) {
        std::sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a.front() == b.front()) return a.back() < b.back();
            else return a.front() < b.front();
        });

        IC(points);

        int ans = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i].front() > points[i - 1].back()) ans++;
            else points[i].back() = std::min(points[i].back(), points[i - 1].back());
        }

        return ans;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<int>> points = {{10, 16},
                                  {2,  8},
                                  {1,  6},
                                  {7,  12}};
    int rel = 2;

    IC(points, rel);
    IC(solution->findMinArrowShots(points) == rel);  // error
    IC(solution->findMinArrowShots_2(points) == rel);  // error
    IC(solution->findMinArrowShots_3(points) == rel);

    vector<vector<int>> points_2 = {{3, 9},
                                    {7, 12},
                                    {3, 8},
                                    {6, 8},
                                    {9, 10},
                                    {2, 9},
                                    {0, 9},
                                    {3, 9},
                                    {0, 6},
                                    {2, 8}};
    int rel_2 = 2;
    IC(points_2, rel_2);
    IC(solution->findMinArrowShots(points_2) == rel_2);  // error
    IC(solution->findMinArrowShots_2(points_2) == rel_2);  // error
    IC(solution->findMinArrowShots_3(points_2) == rel_2);
    // code end

    delete solution;
    return 0;
}


