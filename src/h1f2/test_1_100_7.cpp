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

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    auto count = 0;

    for(int i = 1; i< 101; ++i){

        if((i * 2 - 1) % 7 == 0) ++count;
    }

    cout<<count<<endl;

    // code end

    return 0;
}