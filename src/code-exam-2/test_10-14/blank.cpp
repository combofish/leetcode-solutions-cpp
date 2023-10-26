#include <icecream.hpp>
#include <iostream>
#include <string>

using namespace std;

inline pair<int, int> expand(const string &s, int i, int j, int sz) {
    while (0 <= i && j < sz && s[i] == s[j]) {
        --i;
        ++j;
    }

    return {++i, --j};
}

int main(int argc, char const *argv[]) {
    string s = "babad";

    auto sz = s.size();

    for (int i = 0; i < sz; ++i) {
        auto a = expand(s, i, i, sz);
        auto b = expand(s, i, i + 1, sz);

        IC(i, a, i + 1, b);
    }


    return 0;
}
