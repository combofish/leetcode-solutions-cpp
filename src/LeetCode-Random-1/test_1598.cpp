/**
 *
 */

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv){
  vector<string> logs = {"d1/","d2/","../","d21/","./"};
  int res = 0;

  for(auto& log: logs){
    cout<< log[0];
  }

  cout<<std::max(1,3);

  return 0;
}
