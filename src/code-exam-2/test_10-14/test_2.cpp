#include <icecream.hpp>
#include <iostream>
#include <queue>


using namespace std;

int main(int argc, char const *argv[]) {

    priority_queue<int, vector<int>, std::less<int>> pqu;
    pqu.push(10);
    pqu.push(1);
    pqu.push(2);

    //  IC(pqu);

    while (!pqu.empty()) {
        IC(pqu.top());
        pqu.pop();
    }

    return 0;
}
