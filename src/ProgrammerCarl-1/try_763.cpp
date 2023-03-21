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
private:

    // function start.
public:

    vector<int> partitionLabels(string s) {
        /**
        unordered_map<char, vector<int>> umap;
        for (int i = 0; i < s.size(); i++) {
            if (umap.find(s[i]) != umap.end()) {
                umap[s[i]].back() = i;
            } else {
                umap[s[i]].emplace_back(i);
                umap[s[i]].emplace_back(i);
            }
        }

        IC(umap);

        vector<vector<int>> tickets;
        for (auto &rec: umap)
            tickets.push_back(rec.second);

        IC(tickets);

        std::sort(tickets.begin(), tickets.end(), [](const vector<int> &a, const vector<int> &b) {
            return a.back() < b.back();
        });

        IC(tickets);


        vector<int> res;
        return res;
         */

        int hash[27] = {0};
        for (int i = 0; i < s.size(); i++)
            hash[s[i] - 'a'] = i;

        vector<int> res;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); i++) {
            right = std::max(right, hash[s[i] - 'a']);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return res;
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    string S = "ababcbacadefegdehijhklij";
    vector<int> rel = {9, 7, 8};

    IC(S, rel);

    IC(solution->partitionLabels(S));

    // code end

    delete solution;
    return 0;
}


