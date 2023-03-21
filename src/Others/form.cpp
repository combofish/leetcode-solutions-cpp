
class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int cnt = 0;
        int max_cnt = arr.size();ectories
        int idx_n = 0;

        for (int i = 0; i < max_cnt; i++) {
            if (arr[i] == 0)
                cnt += 2;
            else
                cnt++;

            if (cnt == max_cnt) {
                idx_n = i;
                break;
            }
        }

        max_cnt--;

        for (int i = idx_n; i >= 0; i--) {
            if (arr[i] != 0) {
                arr[max_cnt] = arr[i];
                max_cnt--;
            } else {
                arr[max_cnt--] = 0;
                arr[max_cnt--] = 0;
            }
        }
    }
};
