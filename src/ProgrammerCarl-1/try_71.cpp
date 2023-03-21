/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.
    string simplifyPath(string path) {
        auto string_split = [](const string &s, char delim) -> vector<string> {
            vector<string> res;
            string tmp;
            for (auto c: s) {
                if (c == delim) {
                    res.emplace_back(tmp);
                    tmp.clear();
                } else {
                    tmp += c;
                }
            }
            res.emplace_back(tmp);
            return res;
        };

        vector<string> names = string_split(path, '/');
        IC(names);

        vector<string> sta;
        for (auto &s: names) {
            if (s == "..") {
                if (!sta.empty()) sta.pop_back();
            } else if (!s.empty() && s != ".") {
                sta.push_back(s);
            }
        }
        if (sta.empty()) {
            sta.push_back("");
        }

        string res;
        for (auto name: sta)
            res += ("/" + name);

        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string path = "/a/./b/../../c/";
    string rel = "/c";

    IC(path, rel);
    string res = solution->simplifyPath(path);
    IC(res, res == rel);
    // code end

    delete solution;
    return 0;
}


