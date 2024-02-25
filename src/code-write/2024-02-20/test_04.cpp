#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
class Trie {
    array<Trie *, 26> children;
    bool isEnd;

    Trie *findPrefix(string word) {
        auto curr = this;
        for (auto &c: word) {
            if (curr->children[c - 'a'] == nullptr) {
                return nullptr;
            }
            curr = curr->children[c - 'a'];
        }
        return curr;
    }

public:
    Trie() : isEnd(false) {
        children.fill(nullptr);
    }

    void insert(string word) {
        auto curr = this;
        for (auto &c: word) {
            auto ch = c - 'a';
            if (curr->children[ch] == nullptr) {
                curr->children[ch] = new Trie();
            }
            curr = curr->children[ch];
        }
        isEnd = true;
    }

    bool search(string word) {
        auto node = findPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return findPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(int argc, char const *argv[]) {

    // string s = "ADOBECODEBANC", t = "ABC", ans = "BANC";
    vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}};

    int ans = 1;

    // IC(s, t, ans);
    IC(grid, ans);

    Solution sol;
    IC(sol.numIslands(grid));


    return 0;
}
