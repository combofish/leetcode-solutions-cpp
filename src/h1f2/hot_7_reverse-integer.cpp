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

class Solution {

    // function start.
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) {
                return 0;
            }
            auto tmp = x % 10;
            x /= 10;
            ans = ans * 10 + tmp;
        }

        unordered_set<int> uet;
        uet.insert(1);

        unordered_map<int, int> ump;
        ump[1] = 1;

        return ans;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int x = -123;
    x = 1534236469;
//    x = 123;
    int ans = -321;

    IC(x, ans);
    IC(solution->reverse(x));

    // code end

    return 0;
}