/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"
#include <ctime>

class Solution {

    // function start.
public:

    void printN(int n) {
        while (n) {
            cout << n << endl;
            n--;
        }
    }

    void printN2(int n) {
        if (n) {
            printN2(n - 1);
            cout << n << endl;
        }
    }

private:
    // function end.
};

void costTime(long start, long end) {
    auto duration = (end - start);
    IC(duration);
}

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

//    int n = 1000000;
//    IC(n);
//
//    // solution->printN(n); // can work
//    solution->printN2(n); // AddressSanitizer:DEADLYSIGNAL


    int n = 1e5;

    auto start = clock();
    solution->printN(n);
    auto end = clock();
    solution->printN2(n);
    auto end2 = clock();


    costTime(start, end);
    costTime(end, end2);

    // code end

    return 0;
}