//
// Created by larry on 23-3-26.
//

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N, M;

    N = 4;
    M = 4;

    vector<int> nums(N, 0);
    vector<int> Ls(M, 0), Rs(M, 0), opN(M, 0);
    string ops;

    ops = "=|&=";

    nums = {5, 4, 7, 4};
    Ls = {1, 2, 3, 2};
    Rs = {4, 3, 4, 2};
    opN = {8, 3, 6, 2};


    for (int i = 0; i < M; i++) {
//        int lk, rk;
//        lk = Ls[i], rk = Rs[i];


        for (int j = Ls[i] - 1; j < Rs[i]; j++) {
            if (ops[i] == '|') {
                // or

                nums[j] |= opN[i];

            } else if (ops[i] == '&') {
                // and

                nums[j] &= opN[i];
            } else if (ops[i] == '=') {
                // ==

                nums[j] = opN[i];
            }
        }

    }


    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}