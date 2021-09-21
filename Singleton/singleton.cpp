#include "singleton.h"

Singleton::Singleton(const std::string& value)
{
    std::cout << "New instance initialized!" << std::endl;
    this->value_ = value;
}

Singleton::~Singleton(){}

Singleton& Singleton::instance(const std::string& value)
{
    // TODO: insert return statement here
    static Singleton instance(value);
    return instance;
}

std::string Singleton::get_value()
{
    return this->value_;
}
