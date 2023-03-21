/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"

class Solution {
public:
  // function start.

  // function end.
};

int main() {

  Solution *solution = new Solution();

  // code start

  for (int i = 640; i >= 1; i--) {
    //    IC(40000 / i);
    if ((40000 % i) == 0) {
      IC(i);
    }
  }
  return 0;
}
