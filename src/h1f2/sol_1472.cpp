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

class Solution {

    // function start.
public:


private:
    // function end.
};

class BrowserHistory {
    int cur;
    vector<string> rec;

public:
    BrowserHistory(string homepage) {
        rec.clear();
        rec.emplace_back(homepage);
        cur = 0;
        IC(rec, cur);
    }

    void visit(string url) {
        IC();
        if (cur + 1 == (int)rec.size()) {
            rec.emplace_back(url);
            ++cur;
        } else {
            rec[++cur] = url;
            rec.resize(cur + 1);
        }
        IC(rec, cur);
        cout << endl << endl;
    }

    string back(int steps) {
        int nI = std::max(0, cur - steps);
        cur = nI;
        IC(rec, cur);
        return rec[nI];
    }

    string forward(int steps) {
        int nI = std::min(cur + steps, (int) rec.size() - 1);
        cur = nI;
        IC(rec, cur);

        return rec[cur];
    }
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    auto browserHistory = new BrowserHistory("leetcode.com");
    browserHistory->visit("google.com");
    browserHistory->visit("facebook.com");
    browserHistory->visit("youtube.com");


    IC(browserHistory->back(1));
    IC(browserHistory->back(1));
    IC(browserHistory->forward(1));
    browserHistory->visit("linkedin.com");

    IC(browserHistory->forward(2));
    IC(browserHistory->back(2));
    IC(browserHistory->back(7));


    delete browserHistory;
    // code end

    return 0;
}