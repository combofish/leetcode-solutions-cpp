#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;



int main(){

    int n;
    cin>>n;

    unordered_set<int> uet;

    for(int i = 0; i< n; ++i){
        int tmp;
        cin>>tmp;
        uet.insert(tmp);
    }

    int s;
    cin>>s;

    int ans = 0;
    // for(int i = 1; i< s/ 2 + 1; ++i){
    //     if(!uet.count(i) && !uet.count(s - i)) {
    //         // ++ans;
    //         // uet.insert(i);

    //         if(i == s-i){
    //             ++ans;
    //             uet.insert(i);
    //         }else{
    //             ++ans;
    //             ++ans;
    //             uet.insert(i);
    //             uet.insert(s - i);
    //         }
    //     }
    // }

    for(auto &item: uet){
        if(!uet.count(s - item)) uet.insert(s - item);
    }

    for(int x  = 1; x< s; ++x){
        if(uet.count(x)) continue;

        auto y = s - x;
        if(x > y) break;

        if(x == y && !uet.count(y)) ++ans;
        if(x < y && !uet.count(y)) ans += 2;

    }

    cout<<ans<<endl;


    return 0;
}
