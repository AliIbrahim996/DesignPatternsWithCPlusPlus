#include "observer.h"

void Publisher::add_subscriber(ISubscriber* subscriber)
{
    subscribers_.push_back(subscriber);
}

void Publisher::remove_subscriber(ISubscriber* subscriber)
{
    subscribers_.erase(std::remove(subscribers_.begin(), subscribers_.end(), subscriber), subscribers_.end());
}

void Publisher::notify()
{
    for(auto& subscriber : subscribers_)
    {
        subscriber->update(this->message_);
    }
}

void Publisher::send_message(const std::string& message)
{
    this->message_ = message;
    notify();
}

std::vector<ISubscriber*>& Publisher::get_subscribers()
{
    return this->subscribers_;
}

Publisher::~Publisher()
{
    std::cout << "Goodbye subsubscribers!\n" << std::endl;
}

Subscriber::Subscriber(IPublisher* publisher, int number)
{
    this->publisher_ = std::move(publisher);
    this->number_ = number;
    this->publisher_->add_subscriber(this);
    std::cout << "Hello I'm subscriber " << number << "\n" << std::endl;
};

Subscriber::~Subscriber()
{
    std::cout << "Subscriber " << this->number_  << ": Goodbye publishers!\n" << std::endl;
   
}

void Subscriber::update(const std::string& message)
{
    this->message_ = message;
    std::cout << "Subscriber " <<this->number_<<": "<<message_ << "\n" << std::endl;
}
void Subscriber::leave()
{
    std::cout << "Subscriber " << this->number_ << ": leaving!\n" << std::endl;
    this->publisher_->remove_subscriber(this);
}

void MemoryManager::add(ISubscriber* subscriber)
{
    subscribers_.push_back(subscriber);
}

void MemoryManager::add(IPublisher* publisher)
{
    publishers_.push_back(publisher);
}

void MemoryManager::remove(ISubscriber* subscriber)
{
    subscribers_.erase(std::remove(subscribers_.begin(), subscribers_.end(), subscriber), subscribers_.end());
   
    for(auto& publisher : publishers_)
    {
        auto& p_subscribers = publisher->get_subscribers();
        p_subscribers.erase(std::remove(p_subscribers.begin(), p_subscribers.end(), subscriber), p_subscribers.end());
        
    }
    delete subscriber;
}

void MemoryManager::remove(IPublisher* publisher)
{
    publishers_.erase(std::remove(publishers_.begin(), publishers_.end(), publisher), publishers_.end());
    delete publisher;
}


MemoryManager::~MemoryManager()
{
    for (auto& subscriber : subscribers_)
    {
        delete subscriber;
    }
    subscribers_.clear();
    for (auto& publisher : publishers_)
    {
        delete publisher;
    }
    publishers_.clear();
    std::cout << "memory cleaned!\n";
}
