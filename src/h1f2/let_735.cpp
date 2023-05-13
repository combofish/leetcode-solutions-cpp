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

    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (asteroids[i] == 0) continue;

            if (i == 0 || ans.empty()) {
                ans.emplace_back(asteroids[i]);
            } else {
                if (ans.back() < 0 && asteroids[i] < 0) {
                    ans.emplace_back(asteroids[i]);
                    continue;
                }

                if (ans.back() > 0 && asteroids[i] > 0) {
                    ans.emplace_back(asteroids[i]);
                    continue;
                }

                auto curr = asteroids[i];
                if (curr < 0) {
                    while (!ans.empty() && ans.back() > 0 && curr < 0) {
                        auto tmp = ans.back();
                        ans.pop_back();

                        if (curr + tmp > 0) {
                            curr = tmp;
                        } else if (curr + tmp < 0) {

                        } else {
                            curr = 0;
                        }
                    }
                    if (curr == 0) continue;
                    ans.push_back(curr);
                } else if (curr > 0) {
//                    while (!ans.empty() && ans.back() < 0 && curr > 0) {
//                        auto tmp = ans.back();
//                        ans.pop_back();
//
//                        if (tmp + curr > 0) {
//
//                        } else if (tmp + curr < 0) {
//                            curr = tmp;
//                        } else {
//                            curr = 0;
//                        }
//                    }
//                    if (curr == 0) continue;
                    ans.push_back(curr);
                }
            }
        }
        return ans;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> asteroids = {5, 10, -5};

    asteroids = {-2, -1, 1, 2};

    IC(asteroids);
    IC(solution->asteroidCollision(asteroids));
    // code end

    return 0;
}