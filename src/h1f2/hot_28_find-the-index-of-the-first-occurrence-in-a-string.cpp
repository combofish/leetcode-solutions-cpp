/**
-- question: 28. 找出字符串中第一个匹配项的下标
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
    int strStr(string haystack, string needle) {

        int hs = haystack.size();
        int ns = needle.size();

        if (hs < ns) return -1;
        for (int i = 0; i + ns <= hs; i++) {

            IC(haystack.substr(i, ns), i, i + ns);
            if (haystack.substr(i, ns) == needle) {
                return i;
            }
        }


        return -1;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    string haystack = "hello";
    string needle = "ll";
    IC(haystack, needle);

    IC(solution->strStr(haystack, needle));

    int a = std::pow(10, 9) + 7;
    int b = INT_MAX;
    IC(a, b);

    int c = 1e9 + 7;
    IC(c);

    // code end

    return 0;
}