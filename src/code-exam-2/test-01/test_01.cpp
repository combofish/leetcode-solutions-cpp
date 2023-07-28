#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    //    int a,b;
    //
    //    a = 2;
    //    b = 2;

    int n, k;


    //    cin>>n>>k;

    n = 2;
    k = 2;

    int sum_val = 0;
    for (int i = 0; i < n; ++i) {
        sum_val += k * (i + 1);
    }

    //    vector<int> rec(n,0);
    //
    //    for(int i = 0; i <n; ++i){
    //        rec[i] = k * (i + 1);
    //    }

    //cout<<std::accumulate(rec.begin(), rec.end(), 0)<<endl;
    cout << sum_val << endl;


    return 0;
}