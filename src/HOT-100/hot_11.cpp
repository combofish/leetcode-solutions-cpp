/**
-- method:

--result:

-- analyse:
Time: O(N)
Space: O(1)

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    /**
     * overtime
     * @param height
     * @return
     */
    int maxArea(vector<int> &height) {
        int res = 0;

        int l = 0, r = height.size() - 1;
        while (l < r) {
            int area = std::min(height[l], height[r]) * (r-l);
            if (area > res) res = area;
            if (height[l] < height[r]) l++;
            else r--;
        }

        return res;

    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int rel = 49;
    IC(height, rel);
    IC(solution->maxArea(height) == rel);


    // code end

    delete solution;
    return 0;
}


