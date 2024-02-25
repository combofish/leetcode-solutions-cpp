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
            if ((std::abs(nums[i] - nums[j]) <= t) &&
                (std::abs(i - j) <= k)) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {

    string s;
    int k = 3;
    int t = 0;

    std::getline(cin, s);
    cout << "ori = " << s << endl;
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
    s = s.substr(lk + 7);


    //cout << in_s << endl;
    auto nums = get_nums(in_s);

    //cout << s << endl;
    //cout << "nums.size() = " << nums.size() << endl;


    lk = 0;
    sz = s.size();
    while (lk < sz && s[lk] != ',') {
        ++lk;
    }

    string in_k = s.substr(0, lk);
    // cout << "in_k = " << in_k << endl;

    s = s.substr(lk);

    k = std::stoi(in_k);
    //cout << "k = " << k << endl;

    s = s.substr(lk + 6);
    // cout << s << endl;

    t = std::stoi(s);
    // cout << "t = " << t << endl;


    // vector<int> nums = {1, 2, 3, 1};
    // int k = 3;
    // int t = 0;


    auto ans = is_satified(nums, k, t);
    if (ans) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}


// bool is_satified(const vector<int> nums, int k, int t) {
//     int n = nums.size();

//     for (int i = 0; i < n; ++i) {

//         int sub_n = std::min(n, i + k + 1);

//         for (int j = i + 1; j < sub_n; ++j) {
//             if ((std::abs(nums[i] - nums[j]) <= t) &&
//                 (std::abs(i - j) <= k)) {
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// int main(int argc, char const *argv[]) {

//     vector<int> nums = {1, 2, 3, 1};
//     int k = 3;
//     int t = 0;


//     auto ans = is_satified(nums, k, t);
//     if (ans) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }

//     return 0;
// }


// int main(int argc, char const *argv[]) {


//     unordered_set<char> uet = {'a', 'e','i','o','u'};

//     string s = "tryhard";
//     int k = 4;

//     int ans = 0;
//     int cnt = 0;

//     int n = s.size();
//     k = std::min(n, k);

//     for(int i = 0; i<k ; ++i){
//         if(uet.count(s[i])){
//             ++cnt;
//         }
//     }

//     ans = std::max(ans, cnt);

//     for(int i = k; i<n; ++i){
//         if(uet.count(s[i])){
//             ++cnt;
//         }

//         if(uet.count(s[i-k])){
//             --cnt;
//         }

//         ans = std::max(ans, cnt);
//     }

//     cout<<ans<<endl;


//     return 0;
// }
