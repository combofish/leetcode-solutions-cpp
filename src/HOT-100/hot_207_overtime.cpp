/**
-- question:
-- method:
 - []

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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

        return
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0},
                                         {0, 1}};
    bool rel = false;

    IC(solution->canFinish(numCourses, prerequisites) == rel);
    // code end

    return 0;
}


