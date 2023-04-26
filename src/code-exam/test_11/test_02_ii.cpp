//
// Created by larry on 23-4-26.
//
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <unordered_set>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int vl) : val(vl), next(nullptr) {}
};

void del_list_node(ListNode *node) {
    if (node == nullptr) return;
    del_list_node(node->next);
    delete node;
}

int main() {

    int l, r;
    cin >> l >> r;

//     l = 1;
//      r = 3;

    int N;
  //  N = 3;
   cin >> N;
    vector<vector<int>> ops(N, vector<int>(2, 0));

    for (int i = 0; i < N; i++) {
        cin >> ops[i][0] >> ops[i][1];
    }

//    ops = {{2, 2},
//          {3, 2},
//         {1, 1}};

//    ops = {{1, 1},
//           {3, 1}};

    //int sz = r - l + 1;

    auto dummyNode = new ListNode(0);
    unordered_set<int> uet;

    auto head = dummyNode;
    for (int i = l; i <= r; i++) {
        head->next = new ListNode(i);
        head = head->next;

        uet.insert(i);
    }


    for (auto &op: ops) {
        if (op.front() == 1) {
            if(op.back() > uet.size()) continue;
            while (op.back()--) {
                auto node = dummyNode->next;
                dummyNode->next = node->next;
                uet.erase(node->val);
                delete node;
            }
        } else if (op.front() == 2) {
            if(!uet.count(op.back())) continue;

            auto curr = dummyNode;
            while (curr->next != nullptr) {
                if (curr->next->val == op.back()) {
                    auto tmp = curr->next;
                    curr->next = curr->next->next;
                    uet.erase(tmp->val);
                    delete tmp;
                    // sz -=1;
                    break;
                }
                curr = curr->next;
            }
        } else if (op.front() == 3) {
            if(op.back() < l && op.back()> r) continue;
            if(uet.count(op.back())) continue;


            auto tmp = dummyNode;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = new ListNode(op.back());
            uet.insert(op.back());
        }
    }

    cout << dummyNode->next->val << endl;


    del_list_node(dummyNode);

    return 0;
}