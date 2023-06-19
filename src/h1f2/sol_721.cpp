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

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 1; i < n; ++i) {
            parent[i] = i;
        }
    }

    void Union(int idx1, int idx2) {
        parent[Find(idx1)] = Find(idx2);
    }

    int Find(int idx) {
        if (parent[idx] != idx) {
            parent[idx] = Find(parent[idx]);
        }
        return parent[idx];
    }
};

class Solution {

    // function start.
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, int> e2idx;
        unordered_map<string, string> e2name;

        int emailCount = 0;
        for (const auto &account: accounts) {
            auto name = account.front();
            int sz = account.size();
            for (int i = 1; i < sz; ++i) {
                auto email = account[i];
                if (!e2idx.count(email)) {
                    e2idx[email] = emailCount++;
                    e2name[email] = name;
                }
            }
        }

        UnionFind uf(emailCount);
        for (const auto &account: accounts) {
            auto firstEmail = account[1];
            auto firstIdx = e2idx[firstEmail];
            int sz = account.size();
            for (int i = 2; i < sz; ++i) {
                uf.Union(firstIdx, e2idx[account[i]]);
            }
        }

        std::map<int, vector<string>> idx2emails;
        for (auto &item: e2idx) {
            auto idx = uf.Find(item.second);
            vector<string> &account = idx2emails[idx];
            account.emplace_back(item.first);
            idx2emails[idx] = account;
        }

        vector<vector<string>> merged;
        for (auto &item: idx2emails) {
            std::sort(item.second.begin(), item.second.end());
            auto name = e2name[item.second.front()];
            vector<string> rec;
            rec.emplace_back(name);
            for (auto &email: item.second) {
                rec.emplace_back(email);
            }
            merged.emplace_back(rec);
        }
        return merged;


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"},
                                       {"John", "johnnybravo@mail.com"},
                                       {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
                                       {"Mary", "mary@mail.com"}},
            ans = {{"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
                   {"John", "johnnybravo@mail.com"},
                   {"Mary", "mary@mail.com"}};


    IC(accounts, ans);
    IC(solution->accountsMerge(accounts));
    // code end

    return 0;
}