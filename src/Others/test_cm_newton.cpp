/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
//牛顿迭代法

#define Length 100
using namespace std;

class NewtonIterationMethod {
public:
    void input();

    double function(double x);

    double derivative(double x);

    double newtonmethod(double Xo);

    void analyse();

    void display();

private:
    double Xo;
    int n;
    double root;
} newton;

void NewtonIterationMethod::input() {
    cout << "**************************第一题**************************\n"
         << endl;
    cout << "  请输入初始值:Xo=";
    cin >> this->Xo;
    cout << "  请输入迭代次数:n=";
    cin >> this->n;
}

double NewtonIterationMethod::function(double x) { return (pow(x, 3) - x - 1); }

double NewtonIterationMethod::derivative(double x) {
    return (3 * pow(x, 2) - 1);
}

double NewtonIterationMethod::newtonmethod(double Xo) {
    double x[Length];
    x[0] = Xo;
    for (int i = 0; i < n; i++) {
        x[i + 1] = x[i] - function(x[i]) / derivative(x[i]);
        root = x[i + 1];
    }
    return root;
}

void NewtonIterationMethod::analyse() {
    cout << "\n**************************第二题**************************\n"
         << endl;
    cout << "  迭代" << n << "次求得方程X^3-x-1=0在x=" << 0
         << "附近的近似根X=" << newtonmethod(0) << endl;
    cout << "\n  原因分析:"
         << "在Xo=" << 0 << "处迭代,在精度相同的前提下,迭代次数超过给定\n"
         << "  的最大值" << n
         << "，由此可见牛顿迭代法在初始值接近近似根处的迭代\n"
         << "  速度要比远离近似根的迭代速度快很多，而且近似值的函数近似\n"
         << "  值要精确很多\n"
         << endl;
}

void NewtonIterationMethod::display() {
    cout << "  迭代" << n << "次求得方程X^3-x-1=0在x=" << Xo
         << "附近的近似根X=" << newtonmethod(Xo) << endl;
}

class Solution {
public:
    // function start.

    // function end.
};

int main() {

    Solution *solution = new Solution();

    // code start
    newton.input();
    newton.display();
    newton.analyse();
    system("pause");

    return 0;
}
