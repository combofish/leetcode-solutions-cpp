
#include <icecream.hpp>

using namespace std;


int getResult(int n) {
    auto a = 5 * std::pow(n, 2) + 4 * n + 3;
    auto b = 4 * std::pow(n, 2) + 3 * n + 2;

    auto c = 1 * std::pow(n, 5) + 8 * std::pow(n, 4) + 9 * std::pow(n, 3) + 5 * std::pow(n, 2) + 1 * n + 4;
    return a * b - c;
}


int main(int argc, char const *argv[]) {
    /* code */

    for (int i = 10; i <= 20; ++i) {
        IC(i, getResult(i));
    }


    return 0;
}
