/**
-- question:
-- method:
 - [ ] 排序
 - [*] 计数

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
        auto arrayHash = [fn = std::hash<int>{}](const array<int, 26> &arr) -> size_t {
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> ump(0, arrayHash);

        for(const auto &item: strs){
            std::array<int,26> tmp{};
            for(auto &c: item)
                tmp[c-'a']++;


            ump[tmp].emplace_back(item);
        }

        vector<vector<string>> ans;
        for(auto &item: ump)
            ans.emplace_back(item.second);

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


