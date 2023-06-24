/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include <set>
#include "../combofish_utils.hpp"

class Solution {

    // function start.
public:


private:
    // function end.
};

class KthLargest {
    int m_k;
    vector<int> rec;
public:
    KthLargest(int k, vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        IC(nums);
        rec = nums;
        m_k = k;
    }

    int add(int val) {
        int n = rec.size();
        rec.resize(n + 1);
        int rk = n - 1;
        while (rk >= 0 && rec[rk] > val) {
            rec[rk + 1] = rec[rk];
            --rk;
        }
        rec[rk + 1] = val;


        IC(rec);
        cout << endl;
        return rec[rec.size() - m_k];

    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    vector<int> nums = {4, 5, 8, 2};
    int k = 2;
    IC(nums, k);
    auto obj = new KthLargest(k, nums);

    IC(obj->add(3), 4);
    IC(obj->add(5), 5);
    IC(obj->add(10), 5);
    IC(obj->add(9), 8);
    IC(obj->add(4), 8);


    cout << endl;
    cout << endl;
    k = 1;
    nums = {};
    IC(nums, k);
    auto obj2 = new KthLargest(k, nums);


    IC(obj2->add(-3), -3);
    IC(obj2->add(-2), -2);
    IC(obj2->add(-4), -2);
    IC(obj2->add(0), 0);
    IC(obj2->add(4), 4);

    delete obj;
    delete obj2;


    auto s = std::set<int, std::greater<int>>();

    s.insert(2);
    s.insert(1);

    for(auto &item: s){
        IC(item);
    }


    nums = {1,2,2,2,2,2};
    IC(nums, 2);
    IC();

    // cout<<nums<<endl;

    // code end

    return 0;
}