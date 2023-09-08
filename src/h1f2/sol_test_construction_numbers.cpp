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

static int count = 0;

class Solution {

    // function start.
public:
    Solution(){
        ++count;
        cout<<"Constructor called."<<endl;
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    Solution b[3];
    Solution* p[4];


    cout<<"count == "<<count<<endl;
    
    // code end

    return 0;
}