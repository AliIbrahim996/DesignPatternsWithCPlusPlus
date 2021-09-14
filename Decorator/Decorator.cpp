#include "Decorator.h"

Decorator::Decorator(Pizza* p)
    : p(move(p)){};

string Decorator::getDesc()
{
    if (p)
        return p->getDesc();
}

double Decorator::getCost()
{
    if (p)
        return p->getCost();
}

Decorator::~Decorator()
{
    delete (p);
}

string BasePizza::getDesc()
{
    return "Base pizza ";
}

double BasePizza::getCost()
{
    return 1.0;
}

WithTomato::WithTomato(Pizza* base)
    : Decorator(base){};

string WithTomato::getDesc()
{
    return Decorator::getDesc().append(" with tomato");
}

double WithTomato::getCost()
{
    return Decorator::getCost() + 2.5;
}


WithChees::WithChees(Pizza* base)
    : Decorator(base){};

string WithChees::getDesc()
{
    return Decorator::getDesc().append(" with chees");
}

double WithChees::getCost()
{
    return Decorator::getCost() + 3.5;
}

WithMashroom::WithMashroom(Pizza* base)
    : Decorator(base){};

string WithMashroom::getDesc()
{
    return Decorator::getDesc().append(" with mashroom");
}

double WithMashroom::getCost()
{
    return Decorator::getCost() + 2.0;
}

Pizza* PizzaFactory::getMyPizza(int type)
{
    switch (type)
    {
        case 1:
            return new BasePizza();
            break;
        case 2:
            return new WithChees(new BasePizza());
            break;
        case 3:
            return new WithMashroom(new WithChees(new BasePizza()));
            break;
        case 4:
            new WithTomato(new WithChees(new BasePizza()));
            break;
        case 5:
            new WithMashroom(new WithChees(new WithTomato(new BasePizza())));
            break;
        default:
            return nullptr;
            break;
    }
}