/*
 * @Author: your name
 * @Date: 2022-04-24 09:14:07
 * @LastEditTime: 2022-04-27 14:04:57
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /use_for_test/test_868_3.cpp
 */
/**
 *
 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <functional>
#include <type_traits>

// void BinaryRecursion(int n, vector<int> &res) {

//   int a;
//   a = n % 2;
//   n = n >> 1;
//   if (n != 0)
//     BinaryRecursion(n, res);
//   res.emplace_back(a);
// }

int main(int argc, char **argv)
{
  int n = 22;
  vector<int> res;

  int result = 0;
  int cur_idx = -1;
  for (int i = 0; n != 0; i++)
  {
    int a = n % 2;

    if (a == 1)
    {
      if (cur_idx != -1)
        result = std::max(result, i - cur_idx);

      cur_idx = i;
    }
    out(i, "i");
    outln(a);

    n = n >> 1;
  }

  outln(result, "result");

  out_vec(res);

  return 0;
}
