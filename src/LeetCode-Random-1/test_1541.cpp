/*
 * @Author: your name
 * @Date: 2022-04-27 20:05:12
 * @LastEditTime: 2022-04-27 21:16:03
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /use_for_test/test_417 copy.cpp
 */
/*
/**
 *
 */

#include "combofish_utils.hpp"

int minInsertions(const string &s)
{
  int count = 0;
  int left = 0;
  int n = s.size();
  int i = 0;
  while (i < n)
  {
    char c = s[i];
    if (c == '(')
    {
      left++;
      i++;
    }
    else
    {
      if (left > 0)
      {
        --left;
      }
      else
      {
        ++count;
      }

      if (i < n - 1 && s[i + 1] == ')')
      {
        i += 2;
      }
      else
      {
        ++i;
        ++count;
      }
    }

    cout <<"---"<< c << " with i: " << i << " ,count: " << count << endl;
  }

  count += left * 2;

  return count;
}

int main(int argc, char **argv)
{
  vector<string> vec = {"(()))", "())", "))())(", "((((((", ")))))))"};
  //vector<string> vec = {"(()))"};
  for (auto &s : vec)
  {
    int n = minInsertions(s);
    cout<<endl;
    cout << s << "   With: "
         << " Res: " << n << endl;
  }
  return 0;
}
