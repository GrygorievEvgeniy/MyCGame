#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual ~Observer() {}  // Virtual destructor
    virtual void update(const std::string &message) = 0;
};

class Subject {
public:
    virtual ~Subject() {}  // Virtual destructor

    void addObserver(Observer *observer) {
        m_observers.push_back(observer);
    }

    void removeObserver(Observer *observer) {
        m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
    }

    void notify(const std::string &message) {
        for (auto observer : m_observers) {
            observer->update(message);
        }
    }

private:
    std::vector<Observer*> m_observers;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string &name) : m_name(name) {}

    void update(const std::string &message) override {
        std::cout << m_name << " received message: " << message << std::endl;
    }

private:
    std::string m_name;
};

class ConcreteSubject : public Subject {
public:
    void someGameLogic() {
        std::string message = "change state";
        notify(message);
    }
};

int main() {
    ConcreteObserver observer1("Observer 1");
    ConcreteObserver observer2("Observer 2");
    ConcreteObserver observer3("Observer 3");

    ConcreteSubject subject;
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);
    subject.addObserver(&observer3);

    subject.someGameLogic();

    subject.removeObserver(&observer2);

    subject.someGameLogic();

    return 0;
}