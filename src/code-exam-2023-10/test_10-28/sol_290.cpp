#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        stringstream ss(s);
        string tmp;

        unordered_map<char, string> ump_c;
        unordered_map<string, char> ump_s;

        for (auto &c: pattern) {
            std::getline(ss, tmp, ' ');

            IC(c, tmp);
            IC(ump_c, ump_s);

            if (ump_c.count(c) && ump_c[c] != tmp) return false;
            if (ump_s.count(tmp) && ump_s[tmp] != c) return false;

            if (!ump_c.count(c) && !ump_s.count(tmp)) {
                ump_c[c] = tmp;
                ump_s[tmp] = c;
            }

            tmp.clear();
        }

        std::getline(ss, tmp, ' ');

        IC(tmp);


        return tmp.empty();
    }
};


// class Solution {
// public:
//     bool wordPattern(string pattern, string s) {

//         stringstream ss(s);
//         string tmp;
//         // while(std::getline(ss, tmp, ' ')){
//         //     IC(tmp);
//         // }

//         unordered_map<char, string> ump_c;
//         unordered_map<string , char> ump_s;

//         for(auto &c: pattern){
//             std::getline(ss, tmp, ' ');

//             IC(c, tmp);
//             IC(ump_c, ump_s);

//             if(ump_c.count(c) && ump_c[c] != tmp) return false;
//             if(ump_s.count(tmp) && ump_s[tmp] != c) return false;

//             if(!ump_c.count(c) && !ump_s.count(tmp)){
//                 ump_c[c] = tmp;
//                 ump_s[tmp] = c;
//             }
//         }


//         return true;
//     }
// };

int main(int argc, char const *argv[]) {
    string patten = "abba";

    string s = "dog cat cat dog";

    IC(patten, s);

    Solution sol;

    IC(sol.wordPattern(patten, s));

    return 0;
}
