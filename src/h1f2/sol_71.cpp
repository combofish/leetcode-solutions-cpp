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
    string simplifyPath(string path) {
        vector<string> rec;

        string tmp = "";
        for (auto c: path) {
            if (c == '/') {
                if (!tmp.empty()) {
                    rec.emplace_back(tmp);
                    tmp.clear();
                }
            } else {
                tmp.push_back(c);
            }
        }
        if(!tmp.empty()){
            rec.emplace_back(tmp);
            tmp.clear();
        }
        IC(rec);
        vector<string> st;
        for (auto &cur: rec) {
            if (cur == ".") continue;
            else if (cur == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(cur);
            }
        }
        IC(st);

        //tmp.clear();
        int n = st.size();
        for (int i = 0; i < n; ++i) {
            tmp.push_back('/');
            tmp += st[i];
        }
        //tmp += st.back();
        if (tmp.empty()) tmp.push_back('/');
        return tmp;

    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string path = "/home//foo/";
    path = "/../";
    path = "/a//b////c/d//././/..";

    auto ans = "/a/b/c";
    IC(path, ans);
    IC(solution->simplifyPath(path));
    // code end

    return 0;
}