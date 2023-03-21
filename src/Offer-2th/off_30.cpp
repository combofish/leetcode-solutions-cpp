/**
-- question: 包含min函数的栈
-- method:
 - [ ] 辅助栈

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <algorithm>
#include <climits>

class Solution {

    // function start.
public:
private:
    // function end.
};

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {
        minSt.push(INT_MAX);
    }
    void push(int x) {
        st.push(x);
        minSt.push(std::min(minSt.top(), x));
    }
    int min() {
        return minSt.top();
    }
    int top() {
        return st.top();
    }
    void pop() {
        st.pop();
        minSt.pop();
    }
};

queue<int> qu;


int main() {
    auto solution = std::make_shared<Solution>();

    // code start
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    auto a = minStack->min();// --> 返回 -3.
    minStack->pop();
    auto b = minStack->top();//     --> 返回 0.
    auto c = minStack->min();//   --> 返回 -2.

    IC(a, b, c);

    delete minStack;

    // code end

    return 0;
}
