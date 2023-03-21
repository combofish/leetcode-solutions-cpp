/**
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.4 MB, 在所有 C++ 提交中击败了60.09%的用户
通过测试用例：14 / 14
 */

#include "combofish_utils.hpp"
#include <string>
#include <vector>

int minMutation(string start, string end, vector<string> &bank) {
  unordered_set<string> cnt;
  unordered_set<string> visited;
  const char gene[4] = {'A', 'C', 'G', 'T'};

  for (const string &b : bank)
    cnt.emplace(b);

  if (start == end)
    return 0;
  if (!cnt.count(end))
    return -1;

  queue<string> qu;
  qu.emplace(start);
  visited.emplace(start);

  IC(start);

  int step = 1;
  while (!qu.empty()) {
    int sz = qu.size();
    for (int i = 0; i < sz; i++) {
      string curr = qu.front();
      qu.pop();
      for (int j = 0; j < 8; j++) {
        for (int k = 0; k < 4; ++k) {
          if (gene[k] != curr[j]) {
            string next = curr;
            next[j] = gene[k];
            if (!visited.count(next) && cnt.count(next)) {
              IC(next);

              if (next == end)
                return step;

              qu.emplace(next);
              visited.emplace(next);
            }
          }
        }
      }
    }
    step++;
  }

  return -1;
}

int main() {
  // code start
  string start = "AACCGGTT", end = "AAACGGTA";
  vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

  IC(start, end);
  IC(bank);
  IC(minMutation(start, end, bank));

  return 0;
}
