#include <cmath>
#include <iostream>
#include <vector>

// #include <icecream.hpp>

using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;
long dp[N];

long cal(vector<long long> &item) {
    // long long sq2 = item[0] * item[0] - 2 * item[1];
    dp[0] = 2;
    dp[1] = item.front();

    auto A = item[0];
    auto B = item[1];
    auto n = item.back();

    for (int i = 2; i <= n; i++)
        dp[i] = (A * dp[i - 1] % mod - B * dp[i - 2] % mod + mod) % mod;

    return dp[n];
}

int main() {

    int T;
    cin >> T;

    vector<vector<long long>> rec(T, vector<long long>(3, 0));

    for (int i = 0; i < T; i++) {
        cin >> rec[i][0] >> rec[i][1] >> rec[i][2];
    }


    for (int i = 0; i < T; i++)
        cout << cal(rec[i]) << endl;

    return 0;
}
