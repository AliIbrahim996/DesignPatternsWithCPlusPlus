#include "strategy.h"


void Strategy::DuckExample:: IDuck::set_fly_behaviour(Strategy::DuckExample::IFlyBeahaviour *fly_beahaviour)
{
  this->fly_behaviour = std::move(fly_beahaviour);
}

void  Strategy::DuckExample::IDuck::fly()
{
	this->fly_behaviour->fly();
}

Strategy::DuckExample::IDuck::~IDuck()
{
	delete this->fly_behaviour;
}

void Strategy::DuckExample::Flying::fly()
{
	std::cout << "Duck can fly!\n"; 
}

void  Strategy::DuckExample::NoFlying::fly()
{ 
	std::cout << "Duck can not fly!\n"; 
}

void  Strategy::DuckExample::Duck::quack()
{ 
	std::cout << "Quack Quack!\n"; 
}

Strategy::DuckExample::Duck::Duck()
{
	this->fly_behaviour = new Flying();
}

Strategy::DuckExample::RuubberDuck::RuubberDuck()
{ 
	this->fly_behaviour = new NoFlying();
}

void  Strategy::DuckExample::RuubberDuck::quack()
{
	std::cout << "Noise!\n";
}

Strategy::DuckExample::WoodenDuck::WoodenDuck()
{ 
	this->set_fly_behaviour(new NoFlying());
}

void Strategy::DuckExample:: WoodenDuck::quack()
{ 
	std::cout << "no sound!\n";
}

Strategy::PockemonExample::Pockemon::Pockemon(const std::string& name)
{
	this->name_ = name;
}

void Strategy::PockemonExample::Pockemon::set_name(const std::string& name)
{
	this->name_ = name;
}

std::string Strategy::PockemonExample::Pockemon::get_name()
{
	return this->name_;
}

void Strategy::PockemonExample::Pockemon::set_fight_type(IFight* fight)
{
	this->fight_type = std::move(fight);
}

Strategy::PockemonExample::IFight* Strategy::PockemonExample::Pockemon::get_fight_type()
{
	return this->fight_type;
}

void Strategy::PockemonExample::Pockemon::perform_fight()
{
	this->fight_type->fight();
}

void Strategy::PockemonExample::CantFight::fight()
{
	std::cout << "Pokemon can not fight!\n";
}

void Strategy::PockemonExample::WaterFight::fight()
{
	std::cout << "Water emission ...\n";
}

void Strategy::PockemonExample::ElictricFight::fight()
{
	std::cout << "Electric shock ...\n";
}

void Strategy::PockemonExample::FireFight::fight()
{
	std::cout << "Huge flame ...\n";
}

Strategy::PockemonExample::Pikatcho::Pikatcho() : Pockemon("Pikatcho")
{
	this->set_fight_type(new ElictricFight());
};

Strategy::PockemonExample::Scoero::Scoero() : Pockemon("Scoero")
{
	this->set_fight_type(new WaterFight());
};

Strategy::PockemonExample::Meaoz::Meaoz() : Pockemon("Meaoz")
{
	this->set_fight_type(new CantFight());
};

Strategy::PockemonExample::Charmander::Charmander() : Pockemon("Charmander") 
{
	this->set_fight_type(new FireFight());
};
