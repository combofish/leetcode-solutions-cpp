#include <bits/stdc++.h>
#include <icecream.hpp>


using namespace std;
vector<int> get_nums(string &s) {
    int n = s.size();
    string tmp;
    vector<int> nums;
    stringstream ss(s);
    while (getline(ss, tmp, ',')) {
        nums.emplace_back(stoi(tmp));
    }
    return nums;
}

bool is_satified(const vector<int> nums, int k, int t) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {

        int sub_n = std::min(n, i + k + 1);

        for (int j = i + 1; j < sub_n; ++j) {
            if (std::abs(nums[i] - nums[j]) <= t) {
                return true;
            }

            // if ((std::abs(nums[i] - nums[j]) <= t) &&
            //     (std::abs(i - j) <= k)) {
            //     return true;
            // }
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {

    string s;
    int k = 3;
    int t = 0;

    std::getline(cin, s);
    IC(s);

    int sz = s.size();
    int lk = 0;
    while (lk < sz && s[lk] != '[') {
        ++lk;
    }
    s = s.substr(++lk);

    sz = s.size();
    lk = 0;
    while (lk < sz && s[lk] != ']') {
        ++lk;
    }

    string in_s = s.substr(0, lk);
    auto nums = get_nums(in_s);
    IC(in_s, nums);

    s = s.substr(lk);

    // k start
    sz = s.size();
    lk = 0;
    while (lk < sz && !std::isdigit(s[lk])) {
        ++lk;
    }
    s = s.substr(lk);

    // k end
    lk = 0;
    sz = s.size();
    while (lk < sz && s[lk] != ',') {
        ++lk;
    }

    string in_k = s.substr(0, lk);
    IC(in_k);

    // end t
    s = s.substr(lk);

    k = std::stoi(in_k);
    
    // cout << "k = " << k << endl;
    // s = s.substr(lk);
    // cout<< "cur s = ("<<s<<")"<<endl;


    IC(s);
    sz = s.size();
    lk = 0;

    while (lk < sz && !std::isdigit(s[lk])) {
        ++lk;
    }

    s = s.substr(lk);


    // while(lk < sz && !std::isdigit(s[lk])){
    //     cnt = cnt * 10 + (s[lk] - '0');
    //     lk++;
    // }
    // cout << s << endl;

    t = std::stoi(s);
    // cout << "t = " << t << endl;
    //t = cnt;


    // vector<int> nums = {1, 2, 3, 1};
    // int k = 3;
    // int t = 0;

    cout << "nums.size()=" << nums.size() << endl;
    cout << "k=" << k << endl;
    cout << "t=" << t << endl;


    auto ans = is_satified(nums, k, t);
    if (ans) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
