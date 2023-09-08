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
#include <deque>

class Solution {

    // function start.
public:


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start


    vector<int> nums = {1,2,3,4,5};
    IC(nums);

    nums.insert(nums.begin() , 0);

    IC(nums);

    

    
    // code end

    return 0;
}