#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;


int main(int argc, char const *argv[]) {
    char *a1 = "bresee";
    char a2[10] = "bresee";

    IC(sizeof(a1), sizeof(a2));


    char a11[] = "bresee";
    char a22[] = {'b', 'r','e','s','e','e'};

    IC(sizeof(a11), sizeof(a22));


    return 0;
}
