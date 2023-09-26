#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <icecream.hpp>

using namespace std;

class Solution{
public:

};

class Status{
public:
    int i;
    int j;
    int cos
};

int main(){
    int n;

    n = 3;
    vector<vector<int>> nums(n, vector<int>(2,0));

    nums = {{3,4}, {-3,4}, {2,3}};

    unordered_map<int, vector<int>> ump;
    for(const auto &ele: nums){
        ump[ele.back()].emplace_back(ele.front());
    }

    IC(ump);

    for(auto &item: ump){
        std::sort(item.second.begin(), item.second.end(), [](const int&a, const int &b){
            return std::abs(a) < std::abs(b);
        });
    }

    IC(ump);





//    std::sort(nums.begin(), nums.end(),[](const vector<int> & a, const vector<int> &b){
//        return a.front() == b.front() ? std::abs(a.back()) < std::abs(b.back()) : a.front() < b.front();
//    });
//
//    IC(nums);
//
//
//    int y_max = 0;
//    for(const auto &ele: nums){
//        y_max = std::max(y_max, ele.back());
//    }
//
//    IC(y_max);







    return 0;
}