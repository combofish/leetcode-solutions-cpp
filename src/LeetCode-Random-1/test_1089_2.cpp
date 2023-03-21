/**
 *
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv) {
  vector<int> arr = {8, 4, 5, 0, 0, 0, 0, 7};
  int cnt = 0;
  int max_cnt = arr.size();
  int idx_n = 0;

  for (int i = 0; i < max_cnt; i++) {
    if (arr[i] == 0) {
      cnt += 2;
    } else {
      cnt++;
    }

    if (cnt >= max_cnt) {
      idx_n = i;
      break;
    }
  }

  cout << "idx_n: " << idx_n << endl;
  cnt--;

  for (int i = idx_n; i >= 0; i--) {
    if (arr[i] != 0) {
      arr[cnt] = arr[i];
      cnt--;
    } else {
      if (cnt == max_cnt) {
        cnt--;
        arr[cnt--] = 0;
      } else {
        arr[cnt--] = 0;
        arr[cnt--] = 0;
      }
    }
  }

  cout << "res : ";
  for (auto &a : arr) {
    cout << a << " ";
  }
  cout << endl;

  return 0;
}
