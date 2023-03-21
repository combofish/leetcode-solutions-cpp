/**
-- method: 差分数组

--result:
执行用时：84 ms, 在所有 C++ 提交中击败了93.72%的用户
内存消耗：25.7 MB, 在所有 C++ 提交中击败了67.21%的用户
通过测试用例：98 / 98

-- analyse:
Time: O(n^2)
Space: O(n)

 */

#include "combofish_utils.hpp"
#include <map>
#include <utility>

class Solution {
public:
  // function start.

  // function end.
};

class MyCalendarThree {
private:
  std::map<int, int> cnt;

public:
  MyCalendarThree() {}
  int book(int start, int end) {
    int ans = 0;
    int maxBook = 0;
    cnt[start]++;
    cnt[end]--;
    for (auto &[_, freq] : cnt) {
      maxBook += freq;
      ans = std::max(maxBook, ans);
    }
    return ans;
  }
};

int main() {

  Solution *solution = new Solution();

  // code start
  mat_t books = {{10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}};
  IC(books);

  auto myCcalendar = new MyCalendarThree();
  for (auto book : books) {
    IC(book, myCcalendar->book(book[0], book[1]));
  }

  mat_t books2 = {{24, 40}, {43, 50}, {27, 43}, {5, 21},  {30, 40},
                  {14, 29}, {3, 19},  {3, 14},  {25, 39}, {6, 19}};

  IC();
  auto myCcalendar2 = new MyCalendarThree();
  vec_t ret2 = {1, 1, 2, 2, 3, 3, 3, 3, 4, 4};

  bool ret_is_right = true;
  for (int i = 0; i < books2.size(); i++) {
    auto book = books2[i];
    auto ret = myCcalendar2->book(book[0], book[1]);
    ret_is_right &= ret == ret2[i];
    IC(book, ret, ret2[i]);
  }
  IC(ret_is_right);
  IC(ret2);

  return 0;
}
