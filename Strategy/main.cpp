#include "strategy.h"
using namespace Strategy;

static void MakeTheDuckFly(std::unique_ptr<DuckExample::IDuck>& duck)
{
    duck->fly();
}

static void MakeTheDuckQuack(std::unique_ptr<DuckExample::IDuck>& duck)
{
    duck->quack();
}

int main(int argc, char** argv)
{
    std::unique_ptr<DuckExample::IDuck> duck = std::make_unique<DuckExample::Duck>();

    MakeTheDuckFly(duck);
    MakeTheDuckQuack(duck);

    //change behaviour in running time;
    duck->set_fly_behaviour(std::make_unique<DuckExample::NoFlying>());

    MakeTheDuckFly(std::move(duck));
    MakeTheDuckQuack(std::move(duck));

    //Pockemon example
    std::cout << "\n========== PockemonExample ==========\n";
    std::unique_ptr<PockemonExample::Pockemon> pika = std::make_unique<PockemonExample::Pikatcho>();
    std::unique_ptr<PockemonExample::Pockemon> cha = std::make_unique<PockemonExample::Charmander>();
    std::unique_ptr<PockemonExample::Pockemon> sco = std::make_unique<PockemonExample::Scoero>();
    std::unique_ptr<PockemonExample::Pockemon> mea = std::make_unique<PockemonExample::Meaoz>();

    std::cout << "\n===== Pikatcho =====\n";
    pika->perform_fight();
    std::cout << "\n===== Charmander =====\n";
    cha->perform_fight();
    std::cout << "\n===== Scoero =====\n";
    sco->perform_fight();
    std::cout << "\n===== Meaoz =====\n";
    mea->perform_fight();
    std::cout<<"\n===== changing Meaoz fight strategy =====\n";
    std::cout << "\n===== Meaoz =====\n";
    mea->set_fight_type(std::make_unique<PockemonExample::FireFight>());
    mea->perform_fight();
}
