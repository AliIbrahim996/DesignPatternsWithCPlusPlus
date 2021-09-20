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

CommandPattern::LightOnCommand::LightOnCommand(Light* light)
{
	this->light_ = std::move(light);
}

void CommandPattern::LightOnCommand::execute()
{
	this->light_->on();
}

CommandPattern::LightOnCommand::~LightOnCommand()
{
	delete this->light_;
}

CommandPattern::LightOffCommand::LightOffCommand(Light* light)
{
	this->light_ = std::move(light);
}

void CommandPattern::LightOffCommand::execute()
{
	this->light_->off();
}

CommandPattern::LightOffCommand::~LightOffCommand()
{
	delete this->light_;
}

CommandPattern::ITv::ITv(TV* tv)
{
	this->tv_ = std::move(tv);
}

CommandPattern::ITv::~ITv()
{
	delete this->tv_;
}

CommandPattern::TVOnCommand::TVOnCommand(TV* tv) : ITv(tv){}

void CommandPattern::TVOnCommand::execute()
{
	this->tv_->on();
}

CommandPattern::TVOffCommand::TVOffCommand(TV* tv): ITv(tv){}

void CommandPattern::TVOffCommand::execute()
{
	this->tv_->off();
}

CommandPattern::TvVolUpCommand::TvVolUpCommand(TV* tv):ITv(tv){}

void CommandPattern::TvVolUpCommand::execute()
{
	this->tv_->volume_up();
}

CommandPattern::TvVolDownCommand::TvVolDownCommand(TV* tv): ITv(tv){}

void CommandPattern::TvVolDownCommand::execute()
{
	this->tv_->volume_down();
}

void CommandPattern::RemoteControl::set_command(ICommand* command)
{
	this->slot_ = std::move(command);
}

void CommandPattern::RemoteControl::press_button()
{
	this->slot_->execute();
}

CommandPattern::RemoteControl::~RemoteControl()
{
	delete this->slot_;
}
