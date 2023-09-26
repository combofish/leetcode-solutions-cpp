#include <iostream>
#include <vector>
#include <icecream.hpp>
using namespace std;

bool debug = true;

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    int n, V;
    //    cin >> n >> V;

    n = 2;
    V = 6;

//    if (debug) {
//        n = 2;
//        V = 6;
//    }

    vector<int> weights(n, 0);
    vector<int> values(n, 0);

    // vector<vector<int>> nums(n, vector<int>(2, 0));

    //    for (int i = 0; i < n; ++i) {
    //        // cin>>nums[i][0]>>nums[i][1];
    //        cin >> weights[i] >> values[i];
    //    }

    weights = {5, 3};
    values = {10, 1};

    vector<int> dp(V + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = weights[i]; j <= V; ++j) {
            dp[j] = std::max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    IC(dp);
    cout << dp.back() << endl;


    // vector<int> dp2(V + 1, 1e9);
    // dp2.front() = 0;

    // for (int i = 0 ; i < n; ++i) {
    //     for (int j = weights[i]; j <= V; ++j) {

    //         dp2[j] = std::min(dp2[j], dp2[j - weights[i]] + values[i]);
    //     }
    // }

    // cout << dp2.back() << endl;


    vector<int> dp2(V + 1, 1e4);
    dp2.front() = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = weights[i]; j <= V; ++j) {

            if (dp2[j - weights[i]] >= 1e4) continue;

            if (dp2[j] >= 1e4) {
                dp2[j] = dp2[j - weights[i]] + values[i];
            } else {
                dp2[j] = std::max(dp2[j], dp2[j - weights[i]] + values[i]);
            }

            IC(dp2);
        }
    }

    cout << dp2.back() << endl;


    // vector<int> dp3(V + 1, 0);

    // for(int i = 0; i< n; ++i){
    //     for(int j = V; j>= weights[i]; --j){
    //         dp3[j] = std::max(dp3[j], dp3[j - weights[i]] + values[i]);
    //     }
    // }

    // cout<< dp3.back()<<endl;


    // vector<vector<int>> dp2(n +1, vector<int>(V + 1, 0));
    // for(int i = 1; i<= n; ++i){
    //     for(int j = 0; j<=V; ++j){
    //         if(weights[i-1] > j){
    //             dp2[i][j] = dp2[i-1][j];
    //         }else{
    //             dp2[i][j] = std::max(dp2[i][j- weights[i-1]]  + values[i - 1], dp2[i-1][j]);
    //         }
    //     }
    // }

    // cout<< dp2.back().back()<<endl;
}
// 64 位输出请用 printf("%lld")