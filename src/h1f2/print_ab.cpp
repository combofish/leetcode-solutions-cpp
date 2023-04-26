/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */
#include <semaphore.h>
#include <thread>

#include "../combofish_utils.hpp"

std::mutex mtx;
sem_t p_sem, c_sem;

int n = 20;

class Solution {

    // function start.
public:
    void print_a() {
        while (1) {
            if (n < 0) break;
            sem_wait(&p_sem);
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (n-- > 0) {
                    cout << n << 'A' << endl;
                }
            }
            sem_post(&c_sem);
        }
    }

    void print_b() {
        while (1) {
            if (n < 0) break;
            sem_wait(&c_sem);
            {
                std::lock_guard<std::mutex> lock(mtx);
                if (n-- > 0) {
                    cout << n << 'B' << endl;
                }
            }
            sem_post(&p_sem);
        }
    }

private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start
    sem_init(&p_sem, 0, 1);
    sem_init(&c_sem, 0, 0);

    std::thread t1(&Solution::print_a, solution);
    std::thread t2(&Solution::print_b, solution);

    char a[6];
    scanf("%s",&a[0]);



    t1.join();
    t2.join();

    // code end
    return 0;
}