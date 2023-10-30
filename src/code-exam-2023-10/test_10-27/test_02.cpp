#include <bits/stdc++.h>
#include <icecream.hpp>

using namespace std;

class Solution {

    inline bool overMerge(const vector<int> &rect1, const vector<int> &rect2){
        auto w1 = rect1[2] - rect1[0];
        auto h1 = rect1[3] - rect1[1];

        auto w2 = rect2[2] - rect2[0];
        auto h2 = rect2[3] - rect2[1];

        auto W = std::abs(((rect1[2] + rect1[0]) >> 1) - ((rect2[2] + rect2[0]) >> 1));
        auto H = std::abs(((rect1[3] + rect1[1]) >> 1) - ((rect2[3] + rect2[1]) >> 1));

        return W < ((w1 + w2 ) >> 1) && H < ((h1 + h2) >> 1);

    }


  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param rects int整型vector<vector<>> 矩形集合
     * @return bool布尔型
     */
    bool MatrixMergeCheck(vector<vector<int> >& rects) {


        // 交集判断
        int n = rects.size();
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j<n; ++j){
                if(overMerge(rects[i], rects[j])) return false;
            }
        }


        // write code here

        int min_x = rects.front()[0];
        int min_y = rects.front()[1];
        int max_x = rects.front()[2];
        int max_y = rects.front()[3];

        int tot_area = 0;



        for (auto& rect : rects) {
            auto x1 = rect[0];
            auto y1 = rect[1];
            auto x2 = rect[2];
            auto y2 = rect[3];

            if(x1 <= min_x && y1 <= min_y){
                min_x = x1;
                min_y = y1;
            }

            if(x2 >= max_x && y2 >= max_y){
                max_x = x2;
                max_y = y2;
            }

            // min_x = std::min(min_x, x1);
            // min_y = std::min(min_y, y1);
            // max_x = std::max(max_x, x2);
            // max_y = std::max(max_y, y2);

            tot_area += (y2 - y1) * (x2 - x1);

        }

        return tot_area == ((max_y - min_y) * (max_x - min_x));




    }
};

int main(int argc, char const *argv[])
{
    /**
     * [[0,1,2,4],[0,4,4,5],[1,1,4,2],[2,2,4,4]]  false
     * 
     * [[0,1,2,4],[2,1,5,2],[0,4,5,5]] false
     * 
     * 
     * [[0,1,2,4],[0,4,4,5],[2,1,4,2],[2,2,4,4]] true
     * */    

    
    return 0;
}

