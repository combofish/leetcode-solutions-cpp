/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

    double myPow(double x, int n) {
//        if (n == 0) return 1;
//        else if (n < 0) return 1.0 / myPow(x, -n);
//        IC(cache);
//        return merge(x, 1, n);

        cache.clear();
        return quickPow(x, n);
    }

private:
    unordered_map<int, double> cache;

    double quickPow(double x, long long n) {
        if (n == 0) return 1;
        else if (n < 0) return 1.0 / quickPow(x, -n);
        return merge(x, 1, n);
    }

    double merge(double x, long i, long j) {
        if (i == j) return x;
        else if (i > j) return 1;


        int d = j - i + 1;
        if (cache.find(d) != cache.end()) return cache[d];

        int mid = (long(i) + long(j)) >> 1;
        int result = merge(x, i, mid) * merge(x, mid + 1, j);
        cache[d] = result;

//        IC(cache);

        IC(result);
        return result;
    }
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    double x = 2.0000;
    int n = 11;
    double rel = 2048.0000;
    IC(x, n, rel);

    IC(solution->myPow(x, n) == rel);

    IC();
    double x2 = 2.0;
    int n2 = -2147483648;
    double rel2 = 0;
//    IC(x2, n2, rel2);
//    IC(solution->myPow(x2, n2));

    // code end

    return 0;
}


