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

    int a[4][2] = {{1,2},{3,4},{5,6},{7,8}};

    IC(a);
    cout<<a<<endl;
    IC(*(a[2] + 1));
    IC(*(*(a + 1) + 1));


    // IC(*(a+1));
    cout<<*(a+1)<<endl;

    cout<<**a<<endl;

    int *p = 0;

    bool ans = p == nullptr;

    cout<<ans<<endl;


    // code end

    return 0;
}