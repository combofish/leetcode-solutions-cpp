
#include <icecream.hpp>

using namespace std;

inline long long fac(int n){
    long long ans = 1;
    vector<int> nums = {1, 2, 6, 24 ,.....}

    1 2 3 4 5

    3 = 
    3 * (2) ( 4)
      * (1) ( 5)

    for (int i = 1; i<=n; ++i){
        ans *=i;
    }

    return ans;
}

int main(int argc, char const *argv[])
{

    int n = 5;
    auto res = fac(n);
    IC(res);
    return 0;
}
