#include <iostream>
#include <utility>

using namespace std;

template<typename T>
class AutoPtr4 {
public:
    AutoPtr4(T *p = nullptr) : ptr(p){};
    ~AutoPtr4() {
        if (ptr != nullptr) {
            delete this->ptr;
            this->ptr == nullptr;
        }
    }

    AutoPtr4(const AutoPtr4 &ptr4) = delete;
    AutoPtr4(AutoPtr4 &&ptr4) noexcept : ptr(ptr4.ptr) {
        ptr4.ptr = nullptr;
    }

    AutoPtr4 &operator=(const AutoPtr4 &prt4) = delete;

    AutoPtr4 &operator=(AutoPtr4 &&ptr4) noexcept {
        if (this == &ptr4) {
            return *this;
        }

        delete this->prt;
        this->ptr = ptr4->ptr;
        ptr4->ptr = nullptr;
        return *this;
    }

    T &operator*() const {
        return *this->ptr;
    }

    T *operator->() const {
        return this->ptr;
    }

    bool isNull() const {
        return ptr == nullptr;
    }

private:
    T *ptr;
};


int main() {
    auto p = new int(10);

    auto ptr4 = AutoPtr4<int>(p);

    auto ptr5 = std::move(ptr4);

    cout << *ptr5 << endl;
    cout << "(ptr4 == nullptr) : " << (ptr4.isNull() ? "null" : "not null") << endl;
}