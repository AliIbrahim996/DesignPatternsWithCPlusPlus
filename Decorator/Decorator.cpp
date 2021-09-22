#include "Decorator.h"

Decorator::Decorator(std::unique_ptr<Pizza>& p)
    : p(move(p)){};

string Decorator::getDesc()
{
    if (p)
        return p->getDesc();
    else
        return "";
}

double Decorator::getCost()
{
    if (p)
        return p->getCost();
    else
        return 0;
}

string BasePizza::getDesc()
{
    return "Base pizza ";
}

double BasePizza::getCost()
{
    return 1.0;
}

WithTomato::WithTomato(std::unique_ptr<Pizza>& base)
    : Decorator(base){};

string WithTomato::getDesc()
{
    return Decorator::getDesc().append(" with tomato");
}

double WithTomato::getCost()
{
    return Decorator::getCost() + 2.5;
}


WithChees::WithChees(std::unique_ptr<Pizza>& base)
    : Decorator(base){};

string WithChees::getDesc()
{
    return Decorator::getDesc().append(" with chees");
}

double WithChees::getCost()
{
    return Decorator::getCost() + 3.5;
}

WithMashroom::WithMashroom(std::unique_ptr<Pizza>& base)
    : Decorator(base){};

string WithMashroom::getDesc()
{
    return Decorator::getDesc().append(" with mashroom");
}

double WithMashroom::getCost()
{
    return Decorator::getCost() + 2.0;
}

std::unique_ptr<Pizza> PizzaFactory::getMyPizza(int type)
{
    std::unique_ptr<Pizza> pizza;
    std::unique_ptr<Pizza> base;
    std::unique_ptr<Pizza> with_chees;
    std::unique_ptr<Pizza> with_mashroom;
    std::unique_ptr<Pizza> with_tomato;

    switch (type)
    {
        case 1:
            base = std::make_unique<BasePizza>();
            pizza = std::move(base);
            break;
        case 2:
            base = std::make_unique<BasePizza>();
            with_chees = std::make_unique<WithChees>(base);
            pizza = std::move(with_chees);
            break;
        case 3:
            base = std::make_unique<BasePizza>();
            with_chees = std::make_unique<WithChees>(base);
            with_mashroom = std::make_unique < WithMashroom>(with_chees);
            pizza = std::move(with_mashroom);
            break;
        case 4:
            base = std::make_unique<BasePizza>();
            with_chees = std::make_unique<WithChees>(base);
            with_tomato = std::make_unique<WithTomato>(with_chees);
            pizza = std::move(with_tomato);
            break;
        case 5:
            base = std::make_unique<BasePizza>();
            with_tomato = std::make_unique<WithTomato>(base);
            with_chees = std::make_unique<WithChees>(with_tomato);
            with_mashroom = std::make_unique < WithMashroom>(with_chees);
            pizza = std::move(with_mashroom);
            break;
        default:
            pizza = nullptr;
            break;
    }
    return std::move(pizza);
}