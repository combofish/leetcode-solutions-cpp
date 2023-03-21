/**
-- question: 最小栈
-- method:
 - []

--result:

-- analyse:
Time: O(1)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <memory>

class Solution {

    // function start.
public:
private:
    // function end.
};

class MinStack {
private:
    stack<pair<int, int>> record;

public:
    MinStack() {
    }

    void push(int val) {
        if(record.empty()){
            record.push({val, val});
        }else{
            record.push({val, std::min(record.top().second, val)});
        }
    }

    void pop() {
        record.pop();
    }

    int top() {
        return record.top().first;
    }

    int getMin() {
        return record.top().second;
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto minStack = std::make_shared<MinStack>();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    IC(minStack->getMin());
    minStack->pop();

    IC(minStack->top());
    IC(minStack->getMin());
    // code end

    return 0;
}
