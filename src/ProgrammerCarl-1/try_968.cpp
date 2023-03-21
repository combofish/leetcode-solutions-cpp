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
private:
    int result;

    int traversal(TreeNode *node) {
        /**
         * 0: not cover
         * 1: has camera
         * 2: cover
         */

        // empty node, cover
        if (!node) return 2;

        int left = traversal(node->left);
        int right = traversal(node->right);


        // 情况1
        // 左右节点都有覆盖
        if (left == 2 and right == 2) return 0;

        // 情况2
        // left == 0 && right == 0 左右节点无覆盖
        // left == 1 && right == 0 左节点有摄像头，右节点无覆盖
        // left == 0 && right == 1 左节点有无覆盖，右节点摄像头
        // left == 0 && right == 2 左节点无覆盖，右节点覆盖
        // left == 2 && right == 0 左节点覆盖，右节点无覆盖
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }

        // 情况3
        // left == 1 && right == 2 左节点有摄像头，右节点有覆盖
        // left == 2 && right == 1 左节点有覆盖，右节点有摄像头
        // left == 1 && right == 1 左右节点都有摄像头
        // 其他情况前段代码均已覆盖
        if (left == 1 || right == 1) return 2;

        return -1;
    }

    // function start.
public:
    int minCameraCover(TreeNode *root) {
        result = 0;
        if (traversal(root) == 0)
            result++;

        return result;
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start

    auto t1 = new TreeNode(1);
    auto t2 = new TreeNode(2);
    auto t3 = new TreeNode(3);
    t1->right = t2;
    t1->left = t3;

    int rel = 1;
    IC(rel);
    IC(solution->minCameraCover(t1));

    deleteTreeNode(t1);
    // code end

    delete solution;
    return 0;
}


