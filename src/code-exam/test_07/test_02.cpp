//
// Created by larry on 23-3-29.
//

#include <iostream>
#include <vector>

#include <icecream.hpp>

using namespace std;

int main() {

    int n, k;

    // cin>>n>>k;

    n = 5;
    k = 2;

    vector<int> ans;
    vector<int> maxN;

    int last = n - k;
    int te = k;
    while (te--) {
        maxN.emplace_back(++last);
    }
    IC(maxN);

    bool can_insert = true;
    int lk = 0;
    for (int i = 0; ans.size() < n;) {
        if (can_insert && lk < k) {
            ans.emplace_back(maxN[lk++]);
            can_insert = false;


            IC('m');
        }
        ans.emplace_back(i + 1);
        i++;
        can_insert = lk >= k ? false : true;

        IC(can_insert, ans, n - k, lk);
    }


    IC(ans, maxN);

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    cout << endl;


    return 0;
}