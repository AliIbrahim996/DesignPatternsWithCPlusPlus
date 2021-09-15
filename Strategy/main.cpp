#include "strategy.h"
using namespace Strategy;
static void MakeTheDuckFly(DuckExample::IDuck* duck)
{
    duck->fly();
}

static void MakeTheDuckQuack(DuckExample::IDuck* duck)
{
    duck->quack();
}

int main(int argc, char** argv)
{
    DuckExample::IDuck* duck = new DuckExample::Duck();

    MakeTheDuckFly(duck);
    MakeTheDuckQuack(duck);

    //change behaviour in running time;
    duck->set_fly_behaviour(new DuckExample::NoFlying);
    MakeTheDuckFly(duck);
    MakeTheDuckQuack(duck);

    //Pockemon example
    std::cout << "========== PockemonExample ==========\n";
    PockemonExample::Pockemon* pika = new PockemonExample::Pikatcho();
    PockemonExample::Pockemon* cha = new PockemonExample::Charmander();
    PockemonExample::Pockemon* sco = new PockemonExample::Scoero();
    PockemonExample::Pockemon* mea = new PockemonExample::Meaoz();
    std::cout << "===== Pikatcho =====\n";
    pika->perform_fight();
    std::cout << "===== Charmander =====\n";
    cha->perform_fight();
    std::cout << "===== Scoero =====\n";
    sco->perform_fight();
    std::cout << "===== Meaoz =====\n";
    mea->perform_fight();
    std::cout<<"===== changing Meaoz fight strategy =====\n";
    std::cout << "===== Meaoz =====\n";
    mea->set_fight_type(new PockemonExample::FireFight());
    mea->perform_fight();
}
