//
// Created by larry on 23-4-1.
//

#include <iostream>
#include <vector>

#include <icecream.hpp>

using namespace std;

int main() {

    int N, M, K;

    N = 3;
    M = 3;
    K = 2;

    IC(N, M, K);

    vector<int> qs(K, 0);
    qs = {1, 2};

    vector<vector<int>> nums(N, vector<int>(M, 0));

    nums = {{5, 5, 0},
            {0, 5, 5},
            {5, 3, 2}};

    IC(qs, nums);


    return 0;
}