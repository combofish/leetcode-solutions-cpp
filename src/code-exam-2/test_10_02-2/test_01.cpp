#include <icecream.hpp>
#include <iostream>
#include <vector>
using namespace std;

string str_multiply(const string &a, const string &b) {
    if (a.front() == '0' || b.front() == '0') return "0";

    int len1 = a.size(), len2 = b.size();
    int sum = 0;
    string ans;

    for (int k = 0; k < len1 + len2; ++k) {
        for (int i = 0; i <= k; ++i) {
            if (i < len1 && k - i < len2) {

                int _a = (a[len1 - i - 1] - '0');
                int _b = (b[len2 - 1 - k + i] - '0');
                int _c = _a * _b;

                sum += (a[len1 - i - 1] - '0') * (b[len2 - 1 - k + i] - '0');

                IC(i, k, _a, _b, _c, sum, ans);
            }
        }

        ans.insert(0, 1, sum % 10 + '0');
        sum /= 10;

        // IC(sum, ans);
    }

    if (ans.front() == '0') ans = ans.substr(1);
    // std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    // string str1 = "83648919651354818901", str2 = "39134761537489194655544";
    // string ans = "3273580523424364621101927664042199195637144";

    string str1 = "99";
    string str2 = "9";
    string ans = "2458";

    IC(str1, str2, ans, 99 * 9);

    auto ans1 = str_multiply(str1, str2);
    IC(ans1);


    return 0;
}