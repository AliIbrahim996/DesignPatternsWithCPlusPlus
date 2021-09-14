#include "singleton.h"


Singleton* Singleton::instance_{nullptr};
std::mutex Singleton::mutex_;
Singleton::Singleton(const std::string value)
{
    std::cout << "New instance initialized!" << std::endl;
    this->value = value;
}
Singleton* Singleton::get_instance(const std::string value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr)
        instance_ = new Singleton(value);
    return instance_;
}

Singleton::~Singleton()
{
    delete (instance_);
}

std::string Singleton::get_value()
{
    return this->value;
}
