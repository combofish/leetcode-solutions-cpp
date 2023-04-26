/**
-- question: 剑指 Offer 67. 把字符串转换成整数
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
    int strToInt(string str) {
        int lk = 0;
        int n = str.size();

        while (lk < n && (str[lk] != '-' && str[lk] != '+' && !std::isdigit(str[lk]))) {
            lk++;
        }
        IC(lk);

        if (lk >= n) return 0;

        IC(lk);

        int len = 0;
        while (lk + len + 1 < n && isdigit(str[lk + len + 1])) {
            ++len;
        }
        str = str.substr(lk, len + 1);

        IC(str);

        int sign = 1;
        lk = 0;
        if (str.front() == '-') {
            sign = -1;
            lk = 1;
        } else if (str.front() == '+') {
            sign = 1;
            lk = 1;
        }

        long long ans = 0;
        n = str.size();
        while (lk < n) {
            ans = 10 * ans + (str[lk] - '0');
            ans = sign == 1 ? std::min(ans, (long long) INT_MAX) : std::min(ans, -(long long) INT_MIN);
            lk++;
        }


        return sign * ans;


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string str = "-4193 with words";
    int ans = 4193;

    str = "    -42";

    IC(str, ans);

    IC(solution->strToInt(str));

    // code end

    return 0;
}