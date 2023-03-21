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

    bool lemonadeChange(vector<int> &bills) {
        int tickets[4] = {0};

        for (auto bill: bills) {
            tickets[bill / 5 - 1]++;

            int rest = bill - 5;
            IC(tickets, rest);

            // need return
            if (rest) {

                if (rest / 10 && tickets[1]) {
                    rest -= 10;
                    tickets[1]--;
                }

                while (rest / 5 && tickets[0]) {
                    rest -= 5;
                    tickets[0]--;
                }

                IC(rest, tickets);

                if (rest > 0) return false;
            }
        }

        return true;
    }

    bool lemonadeChange_2(vector<int> &bills) {
        std::pair<int, int> rec;
        for (auto bill: bills) {
            int rest = bill - 5;
            if (!rest) {
                rec.first++;
                continue;
            }

            if (rest == 5) {
                rec.second++;
            }

            if (rest / 10 && rec.second) {
                rec.second--;
                rest /= 10;
            }

            while (rest / 5 && rec.first) {
                rec.first--;
                rest /= 5;
            }

            if (rest) return false;
        }
        return true;

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> bills = {5, 5, 10, 10, 20};
    bool rel = false;
    IC(bills, rel);


    IC(solution->lemonadeChange(bills) == rel);
    IC(solution->lemonadeChange_2(bills) == rel);
    // code end

    delete solution;
    return 0;
}


