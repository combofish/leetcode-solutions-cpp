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

    void compute() {
        int sum = 0;
        for (int i = 0; i < 1e5; ++i) {
            ++sum;
            // IC(sum);
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto start = time(nullptr);
    solution->compute();
    auto end = time(nullptr);

    long int cost_time = end - start;
    cout << "Cost: " << cost_time << endl;

    // code end

    return 0;
}