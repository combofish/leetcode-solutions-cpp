#include <iostream>
#include <icecream.hpp>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){

    cout<<"hello world"<<endl;

    unordered_map<int, vector<int>> ump;
    ump[0].push_back(0);

    for(auto &item: ump){
        cout<<item.second.front()<<endl;
    }

    return 0;
}