#include <iostream>
#include <memory>
#include <utility>
#include <icecream.hpp>

using namespace std;


class Resource {
public:
    Resource() {
        cout << "Resource acquired" << endl;
    }
    ~Resource() {
        cout << "Resource destroyed" << endl;
    }
};

void show(unique_ptr<Resource> &res){
    
    auto ans = static_cast<bool>(res) ? "not null": "null";
    IC(ans);
}
int main(int argc, char const *argv[])
{
    unique_ptr<Resource> res1{new Resource()};
    unique_ptr<Resource> res2{};

    show(res1);
    show(res2);

    res2 = std::move(res1);
    cout<<"Ownership transfered"<<endl;

    show(res1);
    show(res2);


    return 0;
}

