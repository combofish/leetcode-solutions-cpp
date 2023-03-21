/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
struct Point {
    int x;
    int y;
    Point(int xx, int yy) : x(xx), y(yy) {}
};
class Solution {
public:
    // function start.
    double getPolygonArea(vector<Point> const &points) {
        const int sizep = points.size();
        if (sizep < 3) return 0.0;

        double area = points.back().x * points[0].y - points[0].x * points.back().y;
        for (int i = 1, v = 0; i < sizep; i++, v++) {
            area += (points[v].x * points[i].y);
            area -= (points[i].x * points[v].y);
        }

        return fabs(0.5 * area);
    }
    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<Point> ps = {{1, 1}, {2, 2}, {1, 3}, {0, 2}};
    IC(ps);
    IC(solution->getPolygonArea(ps));
    // code end

    delete solution;
    return 0;
}
