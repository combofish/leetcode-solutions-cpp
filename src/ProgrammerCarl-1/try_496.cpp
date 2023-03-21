/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {

    // function start.
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> record(nums1.size(), -1);
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++)
            umap[nums1[i]] = i;

        IC(umap);

        stack<int> sta;
        for (int i = 0; i < nums2.size(); i++) {
            while (!sta.empty() && nums2[i] > nums2[sta.top()]) {
//                IC('i');

                if (umap.find(nums2[sta.top()]) != umap.end()) {
                    int index = umap[nums2[sta.top()]];
                    record[index] = nums2[i];
//                    IC(index);
                }
                sta.pop();
            }

            sta.push(i);
//            out_sta(sta);
//            IC(record);
//            IC();
        }

        return record;


    }

private:

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2}, rel = {-1, 3, -1};

    IC(nums1, nums2, rel);
    IC(solution->nextGreaterElement(nums1, nums2));

    // code end

    delete solution;
    return 0;
}


