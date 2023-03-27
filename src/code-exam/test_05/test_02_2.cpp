//
// Created by larry on 23-3-26.
//
#include <iostream>
#include<cmath>
#include <icecream.hpp>

using namespace std;

const int n = 500;

int cal(double a, double b) {
    double d_x = (b - a) / n;

    double P = 0;

    for (int i = 0; i < n; i++) {
        auto x_i = a + i * d_x;
        auto tmp = ::sin(::sqrt(x_i)) / 5.68;

        P += tmp * d_x;
        IC(tmp * d_x);
        IC(P);
    }

    cout<<P<<endl;
    return P > 0.5 ? 1 : 0;
}

int main() {

    int a, b;

    // cin>>a>>b;
    a = 1;
    b = 6;

    cout << cal(a, b) << endl;

    return 0;
}