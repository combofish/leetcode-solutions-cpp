/*
 * @Author: larry combofish@163.com
 * @Date: 2023-07-11 17:49:51
 * @LastEditors: larry combofish@163.com
 * @LastEditTime: 2023-07-28 19:32:14
 * @FilePath: /leetcode-solutions-cpp/src/h1f2/sol_38.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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

class Solution {

    // function start.
public:
    string countAndSay(int n) {

        string str = "1";

        while(--n>0){
            string tmp = "";

            int ns = str.size();
            int i = 0;
            while(i < ns){
                int cnt = 1;
                while(i + 1 < ns && str[i+1] == str[i]){
                    ++i;
                    ++cnt;
                }
                // cout<<cnt<<endl;

                tmp += std::to_string(cnt);
                tmp += str[i];
                // tmp += (str[i] + '0');
                ++i;
            }

            str = tmp;
            IC(str);
        }


        return str;


    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    int n = 5;
    IC(n);
    IC(solution->countAndSay(n));
    // code end

    return 0;
}