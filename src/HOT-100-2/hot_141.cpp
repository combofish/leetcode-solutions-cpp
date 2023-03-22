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
#include <algorithm>

class Solution {

    // function start.
public:

    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        auto fast = head->next;
        auto slow = head;

        while (fast != slow) {
            if (!fast || !fast->next) return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return true;


    }

private:

    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto n3 = new ListNode(3);
    auto n2 = new ListNode(2);
    auto n0 = new ListNode(0);
    auto n4 = new ListNode(-4);
    n3->next = n2;
    n2->next = n0;
    n0->next = n4;
    n4->next = n2;

    bool ans = true;
    IC(ans);

    IC(solution->hasCycle(n3));

    deleteListNode(n3, 4);

    // code end

    return 0;
}


