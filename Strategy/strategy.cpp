#include "strategy.h"

void IDuck::set_fly_behaviour(IFlyBeahaviour *fly_beahaviour)
{
  this->fly_behaviour = std::move(fly_beahaviour);
}

void IDuck::fly() 
{
	this->fly_behaviour->fly();
}

IDuck::~IDuck() 
{
	delete this->fly_behaviour;
}

void Flying::fly()
{
	std::cout << "Duck can fly!\n"; 
}

void NoFlying::fly()
{ 
	std::cout << "Duck can not fly!\n"; 
}

void Duck::quack() 
{ 
	std::cout << "Quack Quack!\n"; 
}

Duck::Duck() 
{
	this->fly_behaviour = new Flying();
}

RuubberDuck::RuubberDuck() 
{ 
	this->fly_behaviour = new NoFlying();
}

void RuubberDuck::quack() 
{
	std::cout << "Noise!\n";
}

WoodenDuck::WoodenDuck() 
{ 
	this->set_fly_behaviour(new NoFlying());
}

void WoodenDuck::quack() 
{ 
	std::cout << "no sound!\n";
}
