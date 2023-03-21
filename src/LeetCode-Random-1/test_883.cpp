/**
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "./combofish_utils.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char **argv) {
  vector<vector<int>> grid = {{1,2}, { 3,4}};

  int h = grid.size(), w = 0;
  for(auto &line: grid)
    w = std::max(w, (int)line.size());

  out(h,"h"); outln(w,"w");

  int bottom = 0;
  for(auto &line: grid)
    bottom += line.size();

  outln(bottom, "bottom");

  int right_area = 0;
  for(auto &line : grid)
    right_area += *std::max_element(line.begin(), line.end());

  outln(right_area, "right_area");

  int left_area = 0;
  int count_zero = 0;
  for(int i = 0 ; i< w; ++i){
    int left_max = 0;
    for(int j = 0; j< w; ++j){
      left_max = std::max(grid[j][i], left_max);

      if(grid[i][j] == 0) count_zero++;
    }
    left_area += left_max;
  }

  outln(left_area, "left_area");

  int res = left_area + right_area + bottom - count_zero;
  outln(res, "res");


  return 0;
}
