/*
 * @Author: your name
 * @Date: 2022-04-28 09:01:59
 * @LastEditTime: 2022-04-28 10:00:41
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /use_for_test/test_905 copy.cpp
 */
/**
 *
 */

#include "combofish_utils.hpp"

int main(int argc, char **argv)
{
  vector<int> nums = {0,1, 3};

  int i = 0;
  int n = nums.size();
  int k = n - 1;

  //int t = n%2 == 0? n/2 : (n+1)/2;
  while (i < n)
  {
    out(nums[i], "\nProcessing this n ");
    if (nums[i] % 2 == 0)
    {
      i++;
    }
    else
    {
      // nums[i] is odd number
      for (; k > i; k--)
      {
        if (nums[k] % 2 == 0)
        {
          // nums[k] is even number
          out(nums[k], "even number");
          int tmp = nums[k];
          nums[k] = nums[i];
          nums[i] = tmp;
          break;
        }
      }
      if (k <= i)
      {
        outln(k, "k");
        ++i;
      }

      out_vec(nums, "Afer on change");
    }
  }

  out_vec(nums, "nums");
  return 0;
}
