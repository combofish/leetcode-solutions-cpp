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

    int lastRemaining(int n, int m) {
        std::list<int> lst;
        for (int i = 0; i < n; ++i) {
            lst.push_back(i);
        }





        return lst.front();
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    int n = 5;
    int m = 3;
    IC(n, m);

    IC(solution->lastRemaining(n, m));

    // code end

    return 0;
}