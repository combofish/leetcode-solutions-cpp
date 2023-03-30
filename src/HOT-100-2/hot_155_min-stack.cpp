/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O(1)
Space: O(n)
 */

#include "../combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:


private:

    // function end.
};

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) st.emplace(val, val);
        else st.emplace(val, std::min(st.top().second, val));
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    vector<string> ops = {"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    string result = "[[],[-2],[0],[-3],[],[],[],[]]";
    IC(ops, result);


    auto minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    IC(minStack->getMin());  // --> 返回 -3->
    minStack->pop();
    IC(minStack->top());     // --> 返回 0->
    IC(minStack->getMin());

    delete minStack;

    // code end

    return 0;
}


