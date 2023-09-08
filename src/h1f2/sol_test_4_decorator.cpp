#include <iostream>
using namespace std;

// 抽象组件类
class Component {
public:
    virtual void operation() = 0;
    virtual ~Component(){};
};

// 具体组件类
class ConcreteComponent : public Component {
public:
    virtual void operation() {
        cout << "ConcreteComponent operation." << endl;
    }
};

// 抽象装饰器类
class Decorator : public Component {
public:
    Decorator(Component* component) : m_component(component) {}

    virtual void operation() {
        if (m_component != nullptr) {
            m_component->operation();
        }
    }

protected:
    Component* m_component;
};

// 具体装饰器类
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    virtual void operation() {
        Decorator::operation();
        cout << "ConcreteDecoratorA operation." << endl;
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    virtual void operation() {
        Decorator::operation();
        cout << "ConcreteDecoratorB operation." << endl;
    }
};

int main() {
    Component* component = new ConcreteComponent();
    component->operation();

    Component* decoratorA = new ConcreteDecoratorA(component);
    decoratorA->operation();

    Component* decoratorB = new ConcreteDecoratorB(decoratorA);
    decoratorB->operation();

    delete decoratorB;
    delete decoratorA;
    delete component;

    return 0;
}
