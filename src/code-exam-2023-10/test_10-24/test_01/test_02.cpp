#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;
void out_qu(queue<int> qu){
    vector<int> qu_;
    while(!qu.empty()){
        qu_.emplace_back(qu.front());
        qu.pop();
    }
    IC(qu_);
}
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


    for (int i = 0; i < T; ++i) {
        int node;
        cin >> node;

        if (leaks[node] == 2) {
            leaks[node] = 3;

            IC(leaks);

            queue<int> qu;
            
            for(int j = 1; j <= n; ++j){
                if(leaks[j] == 1) qu.emplace(j);
            }

            out_qu(qu);

            while (!qu.empty()) {
                auto v = qu.front();qu.pop();

                for (auto& u : edges[v]) {
                    if (leaks[u] == 3) {
                        leaks[u] = 1;
                        qu.emplace(u);
                    }
                }

                out_qu(qu);
                IC(leaks);
            }

            IC(leaks);
        }

        int cnt = 0;
        for(int i = 1; i<=n; ++i){
            if(leaks[i] == 1) ++cnt;
        }

        cout<<cnt<<endl;
    }




    return 0;

}
// 64 位输出请用 printf("%lld")