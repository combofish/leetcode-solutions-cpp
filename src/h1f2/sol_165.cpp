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
    int compareVersion(string version1, string version2) {

        vector<string> rec1;
        string tmp;
        for (auto &c: version1) {
            if (c == '.') {
                rec1.emplace_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        if (!tmp.empty()) {
            rec1.emplace_back(tmp);
        }

        tmp.clear();
        vector<string> rec2;
        for (auto &c: version2) {
            if (c == '.') {
                rec2.emplace_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(c);
            }
        }
        if (!tmp.empty()) {
            rec2.push_back(tmp);
        }

        IC(rec1, rec2);

        int n = rec1.size();
        int m = rec2.size();
        int i = 0;
        while (i < n || i < m) {
            auto word1 = i < n ? rec1[i] : "";
            auto word2 = i < m ? rec2[i] : "";

            // auto word1 = rec1[i], word2 = rec2[i];
            int k1 = 0;
            while (k1 < word1.size() && word1[k1] == '0') {
                ++k1;
            }
            word1 = word1.substr(k1);

            k1 = 0;
            while (k1 < word2.size() && word2[k1] == '0') {
                ++k1;
            }
            word2 = word2.substr(k1);

            IC(word1, word2);
            IC(word1.empty(), word2.empty());

            if (word1.empty() && word2.empty()) ++i;
            else if (word1.empty() && !word1.empty()) return -1;
            else if (!word1.empty() && word2.empty()) return 1;
            else if (std::stoi(word1) < std::stoi(word2)) return -1;
            else if (std::stoi(word1) > std::stoi(word2)) return 1;
            else ++i;
        }

        return 0;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    string version1 = "1.01";
    string version2 = "1.001";


    version1 = "1.0";
    version2 = "1.0.0";

    version1 = "0.1";
    version2 = "1.1";
    IC(version1, version2);

    IC(solution->compareVersion(version1, version2));
    // code end

    return 0;
}