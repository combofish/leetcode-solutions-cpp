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
#include <algorithm>

class Solution {

    // function start.
public:
    int singleNumber(vector<int> &nums) {
        unordered_set<int> uset;
        for(auto &n: nums){
            if(uset.count(n)){
                uset.erase(n);
            } else uset.insert(n);
        }

        return *uset.begin();
    }


private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {4, 1, 2, 1, 2};
    int ans = 4;

    IC(nums, ans);
    IC(solution->singleNumber(nums));

    // code end

    return 0;
}


