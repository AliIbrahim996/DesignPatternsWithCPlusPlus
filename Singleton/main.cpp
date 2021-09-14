#include "singleton.h"
#include <thread>

void thread_foo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::get_instance("Foo");
    std::cout << singleton->get_value() << std::endl;
}

void thread_bar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::get_instance("bar");
    std::cout << singleton->get_value() << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "If you see the same output that meens there is only one instance" << std::endl;
    std::thread t1(thread_foo);
    std::thread t2(thread_bar);
    t1.join();
    t2.join();
    return 0;
}
