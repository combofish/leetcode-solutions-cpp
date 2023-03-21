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
    vector<vector<string>> result;
    vector<string> path;

    void backtracking(vector<vector<string>> &tickets, string station, vector<bool> &used) {
        if (path.size() == tickets.size()) {
            path.push_back(station);
            result.push_back(path);
            path.pop_back();
            return;
        }

        for (int i = 0; i < tickets.size(); i++) {
            if (tickets[i].front() == station && !used[i]) {
                used[i] = true;
                path.push_back(station);
                backtracking(tickets, tickets[i].back(), used);
                path.pop_back();
                used[i] = false;
            }
        }


    }
    // function start.
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        result.clear();
        path.clear();

        vector<bool> used(tickets.size(), false);
        backtracking(tickets, "JFK", used);

        std::sort(result.begin(), result.end());

        IC(result);
        return result.front();
    }

    // function end.
};

int main() {

    auto solution = new Solution();

    // code start
    vector<vector<string>> tickets = {{"JFK", "SFO"},
                                      {"JFK", "ATL"},
                                      {"SFO", "ATL"},
                                      {"ATL", "JFK"},
                                      {"ATL", "SFO"}};
    vector<string> rel = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};

    IC(tickets, rel);

    IC(solution->findItinerary(tickets));

    IC(2);
    vector<vector<string>> test = {{"AXA", "EZE"},
                                   {"EZE", "AUA"},
                                   {"ADL", "JFK"},
                                   {"ADL", "TIA"},
                                   {"AUA", "AXA"},
                                   {"EZE", "TIA"},
                                   {"EZE", "TIA"},
                                   {"AXA", "EZE"},
                                   {"EZE", "ADL"},
                                   {"ANU", "EZE"},
                                   {"TIA", "EZE"},
                                   {"JFK", "ADL"},
                                   {"AUA", "JFK"},
                                   {"JFK", "EZE"},
                                   {"EZE", "ANU"},
                                   {"ADL", "AUA"},
                                   {"ANU", "AXA"},
                                   {"AXA", "ADL"},
                                   {"AUA", "JFK"},
                                   {"EZE", "ADL"},
                                   {"ANU", "TIA"},
                                   {"AUA", "JFK"},
                                   {"TIA", "JFK"},
                                   {"EZE", "AUA"},
                                   {"AXA", "EZE"},
                                   {"AUA", "ANU"},
                                   {"ADL", "AXA"},
                                   {"EZE", "ADL"},
                                   {"AUA", "ANU"},
                                   {"AXA", "EZE"},
                                   {"TIA", "AUA"},
                                   {"AXA", "EZE"},
                                   {"AUA", "SYD"},
                                   {"ADL", "JFK"},
                                   {"EZE", "AUA"},
                                   {"ADL", "ANU"},
                                   {"AUA", "TIA"},
                                   {"ADL", "EZE"},
                                   {"TIA", "JFK"},
                                   {"AXA", "ANU"},
                                   {"JFK", "AXA"},
                                   {"JFK", "ADL"},
                                   {"ADL", "EZE"},
                                   {"AXA", "TIA"},
                                   {"JFK", "AUA"},
                                   {"ADL", "EZE"},
                                   {"JFK", "ADL"},
                                   {"ADL", "AXA"},
                                   {"TIA", "AUA"},
                                   {"AXA", "JFK"},
                                   {"ADL", "AUA"},
                                   {"TIA", "JFK"},
                                   {"JFK", "ADL"},
                                   {"JFK", "ADL"},
                                   {"ANU", "AXA"},
                                   {"TIA", "AXA"},
                                   {"EZE", "JFK"},
                                   {"EZE", "AXA"},
                                   {"ADL", "TIA"},
                                   {"JFK", "AUA"},
                                   {"TIA", "EZE"},
                                   {"EZE", "ADL"},
                                   {"JFK", "ANU"},
                                   {"TIA", "AUA"},
                                   {"EZE", "ADL"},
                                   {"ADL", "JFK"},
                                   {"ANU", "AXA"},
                                   {"AUA", "AXA"},
                                   {"ANU", "EZE"},
                                   {"ADL", "AXA"},
                                   {"ANU", "AXA"},
                                   {"TIA", "ADL"},
                                   {"JFK", "ADL"},
                                   {"JFK", "TIA"},
                                   {"AUA", "ADL"},
                                   {"AUA", "TIA"},
                                   {"TIA", "JFK"},
                                   {"EZE", "JFK"},
                                   {"AUA", "ADL"},
                                   {"ADL", "AUA"},
                                   {"EZE", "ANU"},
                                   {"ADL", "ANU"},
                                   {"AUA", "AXA"},
                                   {"AXA", "TIA"},
                                   {"AXA", "TIA"},
                                   {"ADL", "AXA"},
                                   {"EZE", "AXA"},
                                   {"AXA", "JFK"},
                                   {"JFK", "AUA"},
                                   {"ANU", "ADL"},
                                   {"AXA", "TIA"},
                                   {"ANU", "AUA"},
                                   {"JFK", "EZE"},
                                   {"AXA", "ADL"},
                                   {"TIA", "EZE"},
                                   {"JFK", "AXA"},
                                   {"AXA", "ADL"},
                                   {"EZE", "AUA"},
                                   {"AXA", "ANU"},
                                   {"ADL", "EZE"},
                                   {"AUA", "EZE"}};
    IC(test);
    IC(solution->findItinerary(test));
    // code end

    delete solution;
    return 0;
}


