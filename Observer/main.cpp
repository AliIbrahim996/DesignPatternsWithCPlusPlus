#include "observer.h"

std::unique_ptr<MemoryManager> manager;

void Client()
{
    IPublisher* publisher = new Publisher();
    IPublisher* publisher2 = new Publisher();

    manager = std::make_unique<MemoryManager>();


    ISubscriber* subscriber1 = new Subscriber(publisher, 1);
    ISubscriber* subscriber2 = new Subscriber(publisher, 2);
    ISubscriber* subscriber3 = new Subscriber(publisher, 3);
    ISubscriber* subscriber4 = new Subscriber(publisher, 4);
    ISubscriber* subscriber5 = new Subscriber(publisher, 5);
    ISubscriber* subscriber6 = new Subscriber(publisher, 6);

    ISubscriber* subscriber7;
    ISubscriber* subscriber8;

    manager->add(publisher);
    manager->add(publisher2);

    manager->add(subscriber1);
    manager->add(subscriber2);
    manager->add(subscriber3);
    manager->add(subscriber4);
    manager->add(subscriber5);
    manager->add(subscriber6);
    

    publisher->send_message("Hello!");
    subscriber5->leave();
    
    subscriber5 = new Subscriber(publisher2, 5);

    publisher->send_message("How are you!");
    publisher2->send_message("hello every one\n");

    subscriber2->leave();

    subscriber7 = new Subscriber(publisher, 7);
    subscriber8 = new Subscriber(publisher, 8);

    manager->add(subscriber7);
    manager->add(subscriber8);

    publisher->send_message("What are you doing right now?!");

    subscriber1->leave();
    subscriber3->leave();
    subscriber4->leave();
    subscriber6->leave();
    subscriber7->leave();
    subscriber8->leave();
}
int main(int argc, char** argv)
{
    Client();
    return 0;
}
