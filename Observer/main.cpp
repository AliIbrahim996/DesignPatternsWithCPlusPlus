#include "observer.h"

void Client()
{
    IPublisher* publisher = new Publisher();
    ISubscriber* subscriber1 = new Subscriber(publisher, 1);
    ISubscriber* subscriber2 = new Subscriber(publisher, 2);
    ISubscriber* subscriber3 = new Subscriber(publisher, 3);
    ISubscriber* subscriber4 = new Subscriber(publisher, 4);
    ISubscriber* subscriber5 = new Subscriber(publisher, 5);
    ISubscriber* subscriber6 = new Subscriber(publisher, 6);
    ISubscriber* subscriber7;
    ISubscriber* subscriber8;
    publisher->send_message("Hello!");
    subscriber5->leave();
    delete subscriber5;
    publisher->send_message("How are you!");
    subscriber2->leave();
    delete subscriber2;
    subscriber7 = new Subscriber(publisher, 7);
    subscriber8 = new Subscriber(publisher, 8);
    publisher->send_message("What are you doing right now?!");
    delete subscriber1;
    delete subscriber6;
    delete subscriber3;
    delete subscriber4;
    delete subscriber7;
    delete subscriber8;
    delete publisher;

}
int main(int argc, char** argv)
{
    Client();
    return 0;
}
