#include <icecream.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool debug = true;
int n, m;
inline void process(const string &ip) {
    unordered_map<char, int> ump;
    int sz = ip.size();

    for (int i = 0; i < sz; ++i) {
        if (!ump.count(ip[i])) {
            ump[ip[i]] = 0;
            continue;
        }
        if (i > 0 && ip[i] == ip[i - 1]) continue;

        if (i > 0 && ip[i] != ip[i - 1]) {
            ++ump[ip[i]];
        }
    }

    IC(ump);

    // case 1
    if (ump.size() == 1) {
        cout << 1 << endl;
        return;
    }

    bool all_is_one = true;
    for (auto &item: ump) {
        if (item.second > 1) {
            all_is_one = false;
            break;
        }
    }

    // case 1
    if (all_is_one) {
        cout << 1 << endl;
        return;
    }


    int cnt = 0;
    for (auto &item: ump) {
        if (item.second >= n) {
            ++cnt;
        }
    }

    cout << cnt << endl;
}

int main() {

    // int n, m;
    n = 3;
    m = 8;

    IC(n, m);

    vector<string> ips(m, "");

    ips.front() = "DDDDDDD";

    ips = {
            //"DDDDD",
            //"XXXXXYYYY",
            //"EFFFFQ",
            //"BFFFFFFFFBBBFBFFBB",
            "CDDAAAADDCADDDCC",
            //"CCDAADDDACCCCDDAAADCDDAAA",
            //"EEEQQQBBBQQQEEEBEQBBEEQQBBBB",
            //"EEBBAAGGEEBBAAGGEEBBAAGGEBAG"
    };

    for (const auto &item: ips) {
        process(item);
    }


    return 0;
}