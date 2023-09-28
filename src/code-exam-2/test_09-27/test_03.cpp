// #include <icecream.hpp>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/**
main: call f1 call f2 call f3
f1: print 1 call f2
f2: print 2
f3: call f1 print 3
end


1 2 2 1 2 3




main: call f1 call f2 call f3
f1: call f3 print 1 call f2
f2: print 2
f3: call f1 print 3
end


recursion error!
*/
unordered_map<string, vector<string>> ump;
unordered_map<string, int> visited;
bool recursion_flag = false;
vector<string> out_vec;

void traversal(const string& u) {
    // IC(u);

    if (visited[u] == 1) {
        recursion_flag = true;
        return;
    }

    visited[u] = 1;

    auto strs = ump[u];
    int sz = strs.size();

    for (int i = 0; i < sz; ++i) {

        if (strs[i] == "call") {
            traversal(strs[i + 1]);

            if (recursion_flag) return;

        } else if (strs[i] == "print") {
            // cout << strs[i + 1] << " ";
            out_vec.emplace_back(strs[i+1]);
        }

        ++i;
    }


    visited[u] = 2;
}


int main() {

    string line;


    while (std::getline(std::cin, line)) {
        if (line == "end") {
            break;
        }

        string name, body;
        stringstream ss(line);

        std::getline(ss, name, ':');
        std::getline(ss, body);

        vector<string> strs;
        string tmp_str;

        for (const auto& c : body) {
            if (c == ' ') {
                if (!tmp_str.empty()) strs.emplace_back(tmp_str);
                tmp_str.clear();
            } else {
                tmp_str.push_back(c);
            }
        }

        if (!tmp_str.empty()) {
            strs.emplace_back(tmp_str);
            tmp_str.clear();
        }

        // IC(strs);

        // IC(name, body);
        ump[name] = strs;
        visited[name] = 0;
    }

    // IC(ump);

    // cout << "recursion error!" << endl;

    line = "main";

    traversal(line);

    if (recursion_flag) {
        cout << "recursion error!" << endl;
        return 0;
    }else{

        for(auto &ele : out_vec){
            cout<<ele<<" ";
        }
        
    }

    // queue<string> qu;
    // qu.emplace("main");


    // while (!qu.empty()) {
    //     auto curr = qu.front();
    //     qu.pop();

    //     if (visited[curr] == 1) {
    //         cout << "recursion error!" << endl;
    //         return 0;
    //     }

    //     visited[curr] = 1;
    //     auto curr_str = ump[curr];


    //     visited[curr] = 2;
    // }

    cout << endl;

    return 0;
}