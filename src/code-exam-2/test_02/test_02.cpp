#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> a(n), b(n);

    for(int i = 0; i< n; ++i){
        cin>>a[i];
    }

    for(int i = 0; i< n; ++i){
        cin>>b[i];
    }

    int ans = 0;

    for(int i = 0; i< n; ++i){
        ans += std::min({
                (int)std::abs(a[i] - b[i]),
                (int)std::abs(a[i] * (-1) - b[i]),
                (int)std::abs(a[i] - b[i] * (-1)),
                (int)std::abs(a[i] * (-1) - b[i] * (-1))
        });
    }

    cout<<ans<<endl;
    return 0;

}