/**

 */

#include "combofish_utils.hpp"

int numPairsDivisibleBy60(vector<int> &time) {
  int n = time.size();
  if (n == 1)
    return 0;

  int ret = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((time[i] + time[j]) % 60 == 0)
        ret++;
    }
  }

  return ret;
}

int main() {
  // code start
  //  vec_t time = {30, 20, 150, 100, 40};
  vec_t time = {60, 60, 60};
  IC(time, numPairsDivisibleBy60(time));

  return 0;
}
