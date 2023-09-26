#include <icecream.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param scores int整型vector 分数
     * @return int整型
     */
    int prize(vector<int> &scores) {
        // write code here

        int n = (int) scores.size();
        vector<int> dp(n, 1);

        for(int i = 1; i< n; ++i){
            if(scores[i] > scores[i-1]){
                dp[i] = dp[i-1] + 1;
            }
        }

        for(int i = n-2; i >=0; --i){
            if(scores[i] > scores[i+1]){
                if(dp[i] <= dp[i+1]){
                    dp[i] = dp[i+1] + 1;
                }
            }
        }

        int ans = std::accumulate(dp.begin(), dp.end(), 0);

        IC(scores, dp, ans);

        return ans;
    }
};

int main() {

    vector<int> scores = {1, 1, 2};
    int ans = 4;

    Solution sol;

    IC(sol.prize(scores), ans);

    cout << endl;
    scores = {1, 2, 2};
    ans = 4;
    IC(sol.prize(scores), ans);


    return 0;
}