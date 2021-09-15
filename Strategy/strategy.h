#ifndef strategy_h
#define startegy_h
#include <iostream>
#include <memory>

class IFlyBeahaviour 
{
	public:
	virtual void fly() = 0;
};

class IDuck 
{
	protected:
	  IFlyBeahaviour *fly_behaviour;

	public:
	  void set_fly_behaviour(IFlyBeahaviour *fly_behaviour);
	  void fly();
	  virtual void quack() = 0;
	  ~IDuck();
};

class Flying : public IFlyBeahaviour
{
	public:
	  void fly() override;
};

class NoFlying : public IFlyBeahaviour
{
	public:
	  void fly() override;
};

class RuubberDuck : public IDuck {
	public:
		RuubberDuck();
		void quack() override;
};

class Duck : public IDuck 
{
	public:
		Duck();
		void quack() override;
};

class WoodenDuck : public IDuck 
{
	public: 
		WoodenDuck(); 
		void quack() override;
};
#endif // !strategy_h
