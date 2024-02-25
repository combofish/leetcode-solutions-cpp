
#include <bits/stdc++.h>
#include <icecream.hpp>
using namespace std;


int main(int argc, char const *argv[]) {


    string line;
    std::getline(cin, line);

    int n = line.size();

    line = line.substr(1, n - 2);
    n = line.size();

    IC(line, n);

    vector<string> strs;

    string tmp;
    stringstream ss(line);
    while (std::getline(ss, tmp, ',')) {
        strs.emplace_back(tmp);
    }

    IC(strs);

    vector<vector<int>> ans;
    n = strs.size();

    int sk = 1;
    int i = 0;
    while (i < n) {
        vector<int> curr;

        for (int k = 0; k < sk; ++k) {

            if (i + k >= n) break;

            if (strs[i + k] != "#") {
                curr.emplace_back(std::stoi(strs[i + k]));
            }
        }

        ans.emplace_back(curr);
        i += sk;
        sk *= 2;
    }

    IC(ans);

    cout << "[";
                   优必选科技
    n = ans.size();

    for (int i = 0; i < n; ++i) {

        cout << '[';
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j];
            if (j == ans[i].size() - 1) {
                cout << "]";
            } else {
                cout << ',';
            }
        }

        if (i == n - 1) {
            cout << "]" << endl;
        } else {
            cout << ',';
        }
    }


    return 0;
}
