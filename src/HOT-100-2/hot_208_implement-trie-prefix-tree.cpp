/**
-- question: 实现 Trie (前缀树)
-- method:
 - [ ] 字典树

--result:

-- analyse:
Time: O( 1  |S| )
Space: O( |T| x E )
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:

private:
    // function end.
};
//
//class Trie : public std::enable_shared_from_this<Trie> {
//public:
//    Trie() : child(26), isEnd(false) {}
//
//    void insert(string word) {
//        auto node = shared_from_this();
//        for (auto &c: word) {
//            c -= 'a';
//            // if (!node->child[c]) node->child[c] = new Trie();
//            if (!node->child[c]) node->child[c] = std::make_shared<Trie>();
//            node = node->child[c];
//        }
//        node->isEnd = true;
//    }
//
//    bool search(string word) {
//        auto node = searchPrefix(word);
//        return node != nullptr && node->isEnd;
//    }
//
//    bool startsWith(string prefix) {
//        return searchPrefix(prefix) != nullptr;
//    }
//
//private:
//    vector<std::shared_ptr<Trie>> child;
//    bool isEnd;
//
//    std::shared_ptr<Trie> searchPrefix(string prefix) {
//        // auto node = this;
//        auto node = shared_from_this();
//        for (auto &c: prefix) {
//            c -= 'a';
//            if (!node->child[c]) return nullptr;
//            node = node->child[c];
//        }
//        return node;
//    }
//};


class Trie : public std::enable_shared_from_this<Trie> {
public:
    Trie():child(26), isEnd(false) {

    }

    void insert(string word) {
        auto node = shared_from_this();
        for(auto &ch: word){
            ch -= 'a';
            if(!node->child[ch]) node->child[ch] = std::make_shared<Trie>();
            node = node->child[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        auto node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr;
    }

private:
    vector<std::shared_ptr<Trie>> child;
    bool isEnd;

    std::shared_ptr<Trie> searchPrefix(string prefix){
        auto node = shared_from_this();
        for(auto &ch: prefix){
            ch -= 'a';
            if(!node->child[ch]) return nullptr;
            node = node->child[ch];
        }
        return node;
    }
};


int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<string> inputs = {"Trie", "insert", "search", "search", "startsWith", "insert", "search"};
    vector<vector<string>> ops = {{},
                                  {"apple"},
                                  {"apple"},
                                  {"app"},
                                  {"app"},
                                  {"app"},
                                  {"app"}};

    string ans = "{null, null, true, false, true, null, true}";
    IC(inputs, ops, ans);


    // auto trie = new Trie();
    auto trie = std::make_shared<Trie>();

    trie->insert("apple");
    IC(trie->search("apple"));   // 返回 True
    IC(trie->search("app"));     // 返回 False
    IC(trie->startsWith("app")); // 返回 True
    trie->insert("app");
    IC(trie->search("app"));     // 返回 True



    // code end

    return 0;
}
