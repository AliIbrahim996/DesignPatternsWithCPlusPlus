#ifndef observer_h
#define observer_h
#include <vector>
#include <string>
#include <iostream>


class ISubscriber
{
public:
    virtual void update(const std::string& message) = 0;
    virtual void leave() = 0;
    virtual ~ISubscriber(){};
};

class IPublisher
{
public:
    virtual void add_subscriber(ISubscriber* subscriber) = 0;
    virtual void remove_subscriber(ISubscriber* subscriber) = 0;
    virtual void notify() = 0;
    virtual void send_message(const std::string& message) = 0;
    virtual std::vector<ISubscriber*>& get_subscribers() = 0;
    virtual ~IPublisher(){};
};
class Subscriber : public ISubscriber
{
private:
    IPublisher* publisher_;
    std::string message_;
    int number_;

public:
    Subscriber(IPublisher* publisher, int number);
    void update(const std::string& message) override;
    void leave() override;
    ~Subscriber();
};


class Publisher : public IPublisher
{
private:
    std::vector<ISubscriber*> subscribers_;
    std::string message_;

public:
    void add_subscriber(ISubscriber* subscriber) override;
    void remove_subscriber(ISubscriber* subscriber) override;
    void notify() override;
    void send_message(const std::string& message) override;
    std::vector<ISubscriber*>& get_subscribers() override;
    ~Publisher();
};
class MemoryManager
{
private:
    std::vector<ISubscriber*> subscribers_;
    std::vector<IPublisher*> publishers_;
public:
     void add(ISubscriber* subscriber);
     void add(IPublisher* publisher);

     void remove(ISubscriber* subscriber);
     void remove(IPublisher* publisher);

     ~MemoryManager();
};
#endif // !observer_h
