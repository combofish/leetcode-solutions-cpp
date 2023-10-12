#include <iostream>
#include <string>
#include <vector>
#include <strstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }


    string str;
    // cin >> str;
    str = "(1,2,3)";

    vector<int> nums;
    //vector<int> nums;

    str = str.substr(1);
    str.pop_back();

    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, ',')) {
        nums.emplace_back(stoi(tmp));
    }

    string ans = "true";
    std::sort(nums.begin(), nums.end());

    int a = nums[0];
    int b = nums[1];
    int c = nums.back();

    if (a == b || a == c || b == c) {
        ans = "false";
    }






    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")