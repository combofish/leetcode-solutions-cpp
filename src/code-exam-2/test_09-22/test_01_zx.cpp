#include <icecream.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int time_cost;
int N, K;

void traversal(int u, int end_node, int curr_cost,
               unordered_map<int, vector<int>> &ump,
               vector<bool> &used,
               vector<vector<int>> &boards) {
    if (u == end_node) {
        if (time_cost == -1)
            time_cost = curr_cost;
        else
            time_cost = std::min(time_cost, curr_cost);

        return;
    }


    if (!ump.count(u)) return;

    for (auto &v: ump[u]) {
        if (!used[v]) {
            used[v] = true;

            if (boards[u][v] != -1) {
                traversal(v, end_node, curr_cost + boards[u][v], ump, used, boards);
            }

            used[v] = false;
        }
    }
}


int find_path(int u, int end_node, unordered_map<int, vector<int>> &ump, vector<vector<int>> &boards, int n) {


    vector<bool> used(N + 1, false);
    used[K] = true;


    time_cost = -1;
    traversal(u, end_node, 0, ump, used, boards);


    return time_cost;
}

int main() {

    int N, K;
    N = 4, K = 2;

    // 起始节点  K = 2;
    // 一共有四个节点

    vector<vector<int>> boards = {
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}};
    // 节点到节点的距离。


    // 问是否能到达所有的节点，能到达，最短路径，不能返回 -1， 例子结果是 2。


    vector<vector<int>> costs(N + 1, vector<int>(N + 1, -1));
    unordered_map<int, vector<int>> edges;

    for (auto &item: boards) {
        costs[item[0]][item[1]] = item.back();
        edges[item.front()].emplace_back(item[1]);
    }

    int min_val = -1;

    for (int i = 1; i <= N; ++i) {
        if (i == K) continue;

        auto ans = find_path(K, i, edges, costs, N);

        IC(K, i, ans);

        min_val = std::max(ans, min_val);

        if (ans == -1 || ans == 1e9) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << min_val << endl;

    return 0;
}