#include <iostream>
#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

int n;

void get_distances(vector<vector<int>>& distances,
                   unordered_map<int, unordered_set<int>>& edges,
                   int u, int end_node) {

    queue<int> qu;
    qu.push(u);
    int cnt = 0;

    while (!qu.empty()) {
        int sz = qu.size();
        ++cnt;

        while (sz-- > 0) {
            auto node = qu.front();
            qu.pop();
            

            for (auto& v : edges[node]) {

                IC(v);

                if (v == end_node) {
                    distances[u][end_node] = cnt;
                    distances[end_node][u] = cnt;

                    return;

                } else {
                    qu.push(v);
                }
            }
        }
    }





}
int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    // int n;
    cin >> n;

    unordered_map<int, unordered_set<int>> edges;
    vector<vector<int>> distances(n, vector<int>(n, -1));

    int a, b;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        edges[a].insert(b); //, InputIterator last)
        edges[b].insert(a);

        distances[a][b] = 1;
        distances[b][a] = 1;
    }

    for(int i = 0; i<n; ++i) distances[i][i] = 0;

    IC(distances, edges);

    


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // if (i == j) distances[i][j] = 0;

            if(distances[i][j] == -1){
                get_distances(distances, edges, i, j);
            }
        }
    }

    vector<int> ans(n);

    for(int i = 0; i < n; ++i){
        int sum_val = 0;

        for(int j = 0; j< n; ++j){
            if(i == j) continue;

            sum_val += distances[i][j];
        }

        ans[i] = sum_val;
    }


    for(auto &num: ans){
        cout<<num<<" ";
    }
    cout<<endl;






    return 0;

}
// 64 位输出请用 printf("%lld")



/***
 * 
 * 
 * 
 * 
 * 6
0 1
0 2
2 3
2 4
2 5


8 12 6 10 10 10




///

2
1 0


1 1


over time

*/