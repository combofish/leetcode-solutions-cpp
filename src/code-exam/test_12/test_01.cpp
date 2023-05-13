//
// Created by larry on 23-5-6.
//

#include <iostream>
#include <string>
#include <vector>

#include <icecream.hpp>

using namespace std;

int main() {
    int N;
    // cin>>N;

    N = 14;

    int n = N / 16 + 1;
    vector<int> rec(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> hex >> rec[i];
//    }

    rec = {0xE77F};
//    IC(rec);

    vector<int> bits;
    for(auto &num: rec){
        for(int i = 0; i< 16; ++i){
            bits.push_back(num & 1);
            num>>=1;
        }
    }

//    IC(bits);

    int cnt = 0;
    int bits_size = bits.size();
    for(int i = 0; i< bits_size; ++i){
        if(bits[i] == 1) continue;
        if(i ==0) bits[i] = -1;
        else {
            if(bits[i-1] < 0) bits[i] = bits[i-1] -1;
            else bits[i] = -1;
        }

        cnt = std::max(cnt, -bits[i]);
    }

//    IC(bits, cnt);
//    int result = 0;
//
//    IC(result);
//    for(int step = cnt; step < N/2; ++step){
//        // left move
//
//
//
//        // right move
//
//
//    }

cout<<cnt<<endl;

    return 0;
}