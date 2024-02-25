#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    int hIndex(vector<int> &citations) {

        int n = citations.size();
        int lk = 0, rk = n - 1;

        while (lk <= rk) {
            auto mid = lk + ((rk - lk) >> 1);
            IC(lk, rk, mid, citations[mid]);

            if (citations[mid] >= n - mid) {
                rk = mid - 1;
            } else {
                lk = mid + 1;
            }
        }

        return n - lk;
    }
};
int main(int argc, char const *argv[]) {

    vector<int> citations = {0, 1, 3, 5, 6};
    int ans = 3;

    IC(citations, ans);

    Solution sol;
    IC(sol.hIndex(citations));

    // 输出：3

    return 0;
}
