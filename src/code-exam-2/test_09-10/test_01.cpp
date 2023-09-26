#include <algorithm>
#include <iostream>
#include <vector>
#include <icecream.hpp>
#include <set>

using namespace std;

bool debug = true;

double getMedian(multiset<int> &st){
    auto it = st.begin();
    advance(it, st.size() /2);

    if(st.size() % 2 == 0){
        int a = *it;
        --it;
        return (a + *it) / 2.0;
    }else{
        return *it;
    }
}

int main(){

    int t;

    if(debug){
        t = 1;
    }else{
        cin>> t;
    }



    while(t--> 0){
        int n;
        // cin>>n;
        n = 5;

        vector<int> nums_a(n, 0);
        vector<int> nums_b(n-1, 0);

        if(debug){
            nums_a = {2,2,1,3,5};
            nums_b = {3,1,2,5};

        }else{
            for(int i =0; i< n; ++i){
                cin>>nums_a[i];
            }


            for(int i = 0; i<n-1;++i){
                cin>>nums_b[i];
            }
        }

        multiset<int> st(nums_a.begin(), nums_a.end());

        for(int i = 0; i< n-1; ++i){
            cout<< (double) getMedian(st)<<" ";

            if(debug){
                IC(st, nums_b[i], nums_a[nums_b[i] - 1]);
            }

            auto it = st.find(nums_a[nums_b[i] - 1]);
            if(it != st.end()){
                st.erase(it);
            }

            if(debug){
                cout<<endl;
                IC(st);

            }


        }

        if(st.size() == 1){
            cout<< *st.begin() <<endl;
        }

//        std::sort(nums_a.begin(), nums_a.end());
//
//        for(int i = 0; i< n-1; ++i){
//            auto sz = nums_a.size();
//            IC(nums_a, sz);
//            if(sz%2 == 1){
//                cout<<nums_a[sz/2]<<" ";
//            }else{
//                double mid = 0.0;
//                mid = (double) (nums_a[sz/2] + nums_a[sz/2+1]) / 2;
//                cout<<mid<<" ";
//            }
//
//            nums_a.erase(nums_a.begin() + nums_b[i]);
//
//
//
//            break;
//        }
























    }







































    return 0;
}
