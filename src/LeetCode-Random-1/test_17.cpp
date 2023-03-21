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
void backtrack(vector<string> &combinations,
               const unordered_map<char, string> &phoneMap,
               const string &digits, int idx, string &combination) {

  if (idx == digits.size()) {
    combinations.push_back(combination);
  } else {
    const string &curstring = phoneMap.at(digits[idx]);
    for (const char &c : curstring) {
      combination.push_back(c);
      backtrack(combinations, phoneMap, digits, idx + 1, combination);
      combination.pop_back();
    }
  }
}

int main(int argc, char **argv) {
  string digits = "23";
  vector<string> res;
  unordered_map<char, string> phoneMap = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  string combination;
  backtrack(res, phoneMap, digits, 0, combination);

  for (auto &s : res) {
    cout << "Res: " << s << endl;
  }
  // if(digits.empty()) return res;

  return 0;
}
