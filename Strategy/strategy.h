#ifndef strategy_h
#define startegy_h
#include <iostream>
#include <memory>
#include <string>
namespace Strategy
{
	namespace DuckExample 
	{

		class IFlyBeahaviour
		{
		public:
			virtual void fly() = 0;
		};

		class IDuck
		{
		protected:
			IFlyBeahaviour* fly_behaviour;

		public:
			void set_fly_behaviour(IFlyBeahaviour* fly_behaviour);
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
	}
	namespace PockemonExample
	{
		class IFight
		{
		public:
			virtual void fight() = 0;
		};

		class Pockemon
		{
		private:
			std::string name_;
			IFight* fight_type;
		public:
			Pockemon(const std::string& name);
			void set_name(const std::string& name);
			std::string get_name();
			void set_fight_type(IFight* fight);
			IFight* get_fight_type();
			void perform_fight();
		};

		class CantFight : public IFight
		{
		public:
				void fight() override;
		};

		class WaterFight : public IFight
		{
		public:
			void fight() override;
		};

		class FireFight : public IFight
		{
		public:
			void fight() override;
		};

		class ElictricFight : public IFight
		{
		public:
			void fight() override;
		};

		class Pikatcho : public Pockemon
		{
		public:
			Pikatcho();
		};

		class Meaoz : public Pockemon
		{
		public:
			Meaoz();
		};

		class Scoero : public Pockemon
		{
		public:
			Scoero();
		};

		class Charmander : public Pockemon
		{
		public:
			Charmander();
		};
	}
}
#endif// !strategy_h
