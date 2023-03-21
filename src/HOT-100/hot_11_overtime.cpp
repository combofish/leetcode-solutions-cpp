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

    // function start.
public:
    /**
     * overtime
     * @param height
     * @return
     */
    int maxArea(vector<int> &height) {
        int res = 0;

        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int area = std::min(height[i], height[j]) * (j - i);
                if (area > res) res = area;
            }
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
    IC(solution->maxArea(height)  == rel);


    // code end

    delete solution;
    return 0;
}


