#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
// #include <icecream.hpp>

using namespace std;

inline bool is_same_val(unordered_map<char, int>& a,
                        unordered_map<char, int>& b) {
    if (a.size() != b.size()) return false;

    for (auto& item : b) {
        if (a[item.first] != item.second) {
            return false;
        }
    }

    return true;
}


// int main() {
//     // int a, b;
//     // while (cin >> a >> b) { // 注意 while 处理多个 case
//     //     cout << a + b << endl;
//     // }


//     int n;
//     cin >> n;

//     vector<string> strs(n, "");
//     for (int i = 0; i < n; ++i) {
//         cin >> strs[i];
//     }

//     vector<unordered_map<char, int>> umps;

//     for (auto& str : strs) {
//         unordered_map<char, int> ump;

//         for (auto& c : str) {
//             ++ump[c];
//         }

//         umps.emplace_back(ump);
//     }

//     // IC(umps);


//     int cnt = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {

//             if (is_same_val(umps[i], umps[j])) {
//                 ++cnt;
//             }


//         }
//     }

//     cout << cnt << endl;



// }






int main(){
    int n;
    cin>> n;

    // vector<string> strs(n, "");

    // unordered_map<int, vector<unordered_map<char, int>>> strs;

    unordered_map<int, vector<string>> strs;

    string line;

    for(int i = 0; i< n; ++i){
        line.clear();
        cin>>line;

        std::sort(line.begin(), line.end());

        // unordered_map<char, int> ump;
        // for(const auto &c: line){
        //     ++ump[c];
        // }

        strs[line.size()].emplace_back(line);
    }

    int cnt = 0;

    for(auto &item: strs){
        if(item.second.size() <= 1) continue;

        auto cur_n = item.second.size();

        for(int i = 0; i< cur_n; ++i){
            for(int j = i+1; j < cur_n; ++j){
                if(item.second[i] == item.second[j]){
                    ++cnt;
                }

                // if(is_same_val(item.second[i], item.second[j])){
                //     ++cnt;
                // }
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
























// 64 位输出请用 printf("%lld")