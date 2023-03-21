/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) : val(_val) {}

    Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};

class Solution {
public:
    // function start.
    /**
     * iterate, queue
     * @param root
     * @return
     */
    int maxDepth(Node *root) {
        if (!root) return 0;
        queue<Node *> que;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            int _size = que.size();
            res++;
            while (_size--) {
                Node *node = que.front();
                que.pop();

                for (Node *child_node: node->children) {
                    if (child_node) que.push(child_node);
                }
            }
        }

        return res;
    }

    /**
     * recursive
     * @param root
     * @return
     */
    int maxDepth_2(Node *root) {
        if (root == nullptr) return 0;
        vector<int> vec{0};
        for (Node *node: root->children) {
            if (node) vec.emplace_back(maxDepth_2(node));
        }
        return 1 + *std::max_element(vec.begin(), vec.end());
    }

    /**
     *
     * @param root
     * @return
     */
    int maxDepth_3(Node *root) {
        _res = 0;
        if (!root) return _res;
        get_depth(root, 1);
        return _res;
    }

private:
    int _res;

    void get_depth(Node *node, int depth) {
        _res = std::max(depth, _res);

        for (Node *_node: node->children) {
            get_depth(_node, depth + 1);
        }

    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    auto t5 = new Node(5);
    auto t6 = new Node(6);
    auto t2 = new Node(2);
    auto t4 = new Node(4);

    vector<Node *> child_1 = {t5, t6};
    auto t3 = new Node(3, child_1);

    vector<Node *> child_2 = {t3, t2, t4};
    auto t1 = new Node(1, child_2);


    int rel = 3;
    IC(rel);
    IC(solution->maxDepth(t1) == rel);
    IC(solution->maxDepth_2(t1) == rel);
    IC(solution->maxDepth_3(t1) == rel);


    delete t1;
    delete t3;
    delete t4;
    delete t2;
    delete t6;
    delete t5;
    // code end

    delete solution;
    return 0;
}


