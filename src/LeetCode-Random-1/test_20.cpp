/**
 *
 */

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::vector;

int main(int argc, char **argv) {
  string s = "()[]}";

  unordered_map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
  bool res = true;
  int n = s.size();

  if (n % 2 != 0)
    res = false;

  stack<char> sta;
  for (const char &c : s) {
    if (sta.empty()) {
      if (c == '(' || c == '[' || c == '{')
        sta.push(c);
      else
        res = false;
    } else {
      char cur = sta.top();
      if (pairs[cur] == c) {
        sta.pop();
      } else {
        if (c == '(' || c == '[' || c == '{')
          sta.push(c);
        else
          res = false;
      }
    }
  }

  if (sta.size() == 0)
    res = true;

  stack<char> sg = sta;
  while (!sg.empty()) {
    cout << '\t' << sg.top();
    sg.pop();
  }
  cout << endl;

  cout << "Res: " << res << endl;

  return 0;
}
