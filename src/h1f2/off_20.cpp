/**
-- question: 剑指 Offer 20. 表示数值的字符串
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
    bool isNumber(string s) {
        int n = s.size();
        int lk = 0;
        while (lk < n && s[lk] == ' ') lk++;
        if (lk >= n) return false;

        int rk = n - 1;
        while (rk >= 0 && s[rk] == ' ') rk--;
        if (rk < 0) return false;

        int e_idx = -1;
        for (int i = lk; i <= rk; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (e_idx == -1) {
                    e_idx = i;
                } else return false;
            }
        }
//        IC(lk, rk, s.substr(lk, rk + 1 - lk));

        if (e_idx == -1) {
            auto part = s.substr(lk, rk + 1 - lk);
            IC(e_idx, part);
            IC(is_integer(part));
            IC(is_decimal(part));
            return is_integer(part) || is_decimal(part);
        }

        auto part1 = s.substr(lk, e_idx - lk);
        auto part2 = s.substr(e_idx + 1, rk + 1 - e_idx - 1);

        IC(part1, part2);
        return (is_integer(part1) || is_decimal(part1)) && is_integer(part2);
    }

private:
    bool is_integer(string &str) {
        if (str.empty()) return false;

        int n = str.size();
        int lk = 0;
        if (str.front() == '-' || str.front() == '+') lk++;

        if (lk == 1 && n == 1) return false; // empty number
        for (int i = lk; i < n; i++) {
            if (!std::isdigit(str[i])) return false;
        }
        return true;
    }

    bool is_decimal(string &str) {
        if (str.empty()) return false;

        int n = str.size();
        int lk = 0;
        if (str.front() == '-' || str.front() == '+') lk++;
        if (lk == 1 && n == 1) return false;

        int dot_idx = -1;
        for (int i = lk; i < n; i++) {
            if (str[i] == '.') {
                if (dot_idx == -1) dot_idx = i;
                else return false;
            }
        }
        if (dot_idx == -1) return false;

        auto part1 = str.substr(lk, dot_idx - lk);
        auto part2 = str.substr(dot_idx + 1, n - dot_idx - 1);

        IC(part1, part2);

        if (part1.empty() && part2.empty()) return false;

        for (auto &c: part1) {
            if (!std::isdigit(c)) return false;
        }

        for (auto &c: part2) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<pair<string, bool>> vec = {
            {"2e0", 1},
            {" 0 ", 1},
            {"-1.", 1},
            {" 277707e26", 1}
    };

    for (auto &item: vec) {
        IC(item, solution->isNumber(item.first));
        cout << endl;
    }

    // code end

    return 0;
}