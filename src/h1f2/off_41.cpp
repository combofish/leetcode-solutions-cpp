/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class MedianFinder {
    std::priority_queue<int, vector<int>, std::less<int>> min_qu;
    std::priority_queue<int, vector<int>, std::greater<int>> max_qu;

    void out_priority_queue(std::priority_queue<int> qu, string s) {
        vector<int> tmp;
        while (!qu.empty()) {
            tmp.emplace_back(qu.top());
            qu.pop();
        }
        IC(s, tmp);
    }

    void out_priority_queue(std::priority_queue<int, vector<int>, std::greater<int>> qu, string s) {
        vector<int> tmp;
        while (!qu.empty()) {
            tmp.emplace_back(qu.top());
            qu.pop();
        }
        IC(s, tmp);
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (min_qu.empty() || num <= min_qu.top()) {
            min_qu.push(num);
            if (max_qu.size() + 1 < min_qu.size()) {
                max_qu.push(min_qu.top());
                min_qu.pop();
            }
        } else {
            max_qu.push(num);
            if (max_qu.size() > min_qu.size()) {
                min_qu.push(max_qu.top());
                max_qu.pop();
            }
        }

        out_priority_queue(min_qu, "min_qu");
        out_priority_queue(max_qu, "max_qu");
        cout << endl;
    }

    double findMedian() {
        if (min_qu.size() > max_qu.size()) return min_qu.size();
        return (min_qu.top() + max_qu.top()) / 2.0;
    }
};

int main() {

    auto solution = std::make_shared<MedianFinder>();

    // code start
    solution->addNum(1);
    solution->addNum(4);
    solution->addNum(7);
    solution->addNum(5);
    solution->addNum(3);

    IC(solution->findMedian());


    // code end

    return 0;
}