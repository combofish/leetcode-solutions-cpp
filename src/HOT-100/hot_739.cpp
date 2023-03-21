/*
 * @Author: combofish combofish@139.com
 * @Date: 2022-12-02 21:39:13
 * @LastEditors: combofish combofish@139.com
 * @LastEditTime: 2022-12-03 22:53:27
 * @FilePath: /Leetcode-Solution-Cpp/src/HOT-100/hot_739.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
-- question: 每日温度
-- method:
 - [] 单调栈

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> st;
        vector<int> record(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();

                record[idx] = i - idx;
            }

            st.push(i);
        }
        return record;
    }

    vector<int> dailyTemperatures_err(vector<int> &temperatures) {
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();

                temperatures[idx] = i - idx;
            }

            st.push(i);
        }

        outStack(st);
        int n = temperatures.size();
        while (!st.empty()) {
            st.pop();
            temperatures[--n] = 0;
        }
        return temperatures;
    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> temperatures = {55, 38, 53, 81, 61, 93, 97, 32, 43, 78};
    vector<int> rel = {3, 1, 1, 2, 1, 1, 0, 1, 1, 0};

    IC(temperatures, rel);

    IC(solution->dailyTemperatures(temperatures));
    IC(solution->dailyTemperatures_err(temperatures));
    // code end

    return 0;
}


