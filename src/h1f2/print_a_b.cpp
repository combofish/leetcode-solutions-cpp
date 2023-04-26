/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */
#include <sys/types.h>
#include <unistd.h>
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

    int n = 1e6;
    int i = n;
    int j = n;
    if (!fork()) {
        while (i > 0) {
            printf("A");
            --i;
        }
    }
    if (!fork()) {
        while (j) {
            printf("B");
            --j;
        }
    }


    // code end

    return 0;
}