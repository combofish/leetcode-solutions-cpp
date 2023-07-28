#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int n, m,k;

    n = 5;
    m = 2;
    k = 3;

    vector<vector<int>> recs(m, vector<int>(2, 0));

    recs = {
            {1,2},
            {3,5}
    };

    std::sort(recs.begin(), recs.end(), [](const vector<int> &a, const vector<int> &b){
        return a.front() < b.front();
    });

    int ans = 0;


    cout<<n<<m<<k<<ans<<endl;







    return 0;
}