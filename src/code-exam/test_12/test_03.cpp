//
// Created by larry on 23-5-6.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;

    vector<pair<int,int>> monsters(k);
    for(int i = 0;i<k;++i){
        cin>>monsters[i].first>>monsters[i].second;
    }

    pair<int,int> que,pri;
    cin>>que.first>>que.second;
    cin>>pri.first>>pri.second;

    vector<vector<string>> board(n, vector<string>(n));

    for(int i = 0; i< n; ++i)

    return 0;
}