#include <bits/stdc++.h>
#include <icecream.hpp>
#include <queue>

using namespace std;

void out_pqu_less(priority_queue<int, vector<int>> pqu) {
    vector<int> pqu_left;
    while (!pqu.empty()) {
        pqu_left.emplace_back(pqu.top());
        pqu.pop();
    }
    std::reverse(pqu_left.begin(), pqu_left.end());
    IC(pqu_left);
}

void out_pqu_greater(priority_queue<int, vector<int>, greater<int>> pqu) {
    vector<int> pqu_right;
    while (!pqu.empty()) {
        pqu_right.emplace_back(pqu.top());
        pqu.pop();
    }
    std::reverse(pqu_right.begin(), pqu_right.end());
    IC(pqu_right);
}

class MedianFinder {
    priority_queue<int, vector<int>> pqu_left;
    priority_queue<int, vector<int>, std::greater<int>> pqu_right;

public:
    MedianFinder() {
        // bigHeap.clear();
        // smallHeap.clear();
    }

    void addNum(int num) {
        if (pqu_left.empty()) {
            pqu_left.emplace(num);
            return;
        }

        int over;
        if (pqu_left.size() > pqu_right.size()) {
            over = pqu_left.top();
            pqu_left.pop();
        } else if (pqu_left.size() < pqu_right.size()) {
            over = pqu_right.top();
            pqu_right.pop();
        } else {
            if (num <= pqu_left.top()) pqu_left.emplace(num);
            else
                pqu_right.emplace(num);

            return;
        }

        if (over <= num) {
            pqu_right.emplace(num);
            pqu_left.emplace(over);
        } else {
            pqu_left.emplace(num);
            pqu_right.emplace(over);
        }

        out_pqu_less(pqu_left);
        out_pqu_greater(pqu_right);
    }

    double findMedian() {
        if (pqu_left.size() == pqu_right.size())
            return (pqu_left.top() + pqu_right.top()) / 2.;
        else if (pqu_right.size() > pqu_left.size())
            return pqu_right.top();
        else
            return pqu_left.top();
    }
};


int main(int argc, char const *argv[]) {

    MedianFinder medianFinder;

    medianFinder.addNum(2);
    IC(medianFinder.findMedian());

    medianFinder.addNum(3);
    IC(medianFinder.findMedian());


    return 0;
}
