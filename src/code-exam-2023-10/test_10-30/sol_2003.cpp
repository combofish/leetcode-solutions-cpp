#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums) {
        int n = parents.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) {
            children[parents[i]].push_back(i);
        }

        vector<int> res(n, 1);
        vector<unordered_set<int>> geneSet(n);
        function<int(int)> dfs = [&](int node) -> int {
            geneSet[node].insert(nums[node]);
            for (auto child: children[node]) {
                res[node] = max(res[node], dfs(child));
                if (geneSet[node].size() < geneSet[child].size()) {
                    geneSet[node].swap(geneSet[child]);
                }
                geneSet[node].merge(geneSet[child]);
            }
            while (geneSet[node].count(res[node]) > 0) {
                res[node]++;
            }
            IC(geneSet, res);
            return res[node];
        };
        dfs(0);
        return res;
    }
};


int main(int argc, char const *argv[]) {
    vector<int> parents = {-1, 0, 0, 2};
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = {5, 1, 1, 1};

    IC(parents, nums, ans);

    Solution sol;

    IC(sol.smallestMissingValueSubtree(parents, nums));


    return 0;
}
