/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        auto fn = std::hash<int>{};

        auto arrayHash = [&fn](const array<int, 26> &arr) -> size_t {
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> ump(0, arrayHash);
        for (string &str: strs) {
            array<int, 26> counts{};
            for (auto &c: str) {
                ++counts[c - 'a'];
            }
            ump[counts].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (auto &item: ump) {
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