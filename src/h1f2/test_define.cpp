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

#define combineAB(A,B) A##B
#define printfA(A) printf("%s", #A);


class Solution {

    // function start.
public:


private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    string abc = "abcd";
    printfA(combineAB(abc, __LINE__));


    cout<<endl;
    cout<<__LINE__<<endl;

    // code end

    return 0;
}