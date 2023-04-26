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
        auto s = std::to_string(x);
//        std::reverse(s.begin(), s.end());
        if (s.front() == '-') {
            std::reverse(s.begin() + 1, s.end());
        } else {
            std::reverse(s.begin(), s.end());
        }

        IC(s);
        int ans = 0;
        ans = std::stoi(s);
        IC(ans);

        IC(INT_MAX);

        int mn = (long)std::pow((long)2, 31) -1;
        IC(mn);
        return 0;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int x = -123;
//    x = 1534236469;
    int ans = -321;

    IC(x, ans);
    IC(solution->reverse(x));

    // code end

    return 0;
}