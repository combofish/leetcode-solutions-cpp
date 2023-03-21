/**
 * OVer time
 */

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

int main(int argc, char **argv) {
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};

  int n = s.size();
  int j = n / 2;

  for (int i = 0; i < j; i++) {
    int tmp = s[i];
    s[i] = s[n - 1 - i];
    s[n - 1 - i] = tmp;
  }
  
  cout << "j = " << j << " ,n = " << n << endl;

  for (auto &ss : s)
    cout << ss << endl;

  return 0;
}
