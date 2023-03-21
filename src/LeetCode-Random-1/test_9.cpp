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
  int x = 121;
  string digit = std::to_string(x);

  int n = digit.size();
  bool res = true;
  for (int i = 0; i < n / 2; i++)
    if (digit[i] != digit[n - 1 - i])
      res = false;

  cout << "Res: " << res << endl;

  return 0;
}
