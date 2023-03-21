/**
-- question: 实现 Trie (前缀树)
-- method:
 - [ ] 字典树

--result:

-- analyse:
Time: O(1)
Space: O( |T| * 26 )
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <memory>

class Solution {

    // function start.
public:
private:
    // function end.
};

class Trie {
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string prefix) {
        auto node = this;
        for (auto &ch: prefix) {
            ch -= 'a';
            if (!node->children[ch]) return nullptr;
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {
    }

    void insert(string word) {
        auto node = this;
        for (auto &ch: word) {
            ch -= 'a';
            if (!node->children[ch]) node->children[ch] = new Trie();
            node = node->children[ch];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        auto node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }

    ~Trie() {
        cout << "Can this exec?" << endl;

        for (int i = 0; i < this->children.size(); i++) {
            if (this->children[i]) {
                delete this->children[i];
            }
        }
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    Trie *trie = new Trie();
    trie->insert("apple");
    auto res1 = trie->search("apple");  // 返回 True
    auto res2 = trie->search("app");    // 返回 False
    auto res3 = trie->startsWith("app");// 返回 True
    trie->insert("app");
    auto res4 = trie->search("app");// 返回 True

    IC(res1, res2, res3, res4);
    IC(true, false, true, true);

    delete trie;


    // code end

    return 0;
}
