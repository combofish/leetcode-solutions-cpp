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
    int add(int a, int b) {
        while (b) {
            unsigned int carry = (unsigned int) (a & b) << 1;
            a = a ^ b;
            b = carry;

            IC(carry, a, b);
        }
        return a;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int a = 10;
    int b = 8;
    IC(a, b);
    IC(solution->add(a, b));
    // code end

    return 0;
}