#ifndef command_pattern_h
#define command_pattern_h
#include<iostream>
#include<memory>
namespace CommandPattern
{
	class ICommand;
	class RemoteControl;
	class LightOnCommand;
	class LightOffCommand;
	class TVOnCommand;
	class TVOffCommand;
	class TvVolDownCommand;
	class TvVolUpCommand;
	class TV;
	class ITv;
	class Light;
}

class CommandPattern::ICommand
{
public:
	virtual void execute() = 0;
};

class CommandPattern::Light
{
public:
	void on();
	void off();
};

class CommandPattern::TV
{
public:
	void on();
	void off();
	void volume_up();
	void volume_down();
};

class CommandPattern::LightOnCommand :public ICommand
{
private:
	std::unique_ptr<Light> light_;
public:
	LightOnCommand(std::unique_ptr<Light>& light);
	void execute() override;
};

class CommandPattern::LightOffCommand :public ICommand
{
private:
	std::unique_ptr<Light> light_;
public:
	LightOffCommand(std::unique_ptr<Light>& light);
	void execute() override;
};

class CommandPattern::ITv : public ICommand
{
protected:
	std::unique_ptr<TV> tv_;
public:
	ITv(std::unique_ptr<TV>& tv);
};
class CommandPattern::TVOnCommand :public ITv
{
public:
	TVOnCommand(std::unique_ptr<TV>& tv);
	void execute() override;
};

class CommandPattern::TVOffCommand :public ITv
{
public:
	TVOffCommand(std::unique_ptr<TV>& tv);
	void execute() override;
};
class CommandPattern::TvVolUpCommand:public ITv
{
public:
	TvVolUpCommand(std::unique_ptr<TV>& tv);
	void execute() override;
};

class CommandPattern::TvVolDownCommand :public ITv
{
public:
	TvVolDownCommand(std::unique_ptr<TV>& tv);
	void execute() override;
};

class CommandPattern::RemoteControl
{
private:
	std::unique_ptr<ICommand> slot_;
public:
	void set_command(std::unique_ptr<ICommand>& command);
	void press_button();
};
#endif // !command_pattern_h
