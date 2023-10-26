#include <algorithm>
#include <array>
#include <icecream.hpp>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;


int main(int argc, char const *argv) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
    IC(strs, ans);


    auto arrayHash = [fn = hash<int>()](const array<int, 26> &arr) -> size_t {
        return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
            return (acc >> 1) ^ fn(num);
        });
    };

    unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> ump(0, arrayHash);

    for (const auto &str: strs) {
        array<int, 26> tmp{};
        IC(tmp);
        for (const auto &c: str) {
            ++tmp[c - 'a'];
        }
        ump[tmp].emplace_back(str);
    }

    vector<vector<string>> ans2;
    for (const auto &item: ump) {
        ans2.emplace_back(item.second);
    }

    IC(ans2);


    return 0;
}
