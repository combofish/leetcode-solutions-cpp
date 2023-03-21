/*
 * @Author: your name
 * @Date: 2022-04-25 08:53:57
 * @LastEditTime: 2022-04-27 13:43:17
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /use_for_test/test_2529.cpp
 */
/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <stack>
using std::stack;

class MyQueue {
private:
  stack<int> inSta, outSta;
  void in2out() {
    while (!inSta.empty()) {
      outSta.push(inSta.top());
      inSta.pop();
    }
  }

public:        /** Initialize your data structure here. */
  MyQueue() {} /** Push element x to the back of queue. */
  void push(int x) { inSta.push(x); }
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (outSta.empty())
      in2out();

    int n = outSta.top();
    outSta.pop();
    return n;
  }
  /** Get the front element. */
  int peek() {
    if (outSta.empty())
      in2out();
    return outSta.top();
  }
  /** Returns whether the queue is empty. */
  bool empty() { return inSta.empty() && outSta.empty(); }
};

int main(int argc, char **argv) {

  // our MyQueue object will be instantiated and called as such:
  MyQueue *obj = new MyQueue();

  obj->push(1);
  obj->push(2);
  int param_2 = obj->peek();
  int param_3 = obj->pop();
  int param_4 = obj->pop();

  bool param_5 = obj->empty();

  outln(param_2, "param_2");
  outln(param_3, "param_3");
  outln(param_4, "param_4");
  outln(param_5, "param_5");
  return 0;
}
