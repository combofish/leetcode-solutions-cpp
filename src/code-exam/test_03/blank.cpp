//
// Created by larry on 23-3-25.
//

#include <iostream>
#include <vector>
#include <stack>

#include <icecream.hpp>
#include "combofish_utils.hpp"
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
//        int n;
//        cin >> n;
//        vector<int> inT(n, 0), outT(n, 0);
//        for (int i = 0; i < n; i++) cin >> inT[i];
//        for (int i = 0; i < n; i++) cin >> outT[i];
//
//        IC(inT, outT);

        // int n = 3;
        vector<int> inT = {1, 2, 3}, outT = {3, 1, 2};

        stack<int> st;

        int ok = 0;
        for(auto &num: inT){
            while(!st.empty() && st.top() == outT[ok]){
                st.pop();
                ok++;
            }
            st.push(num);
        }

        outStack(st);

        while(!st.empty() && st.top() == outT[ok]){
            st.pop();
            ok++;
        }

        outStack(st);
        cout<< st.empty() <<" "<< ok << endl;


    }

    return 0;
}

/**
  1
    3
    1 2 3
    1 2 3

*/