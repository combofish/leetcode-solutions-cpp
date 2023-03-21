/**
-- question: 字母异位词分组
-- method: 排序，哈希

--result:

-- analyse:
Time: O(nklogk)
Space: O(nk)
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string , vector<string> > umap;
        vector<vector<string>> result;

        for(auto str: strs){
            string sort_str = str;
            std::sort(sort_str.begin(), sort_str.end());
            umap[sort_str].push_back(str);
        }

        IC(umap);
        for(auto &u: umap)
            result.push_back(u.second);

        return result;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> rel = {{"bat"},
                                  {"nat", "tan"},
                                  {"ate", "eat", "tea"}};

    IC(strs, rel);
    IC(solution->groupAnagrams(strs));
    // code end

    return 0;
}


