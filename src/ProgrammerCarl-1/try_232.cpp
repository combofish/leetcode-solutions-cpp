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

class MyQueue {
public:
    MyQueue() {}

    void push(int x) {
        _in_sta.push(x);
    }

    int pop() {
        if(_out_sta.empty()){
            while(!_in_sta.empty()){
                _out_sta.push(_in_sta.top());
                _in_sta.pop();
            }
        }
        int res = _out_sta.top();
        _out_sta.pop();
        return res;
    }

    int peek() {
        int res = this->pop();
        _out_sta.push(res);
        return res;
    }

    bool empty() {
        return _out_sta.empty() && _in_sta.empty();
    }
private:
    stack<int> _in_sta;
    stack<int> _out_sta;
};

int main() {

    auto solution = new Solution();

    // code start
    auto obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    int p2 = obj->pop();
    int p3 = obj->peek();
    bool p4 = obj->empty();

    IC(obj, p2, p3, p4);

    delete obj;
    // code end

    delete solution;
    return 0;
}


