/**
 *
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
  string sentence = "The quick brown fox jumped over the lazy dog";

  vector<string> vstr;
  std::stringstream ss(sentence);

  string item;
  while (std::getline(ss, item, ' '))
    vstr.push_back(item);

  int cnt = 1;
  vector<string> vstr_res;

  for (const string &s : vstr) {
    std::stringstream tmp_ss;
    char f = std::tolower(s.front());

    if (f != 'a' && f != 'e' && f != 'i' && f != 'o' && f != 'u')
      tmp_ss << s.substr(1) << s.front();
    else
      tmp_ss << s;

    tmp_ss << "ma";
    for (int i = 0; i < cnt; i++)
      tmp_ss << 'a';

    ++cnt;
    vstr_res.push_back(tmp_ss.str());
  }

  stringstream res;
  res << vstr_res.front();

  if (vstr_res.size() > 1) {
    for (auto it = vstr_res.begin() + 1; it != vstr_res.end(); it++) {
      res << ' ' << *it;
    }
  }

  cout << res.str() << endl;

  const string res_true =
      "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa "
      "hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa";
  cout << "Res: " << (res.str() == res_true) << endl;

  return 0;
}
