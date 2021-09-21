#ifndef singleton_h
#define singleton_h
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
class Singleton
{
private:
    std::string value_;
    Singleton(const std::string& value);
    ~Singleton();
public:
    /**
     * @brief a static method that check and return only one instance.
     *
     * \param 
     * \return a single instance of the class
     */
    static Singleton& instance(const std::string& value);
    /**
    * @brief Singleton instance should not be cloneable.
    */
    Singleton(const Singleton&) = delete;
    /**
     * @brief Singleton instance should not be ssignable.
     */
    void operator=(const Singleton&) = delete;

    /**
     * @brief demo method to  get the instance value
     *
     * \return value
     */
    std::string get_value();
};

#endif // !singleton_h
