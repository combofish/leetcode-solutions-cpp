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
        int lk = 0;
        int n = s.size();
        while (lk < n && s[lk] == ' ') lk++;
        s = s.substr(lk);
        while (s.back() == ' ') s.pop_back();

        bool numFlag = false;
        bool dotFlag = false;
        bool eFlag = false;

        n = s.size();
        for (int i = 0; i < n; ++i) {
            if (std::isdigit(s[i])) {
                numFlag = true;
            } else if (s[i] == '.' && !dotFlag && !eFlag) {
                dotFlag = true;
            } else if ((s[i] == 'e' || s[i] == 'E') && !eFlag && numFlag) {
                eFlag = true;
                numFlag = false;
            } else if ((s[i] == '+' || s[i] == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E')) {

            } else {
                return false;
            }
        }
        return numFlag;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<pair<string, bool>> vec = {
            {"2e0",        1},
            {" 0 ",        1},
            {"-1.",        1},
            {" 277707e26", 1},
            {".1",         1},
            {"-1E-16",     1},
            {" -54.53061", 1}
    };

    for (auto &item: vec) {
        IC(item, solution->isNumber(item.first));
        cout << endl;
    }

    // code end

    return 0;
}