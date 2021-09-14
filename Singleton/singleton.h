#ifndef singleton_h
#define singleton_h
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
class Singleton
{
private:
    static Singleton* instance_;
    std::string value;
    static std::mutex mutex_;

protected:
    Singleton(const std::string value);
    ~Singleton();


public:
    /**
     * @brief a static method that check and return only one instance.
     * 
     * \param value
     * \return 
     */
    static Singleton* get_instance(const std::string value);
    /**
     * @brief Singleton instance should not be cloneable.
     */
    Singleton(Singleton& other) = delete;
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
