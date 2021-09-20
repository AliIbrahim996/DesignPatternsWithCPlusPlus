#ifndef command_pattern_h
#define command_pattern_h
#include<iostream>
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
	Light* light_;
public:
	LightOnCommand(Light* light);
	void execute() override;
	~LightOnCommand();
};

class CommandPattern::LightOffCommand :public ICommand
{
private:
	Light* light_;
public:
	LightOffCommand(Light* light);
	void execute() override;
	~LightOffCommand();
};

class CommandPattern::ITv : public ICommand
{
protected:
	TV* tv_;
public:
	ITv(TV* tv);
	~ITv();
};
class CommandPattern::TVOnCommand :public ITv
{
public:
	TVOnCommand(TV* tv);
	void execute() override;
};

class CommandPattern::TVOffCommand :public ITv
{
public:
	TVOffCommand(TV* tv);
	void execute() override;
};
class CommandPattern::TvVolUpCommand:public ITv
{
public:
	TvVolUpCommand(TV* tv);
	void execute() override;
};

class CommandPattern::TvVolDownCommand :public ITv
{
public:
	TvVolDownCommand(TV* tv);
	void execute() override;
};

class CommandPattern::RemoteControl
{
private:
	ICommand* slot_;
public:
	void set_command(ICommand* command);
	void press_button();
	~RemoteControl();
};
#endif // !command_pattern_h
