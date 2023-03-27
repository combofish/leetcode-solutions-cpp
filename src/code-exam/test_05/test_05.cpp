//
// Created by larry on 23-3-26.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <tuple>
#include <unordered_map>

using namespace std;

int main() {

    int H, W;

    // cin>>H>>W;
    H = 2;
    W = 2;

    int m; // line numbers

    // cin>>m;
    m = 2;

    vector<vector<int>> points(m, vector<int>(4,0));

    points = {
            {0,0,1,1},
            {0,1,1,0}
    };

    // 直线去重
//   unordered_set<std::pair<int,int>> uet = {{0,0}};
//    unordered_map<std::pair<int,int>,int> ump;

    for(auto &item: points){
        int k = (item[3] - item[1]) / (item[2] - item[0]);
        int b = item[1] - k * item[0];

    }


    return 0;
}