#include "command.h"

void CommandPattern::Light::on()
{
	std::cout << "Light is on!\n";
}

void CommandPattern::Light::off()
{
	std::cout << "Light is off!\n";
}

void CommandPattern::TV::on()
{
	std::cout << "TV is on!\n";
}

void CommandPattern::TV::off()
{
	std::cout << "TV is off!\n";
}

void CommandPattern::TV::volume_up()
{
	std::cout << "Volume up!\n";
}

void CommandPattern::TV::volume_down()
{
	std::cout << "Volume off\n";
}

CommandPattern::LightOnCommand::LightOnCommand(std::unique_ptr<Light>& light)
{
	this->light_ = std::move(light);
}

void CommandPattern::LightOnCommand::execute()
{
	this->light_->on();
}


CommandPattern::LightOffCommand::LightOffCommand(std::unique_ptr<Light>& light)
{
	this->light_ = std::move(light);
}

void CommandPattern::LightOffCommand::execute()
{
	this->light_->off();
}


CommandPattern::ITv::ITv(std::unique_ptr<TV>& tv)
{
	this->tv_ = std::move(tv);
}


CommandPattern::TVOnCommand::TVOnCommand(std::unique_ptr<TV>& tv) : ITv(tv){}

void CommandPattern::TVOnCommand::execute()
{
	this->tv_->on();
}

CommandPattern::TVOffCommand::TVOffCommand(std::unique_ptr<TV>& tv): ITv(tv){}

void CommandPattern::TVOffCommand::execute()
{
	this->tv_->off();
}

CommandPattern::TvVolUpCommand::TvVolUpCommand(std::unique_ptr<TV>& tv):ITv(tv){}

void CommandPattern::TvVolUpCommand::execute()
{
	this->tv_->volume_up();
}

CommandPattern::TvVolDownCommand::TvVolDownCommand(std::unique_ptr<TV>& tv): ITv(tv){}

void CommandPattern::TvVolDownCommand::execute()
{
	this->tv_->volume_down();
}

void CommandPattern::RemoteControl::set_command(std::unique_ptr<ICommand>& command)
{
	this->slot_ = std::move(command);
}

void CommandPattern::RemoteControl::press_button()
{
	this->slot_->execute();
}
