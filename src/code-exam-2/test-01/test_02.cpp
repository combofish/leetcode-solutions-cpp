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

//    std::sort(recs.begin(), recs.end(), [](const vector<int> &a, const vector<int> &b){
//        return a.front() < b.front();
//    });

    int ans = 0;

    vector<int> rec(n+1);

    for(const auto &item: recs){
        for(int i = item.front(); i+1 <= item.back(); ++i){
            rec[i+1] = 1;
        }
    }

    for(int i = 0; i <= n; ++i){
        cout<<rec[i]<<endl;
    }

    int prev = 0;
    for(int i= 0; i<=n; ++i){
        rec[i] += prev;
        prev = rec[i];
    }

    cout<<endl<<endl;
    for(int i = 0; i <= n; ++i){
        cout<<rec[i]<<endl;
    }

    for(int i = k; i<=n; ++i){
        ans = std::max(ans, rec[i] - rec[i-k]);
    }


    cout<<n<<m<<k<<endl;
    cout<<ans<<endl;







    return 0;
}