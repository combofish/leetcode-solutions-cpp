#include <iostream>
#include <vector>
#include <stack>

#include <icecream.hpp>

using namespace std;

void expand(const vector<long long> &points, vector<int> &kinds, int idx) {
    // idx is people.
    int ls = idx, rs = idx;
    while (ls >= 0 && kinds[ls] == 0) {
        ls--;
    }

    while (rs < points.size() && kinds[rs] == 0) {
        rs++;
    }

    if (ls == idx || ls == -1 || kinds[ls] != 1) {
        kinds[rs]++;
        return;
    }

    if (rs == idx || rs == points.size() || kinds[rs] != 1) {
        kinds[ls]++;
        return;
    }

    long long left_gap = points[idx] - points[ls];
    long long right_gap = points[rs] - points[idx];

    if(right_gap > left_gap){
        kinds[rs]++;
    }else{
        kinds[ls]++;
    }

//    if (idx - ls < rs - idx) {
//        kinds[ls]++;
//    } else if (idx - ls > rs - idx) {
//        kinds[rs]++;
//    } else {
//        kinds[ls]++;
//    }

}

int main() {
    int n, m;

    // cin>>n>>m;

    n = 2;
    m = 3;

    int tot = n + m;
    vector<long long> points(tot);
    vector<int> kinds(tot);
//
//    for (int i = 0; i < tot; i++) cin >> points[i];
//    for (int i = 0; i < tot; i++) cin >> kinds[i];

    points = {1, 2, 3, 4, 5};
    kinds = {0, 0, 1, 0, 1};

    for (int i = 0; i < tot; i++) {
        if (!kinds[i]) {
            // people
            expand(points, kinds, i);
        }
    }

    IC(kinds);

    for (int i = 0; i < tot; i++) {
        if (kinds[i]) {
            cout << kinds[i] - 1 << " ";
        }
    }
    cout << endl;

    return 0;
}


/**
    long long prev = -1;
    long long left_left = 0;

    for (int i = 0; i < tot; i++) {
        if (kinds[i]) {
            if (prev < 1) {
                kinds[i] += left_left;
            } else {
                prev = points[i];
            }
        } else {
            // curr is person;
            if (prev < 1) {
                // left = null;
                left_left++;
            } else {


            }
        }

    }
*/

//    vector<int> stores(m);
//    vector<int> stores_rec(m, 0);
//    vector<int> persons(n);
//
//    int sk = 0;
//    int pk = 0;
//    for (int i = 0; i < tot; i++) {
//        if (kinds[i]) {
//            //  store
//            stores[sk++] = points[i];
//        } else {
//            persons[pk++] = points[i];
//        }
//    }
//
//    IC(persons, stores);