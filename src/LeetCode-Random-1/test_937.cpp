

#include "combofish_utils.hpp"
#include <cwctype>
#include <string>
vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                       "let2 own kit dig", "let3 art zero"};

vector<pair<string, string>> rec;

vector<string> num_logs;

int main() {
  for (const string &s : logs) {
    IC(s);

    auto i = s.find(' ');
    if (std::all_of(s.begin() + i + 1, s.end(), [](unsigned char c) {
          return (std::isdigit(c) || c == ' ');
        })) {
      num_logs.emplace_back(s);
    } else {
      rec.push_back(make_pair(s.substr(0, i), s.substr(i)));
    }
  }

  IC(num_logs);
  IC(rec);

  std::sort(rec.begin(), rec.end(),
            [](pair<string, string> &s1, pair<string, string> &s2) {
              if (s1.second == s2.second)
                return s1.first < s2.first;
              return s1.second < s2.second;
            });

  IC("after sort: ", rec);

  vector<string> res;
  for (auto &r : rec)
    res.emplace_back(r.first + r.second);

  res.insert(res.end(), num_logs.begin(), num_logs.end());

  IC(res);

  return 0;
}
