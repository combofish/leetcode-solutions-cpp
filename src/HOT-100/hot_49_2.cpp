/**
-- question: 字母异位词分组
-- method: 自定义 hash, 计数

--result:

-- analyse:
Time: O( n(k+|E|) )
Space: O( n(k+|E|) )
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        auto arrayHash = [fn = std::hash<int>{}](const std::array<int, 26> &arr) -> size_t {
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };
        unordered_map<std::array<int, 26>, vector<string>, decltype(arrayHash)> umap(0, arrayHash);

        for (const auto &item: strs){
            std::array<int, 26> counts{};
            for (const auto &c: item)
                counts[c-'a']++;

            umap[counts].emplace_back(item);
        }

        vector<vector<string>> result;
        for (const auto &item: umap)
            result.emplace_back(item.second);

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


