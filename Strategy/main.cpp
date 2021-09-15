#include "strategy.h"
static void MakeTheDuckFly(IDuck* duck)
{
    duck->fly();
}

static void MakeTheDuckQuack(IDuck* duck)
{
    duck->quack();
}

int main(int argc, char** argv)
{
    IDuck* duck = new Duck();

    MakeTheDuckFly(duck);
    MakeTheDuckQuack(duck);

    //change behaviour in running time;
    duck->set_fly_behaviour(new NoFlying);
    MakeTheDuckFly(duck);
    MakeTheDuckQuack(duck);
}
