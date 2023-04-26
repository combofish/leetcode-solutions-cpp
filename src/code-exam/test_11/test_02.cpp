//
// Created by larry on 23-4-26.
//
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

//class ListNode{
//    int val;
//    ListNode* next;
//public:
//    ListNode():val(0){}
//    ListNode(int vl):val(vl){}
//};

int main() {

    int l, r;
//    cin>>l>>r;

    l = 1;
    r = 3;

    int N;
    N = 3;
//    cin >> N;
    vector<vector<int>> ops(N, vector<int>(2, 0));

//    for (int i = 0; i < N; i++) {
//        cin >> ops[i][0] >> ops[i][1];
//    }

//    ops = {{2, 2},
//          {3, 2},
//         {1, 1}};

    ops = {{1, 1},
           {3, 1}};

    std::list<int> rec;
    for (int i = l; i <= r; i++) {
        rec.push_back(i);
    }

    for (auto &op: ops) {
        if (op.front() == 1) {
            if(rec.size() < op.back()) continue;
            for (int i = 0; i < op.back(); i++) {
                rec.pop_front();
            }
        } else if (op.front() == 2) {
            rec.remove(op.back());
        } else if (op.front() == 3) {
            rec.push_back(op.back());
        }
    }

    cout << rec.front() << endl;


    return 0;
}