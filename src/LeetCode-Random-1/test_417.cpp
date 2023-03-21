/*
 * @Author: your name
 * @Date: 2022-04-27 18:51:27
 * @LastEditTime: 2022-04-27 19:40:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /use_for_test/test_2529 copy.cpp
 */
/**
 *
 */

#include "combofish_utils.hpp"
const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  vector<vector<int>>  heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

void dfs(int i, int j, vector<vector<bool>> &ocean)
{
  int n = ocean.size();
  int m = ocean.front().size();

  if(ocean[i][j])
    return;

  ocean[i][j] = true;
  for(int k = 0; k<4; ++k){
    int new_i = i + dirs[k][0];
    int new_j = j + dirs[k][1];

    if(new_i >= 0 && new_i < m && new_j >=0 && new_j <n && (heights[i][j] <= heights[new_i][new_j])){
      dfs(new_i,new_j, ocean);
    }
  }
  
}

int main(int argc, char **argv)
{

  vector<vector<int>> res;

  int m = heights.size();
  int n = heights.front().size();

  vector<vector<bool>> pacific_ocean(m, vector<bool>(n, false));
  vector<vector<bool>> atlantic_ocean(m, vector<bool>(n, false));

  for (int i = 0; i < m; i++)
    dfs(i, 0, pacific_ocean);

  for (int j = 0; j < n; ++j)
    dfs(0, j, pacific_ocean);

  for (int i = 0; i < m; i++)
    dfs(i, n-1, atlantic_ocean);

  for (int j = 0; j < n; ++j)
    dfs(m-1, j, atlantic_ocean);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(pacific_ocean[i][j] && atlantic_ocean[i][j]){
        vector<int> cell;
        cell.emplace_back(i);
        cell.emplace_back(j);
        res.emplace_back(cell);
      }
    }
  }

  for(auto &c: res){

    cout<< c[0] << ","<<c[1]<<endl;
  }
  return 0;
}
