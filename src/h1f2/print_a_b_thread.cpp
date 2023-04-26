/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */
#include <thread>
#include <mutex>
#include <condition_variable>
#include "../combofish_utils.hpp"

std::mutex mtx;
std::condition_variable cond;

int n = 20;

class Solution {

    // function start.
public:

    void print_char_a(char a) {
        while (n-- > 0) {
            std::lock_guard<std::mutex> lock(mtx);
            cout << n << a << endl;

            cond.notify_one();
        }
        return;
    }

    void print_char_b(char a) {
        while (n-- > 0) {
            std::unique_lock<std::mutex> lock(mtx);
            cout<<n<<a<<endl;
            cond.wait(lock);
        }
        return;
    }

private:
    // function end.
};

int main() { // err for using.

    auto solution = std::make_shared<Solution>();

    // code start
    std::thread t1(&Solution::print_char_a, solution, 'A');
//    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread t2(&Solution::print_char_b, solution, 'B');

    t1.join();
    t2.join();

    // code end

    return 0;
}