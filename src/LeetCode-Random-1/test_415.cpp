/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>

int main(int argc, char **argv) {
  string num1 = "456";
  string num2 = "77";
  string res;

  unordered_map<char, int> umap = {{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3},
                                   {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7},
                                   {'8', 8}, {'9', 9}};
  int over = 0;

  while (!num1.empty() || !num2.empty() || over > 0) {
    char n1 = num1.size() > 0 ? num1.back() : '0';
    char n2 = num2.size() > 0 ? num2.back() : '0';
    int l = 0;
    outln(l,"-------");

    out(umap[n1],"un1");
    out(umap[n2],"un2");
    outln(over,"over");
    
    
    int n = umap[n1] + umap[n2] + over;

    

    outln(n, "n");

    if (n > 9) {
      over = 1;
      n = n % 10;
    } else {
      over = 0;
    }

    out(n, "n");
    outln(over, "over");

    res.push_back('0' + n);
    // over = '0' + n % 10;

    if (num1.size() > 0)
      num1.pop_back();

    if (num2.size() > 0)
      num2.pop_back();

    outln(n, "n");

    out(num1, "nums1");
    outln(num2, "nums2");

    //  break;
  }

  std::reverse(res.begin(), res.end());

  outln(num1, "nums1");
  outln(num2, "nums2");
  outln(res);

  return 0;
}
