#include "strategy.h"


void DuckExample::IDuck::set_fly_behaviour(IFlyBeahaviour *fly_beahaviour)
{
  this->fly_behaviour = std::move(fly_beahaviour);
}

void  DuckExample::IDuck::fly()
{
	this->fly_behaviour->fly();
}

DuckExample::IDuck::~IDuck()
{
	delete this->fly_behaviour;
}

void  DuckExample::Flying::fly()
{
	std::cout << "Duck can fly!\n"; 
}

void  DuckExample::NoFlying::fly()
{ 
	std::cout << "Duck can not fly!\n"; 
}

void  DuckExample::Duck::quack()
{ 
	std::cout << "Quack Quack!\n"; 
}

DuckExample::Duck::Duck()
{
	this->fly_behaviour = new Flying();
}

DuckExample::RuubberDuck::RuubberDuck()
{ 
	this->fly_behaviour = new NoFlying();
}

void  DuckExample::RuubberDuck::quack()
{
	std::cout << "Noise!\n";
}

DuckExample::WoodenDuck::WoodenDuck()
{ 
	this->set_fly_behaviour(new NoFlying());
}

void DuckExample::WoodenDuck::quack()
{ 
	std::cout << "no sound!\n";
}
