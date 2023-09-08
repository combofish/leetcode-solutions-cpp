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
#include <cmath>
#include <iostream>

using namespace std;

class Solution {

    // function start.
public:
    void cal(){

        double r;
        cin>>r;

        if(r >= 0){
            auto circumference = 2 * M_PI * r;
            auto area = std::pow(r, 2) * M_PI;

                   cout << "该圆的周长为：" << circumference << ", 面积为：" << area << endl;
        } else {    //如果r小于0
            cout << "输入错误，半径不能为负值。" << endl;
        }

    }
private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    solution->cal();
    // code end

    return 0;
}