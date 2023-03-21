/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <iostream>

class Solution {
public:
    // function start.

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    auto it1 = {2, 4, 1, 2, 5, 6};
    auto it2 = {3, 1, 3, 5, 6, 4};

    queue<int> q1(it1);
    queue<int> q2(it2);
    stack<int> sta;

    int book[10] = {0};

    int t;
    while (!q1.empty() && !q2.empty()) {
        // 游戏循环

        // 1 号出牌
        t = q1.front();
        q1.pop();

        if (book[t] == 0) {
            // 桌面上没有牌面为t的
            sta.push(t);
            book[t] = 1;
        } else {
            q1.push(t);
            while (sta.top() != t) {
                book[sta.top()] = 0;
                q1.push(sta.top());
                sta.pop();
            }
        }


        cout << "1. end one turn." << endl;
        // IC(sta);
        out_qu(q1);
        out_qu(q2);
        out_sta(sta);

        // 2 号出牌
        t = q2.front();
        q2.pop();

        if (book[t] == 0) {
            sta.push(t);
            book[t] = 1;
        } else {
            q2.push(t);
            while (sta.top() != t) {
                book[sta.top()] = 0;
                q2.push(sta.top());
                sta.pop();
            }
        }

        out_line();
        cout << "2. end one turn." << endl;
        // IC(sta);
        out_qu(q1);
        out_qu(q2);
        out_sta(sta);

        cout << endl;
        cout << endl;
    }

    if (q1.empty()) {
        cout << "2 Win" << endl;
        cout << "2's cards are: ";

        while (!q2.empty()) {
            cout << "\t" << q2.front();
            q2.pop();
        }
        cout << endl;

        if (sta.empty()) {
            cout << "No card on desktop." << endl;
        } else {
            while (!sta.empty()) {
                cout << "\t" << sta.top() << endl;
                sta.pop();
            }
        }
    } else {
        // q2.empty();

        cout << "1 Win" << endl;
        cout << "1's cards are: ";

        while (!q1.empty()) {
            cout << "\t" << q1.front();
            q1.pop();
        }
        cout << endl;

        if (sta.empty()) {
            cout << "No card on desktop." << endl;
        } else {
            while (!sta.empty()) {
                cout << "\t" << sta.top() << endl;
                sta.pop();
            }
        }
    }


    // code end

    delete solution;
    return 0;
}
