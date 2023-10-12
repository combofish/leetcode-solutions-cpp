#include <icecream.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

inline bool check(unordered_map<char, int> &ump) {
    if (ump['r'] > 0 && ump['e'] > 0 && ump['d'] == 0) {
        // IC('1');
        return true;
    }
    return false;
}

inline bool is_key_char(const char c) {
    if (c == 'r' || c == 'd' || c == 'e') return true;
    return false;
}

int process(const string &str) {
    unordered_map<char, int> ump;
    for (auto &c: str) {
        if (is_key_char(c))
            ++ump[c];
    }
    int ans = 0;
    int sz = str.size();


    for (int i = 0; i < sz; ++i) {
        auto clone_ump = ump;

        auto j = sz - 1;
        while (j >= i && check(clone_ump)) {
            ++ans;

            if (is_key_char(str[j]))
                --clone_ump[str[j]];

            --j;
        }

        --ump[str[i]];
    }

    IC(ans);
    return ans;
}


int main() {

    string str = "raefadr";

    string tmp;
    vector<string> strs;
    stringstream ss(str);

    while (std::getline(ss, tmp, 'd')) {
        if (tmp.size() > 1)
            strs.emplace_back(tmp);
    }

    // IC(strs);

    int ans = 0;
    for (const auto &item: strs) {
        ans += process(item);
        IC(item, ans);
    }

    cout << ans << endl;


    return 0;
}