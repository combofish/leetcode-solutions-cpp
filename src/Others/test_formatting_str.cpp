/**
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
/**
 * @description: 分割字符串
 * @param {string} &str
 * @param {char} delim
 * @param {vector<string>} &elems
 * @return {*}
 */
vector<string> &split(const string &str, char delim, vector<string> &elems) {
  std::stringstream ss(str);
  string item;
  while (std::getline(ss, item, delim))
    elems.push_back(item);

  return elems;
}

int main(int argc, char **argv) {

  vector<string> vstr;
  string str = "Abstract—Existing salient object detection (SOD) methods\n\
mainly rely on CNN-based U-shaped structures with skip connec-\n\
tions to combine the global contexts and local spatial details that\n\
are crucial for locating salient objects and refining object details,\n\
respectively. Despite great successes, the ability of CNN in learn-\n";

  split(str, '\n', vstr);
  cout << str << endl;

  cout << "after: " << endl;

  std::stringstream ss;
  for (auto &s : vstr) {
    if (s.size() >= 1 && s.back() == '-') {
      ss << s;
    } else {
      ss << s << " ";
    }
  }
  ss << endl;

  cout << ss.str();

  return 0;
}
