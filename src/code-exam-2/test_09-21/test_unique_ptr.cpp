#include <icecream.hpp>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Task {
    int m_id;

public:
    Task(int id) : m_id(id) {
        cout << "Task::constructor" << endl;
    }
    ~Task() {
        cout << "Task::Destructor : " << m_id<< " (m_id)"<< endl;
    }

    int get_id() const { return m_id; }
};

int main() {
    // unique_ptr
    unique_ptr<Task> task_ptr(new Task(23));
    IC(task_ptr->get_id());

    shared_ptr<Task> taskPtr(new Task(21));
    IC(taskPtr->get_id());

    weak_ptr<Task> weak1 = taskPtr;
    IC(weak1.lock()->get_id());

    return 0;
}