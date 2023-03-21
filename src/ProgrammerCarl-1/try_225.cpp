/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.

    // function end.
};

class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        _q1.push(x);
    }

    int pop() {
        int size = _q1.size();
        size--;
        while(size--){
            _q2.push(_q1.front());
            _q1.pop();
        }

        int res = _q1.front();
        _q1.pop();
        _q1 = _q2;
        while(!_q2.empty()){
            _q2.pop();
        }

        return res;
    }

    int top() {
        return _q1.back();
    }

    bool empty() {
        return _q1.empty();
    }

private:
    queue<int> _q1, _q2;
};

int main() {

    auto solution = new Solution();

    // code start

    auto my_stack = new MyStack();
    my_stack->push(1);
    my_stack->push(2);
    IC(my_stack->top());
    IC(my_stack->pop());
    IC(my_stack->empty());
    delete my_stack;
    // code end

    delete solution;
    return 0;
}


