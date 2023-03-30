//
// Created by larry on 23-3-30.
//

#include <iostream>
#include <vector>
#include <stack>

#include <unordered_map>
#include <icecream.hpp>
#include <unordered_set>
using namespace std;

int main() {

    int n, m;
    // cin>>n>>m;
    n = 5;
    m = 2;

    vector<pair<char, vector<int>>> rec;
    // for (int i = 0; i < n; i++) cin >> rec[i].first >> rec[i].second;
    rec = {
            {'b', {1}},
            {'b', {2}},
            {'m', {1, 10}},
            {'m', {2, 20}},
            {'m', {2, 30}}
    };

    IC(rec);
    IC(m, n);

    unordered_map<int, int> prices;
    for (auto &item: rec) {
        if (item.first == 'm') {
            prices[item.second.front()] = item.second.back();
        }
    }


    int ans = 0;

    // vector<int> canPick;
    // vector<int> stores;
    unordered_set<int> canPick;

    int i = 0;
    while (i < n) {
        if (rec[i].first == 'b') {
            canPick.insert(rec[i].second.front());
            i++;
        } else {
            // 'm'
            int rk = i;
            while (rk + 1 < n && rec[rk + 1].first == 'm') {
                rk++;
            }

            int max_val = 0;
            for (int j = i; j <= rk; j++) {

            }

            IC(canPick, max_val);

            canPick.clear();
            i = rk+1;
        }
    }


    cout << ans << endl;

    return 0;
}

/**
*
 stack<int> st;
    int ans = 0;
    int i = 0;
    while (i < n) {
        if (rec[i].first == 'b') {
            st.push(rec[i].second.front());
            i++;
            continue;
        }

        int lk = i + 1;
        unordered_map<int, int> can_sale;
        can_sale.emplace(rec[i].second.front(), rec[i].second.back());

        while (lk < n && rec[lk].first == 'm') {
            can_sale[rec[lk].second.front()] = rec[lk].second.back();
            lk++;
        }

        IC(can_sale);

        int tmp_max = 0;
        while (!st.empty()) {
            if (can_sale.count(st.top())) tmp_max = std::max(tmp_max, can_sale[st.top()]);
            st.pop();
        }
        ans += tmp_max;

        i = lk;
    }

*/