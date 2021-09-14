#include "observer.h"

void Publisher::add_subscriber(ISubscriber* subscriber)
{
    subscribers_.push_back(subscriber);
}

void Publisher::remove_subscriber(ISubscriber* subscriber)
{
    subscribers_.remove(subscriber);
}

void Publisher::notify()
{
    std::list<ISubscriber*>::iterator iterator = subscribers_.begin();
    while (iterator != subscribers_.end())
    {
        (*iterator)->update(this->message_);
        iterator++;
    }
}

void Publisher::send_message(const std::string& message)
{
    this->message_ = message;
    notify();
}

Publisher::~Publisher()
{
    std::cout << "Goodbye!" << std::endl;
}

Subscriber::Subscriber(IPublisher* publisher, int number)
{
    this->publisher_ = std::move(publisher);
    this->number_ = number;
    this->publisher_->add_subscriber(this);
    std::cout << "Hello I'm subscriber " << number << std::endl;
};

Subscriber::~Subscriber()
{
    std::cout << "Subscriber " << this->number_ << ": Goodbye!" << std::endl;
}

void Subscriber::update(const std::string& message)
{
    this->message_ = message;
    std::cout << "Subscriber " <<this->number_<<": "<<message_ << std::endl;
}
void Subscriber::leave()
{
    this->publisher_->remove_subscriber(this);
}