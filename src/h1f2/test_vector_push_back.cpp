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
    Solution(){
        cout<<"Constructed"<<endl;
    }

    ~Solution(){
        cout<<"Deconstructed"<<endl;
    }

    Solution(const Solution &solution){
        cout<<"Copy constructe"<<endl;
    }

    Solution(Solution &&solution) noexcept{
        cout << "Move construce"<<endl;
    }



private:
    // function end.
};

int main() {

    //  auto solution = std::make_shared<Solution>();

    // code start

    vector<Solution> vecs;

    // case 1
    Solution sol2;
    vecs.emplace_back(sol2);

    // auto sol3 = std::move(sol2);

    /**
    Constructed
    Copy constructe
    Deconstructed
    Deconstructed
    */


    // case 2
    // Solution sol;
    // vecs.push_back(sol);

    /**
    Constructed
    Copy constructe
    Deconstructed
    Deconstructed
    */




    // code end

    return 0;
}