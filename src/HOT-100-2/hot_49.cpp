/**
-- question:
-- method:
 - [*] 排序
 - [ ] 计数

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> umap;

        for(const auto &str: strs){
            auto tmp = str;
            std::sort(tmp.begin(), tmp.end());
            umap[tmp].emplace_back(str);
        }

        for(auto &item: umap){
            ans.emplace_back(item.second);
        }

        return ans;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = {{"bat"},
                                  {"nat", "tan"},
                                  {"ate", "eat", "tea"}};

    IC(strs, ans);

    IC(solution->groupAnagrams(strs));
    // code end

    return 0;
}


