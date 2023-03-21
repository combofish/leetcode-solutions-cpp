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
    int monotoneIncreasingDigits(int n) {
//        vector<int> nums;
//        while (n) {
//            nums.emplace_back(n % 10);
//            n /= 10;
//        }
//
//        IC(nums);

        string num = std::to_string(n);
        IC(num);

        int flag = num.size();
        for (int i = num.size() - 1; i > 0; i--) {
            if (num[i - 1] > num[i]) {
                flag = i;
                num[i - 1]--;
            }
        }

        IC(num);
        for (int i = flag; i < num.size(); i++)
            num[i] = '9';

        IC(num);
        return std::stoi(num);

    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    int n = 332;
    int rel = 299;
    IC(n, rel);
    IC(solution->monotoneIncreasingDigits(n));
    // code end

    delete solution;
    return 0;
}


