

#include "combofish_utils.hpp"
#include <cstdio>
int findTheWinner(int n, int k) {
  queue<int> qu;
  for (int i = 1; i <= n; i++)
    qu.emplace(i);

  // IC(qu);
  out_qu(qu);
  while (qu.size() > 1) {

    for (int i = 1; i < k; ++i) {
      qu.emplace(qu.front());
      qu.pop();
    }
    // IC(qu);
    qu.pop();
    out_qu(qu);
    // IC(qu);
  }
  return qu.front();
}

int main() {

  vec_t test_data_1 = {5, 2, 3};
  vec_t test_data_2 = {6, 5, 1};

  IC(test_data_1[2] == findTheWinner(IC(test_data_1[0]), IC(test_data_1[1])));

  return 0;
}
