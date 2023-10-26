#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    int n, m, T;
    cin >> n >> m >> T;

    vector<vector<int>> nums(m, vector<int>(2));
    unordered_map<int, unordered_set<int>> edges;

    for (int i = 0; i < m; ++i) {
        cin >> nums[i][0] >> nums[i][1];

        edges[nums[i][0]].insert(nums[i][1]);
        edges[nums[i][1]].insert(nums[i][0]);
    }

    // vector<int> as(T);
    // for(int i =0; i<T; ++i){
    //     cin>>as[i];
    // }

    // 1 湖
    // 2 普通节点
    // 3 坑

    vector<int> leaks(n + 1, 2);
    leaks[1] = 1;

    unordered_set<int> all_leaks;
    all_leaks.insert(1);


    for (int i = 0; i < T; ++i) {
        int node;
        cin >> node;

        if (leaks[node] == 2) {
            leaks[node] = 3;

            // for(auto &item: all_leaks){

            // }

            queue<int> qu;
            
            // for(int j = 1; j <= n; ++j){
            //     if(leaks[j] == 1) qu.emplace(j);
            // }

            for(auto &item: all_leaks){
                qu.emplace(item);
            }

            while (!qu.empty()) {
                auto v = qu.front();qu.pop();

                for (auto& u : edges[v]) {
                    if (leaks[u] == 3) {
                        leaks[u] = 1;
                        all_leaks.insert(u); // , InputIterator last)
                        qu.emplace(u);
                    }
                }
            }
        }

        // int cnt = 0;
        // for(int j = 1; j<=n; ++j){
        //     if(leaks[j] == 1) ++cnt;
        // }

        // cout<<cnt<<endl;

        cout<< all_leaks.size()<<endl;
    }




    return 0;

}
// 64 位输出请用 printf("%lld")


// 3 2 3
// 1 2
// 2 3
// 3 2 1


// 1
// 3
// 3