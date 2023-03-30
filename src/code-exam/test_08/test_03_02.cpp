//
// Created by larry on 23-3-30.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <icecream.hpp>

using namespace std;

int main() {
    int n;
    // cin>>n;

    n = 4;
    vector<int> nums(n, 0);
//    for (int i = 0; i < n; i++) {
//        cin >> nums[i];
//    }
    nums = {1, 4, -1, 4};
    IC(nums);

    int ans = 1;

    vector<int> maxF(n), minF(n);

    pair<int, int> fin;

    int fk = 0;
    int mk = 0;

    int lan = 0;

    for (int i = 1; i < n; i++) {
        maxF[i] = std::max({maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i]});
        minF[i] = std::min({maxF[i - 1] * nums[i], nums[i], minF[i - 1] * nums[i]});

        ans = std::max(ans, maxF[i]);
    }

    IC(mk, fk, fin);
    
    if (ans == 1) {
        cout << -1 << endl;
        return 0;
    }

    IC(maxF, minF);

    cout << fin.first << " " << fin.second << endl;

    return 0;
}

/**
*
 *
   vector<pair<int, int>> rec;

    int lk = 0;
    for (int i = 0; i < n; i++) {
        if (maxF[i] == ans) {
            lk = i;
            auto tmp = ans;
            while (lk >= 0 && (tmp / nums[lk]) >= 1) {
                tmp /= nums[lk];
                lk--;
            }
            lk++;
            IC(lk, i);

            rec.emplace_back(lk, i);
        }
    }

    IC(rec);
    pair<int, int> fin;
    if (rec.size() == 1) {
        fin = rec.front();
    } else {
        int max_len = 1;
        for (auto &item: rec) {
            auto tmp_len = item.second - item.first;
            if (tmp_len >= max_len) {
                max_len = tmp_len;
                fin = item;
            }
        }
    }
*/