/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include <deque>
#include "../combofish_utils.hpp"
using std::deque;

class MaxQueue {
    deque<int> dq;
    queue<int> qu;

public:
    MaxQueue() {

    }

    int max_value() {
        if(dq.empty()){
            return -1;
        }
        return dq.front();
    }

    void push_back(int value) {
        while(!dq.empty() && dq.back() < value){
            dq.pop_back();
        }
        qu.push(value);
        dq.push_back(value);
    }

    int pop_front() {
        if(qu.empty()) return -1;

        int ans = qu.front();
        if(ans == dq.front()){
            dq.pop_front();
        }

        qu.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    // code end

    return 0;
}