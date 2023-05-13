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

private:
    // function end.
};

void out_pqu(std::priority_queue<int> pqu_cpy){
    vector<int> tmp;
    while(!pqu_cpy.empty()){
        tmp.push_back(pqu_cpy.top());
        pqu_cpy.pop();
    }
    IC(tmp);
}
int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    std::priority_queue<int> pqu;


    pqu.push(2);
    pqu.push(2);
    pqu.push(3);
    pqu.push(1);

    out_pqu(pqu);



    // code end

    return 0;
}