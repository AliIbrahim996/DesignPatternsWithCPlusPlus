#ifndef state_h
#define state_h
#include<string>
#include<iostream>
namespace Atm
{
	class ATMState;
	class AtmMachine;
	class HasCardState;
	class NoCardState;
	class NoCashState;
	class ReadyState;
}
	class Atm::ATMState
	{
	
	public:
		virtual void insert_card() = 0;
		virtual void eject_card() = 0;
		virtual void insert_password(const std::string& password) = 0;
		virtual void request_cash(double amount) = 0;
		virtual ~ATMState() {};
		
	};

	class Atm::AtmMachine
	{
	private:
		std::unique_ptr<ATMState> has_card_;
		std::unique_ptr<ATMState> no_card_;
		std::unique_ptr<ATMState> no_cash_;
		std::unique_ptr<ATMState> ready_;
		double total_balance_;
		ATMState* current_state_;
	public:
		AtmMachine(double balance);
		void insert_card();
		void eject_card();
		void insert_password(const std::string& password);
		void request_cash(double amount);
		void set_balance(double balance);
		double get_balance();
		void set_current_state(ATMState* state);
		ATMState* get_current_state();
		ATMState* get_no_card_state();
		ATMState* get_has_card_state();
		ATMState* get_no_cash_state();
		ATMState* get_ready_state();
	};
	class Atm::HasCardState : public ATMState
	{
	private:
		AtmMachine* atm_;
	public:
		HasCardState(AtmMachine* atm);
		void insert_card() override;
		void eject_card() override;
		void insert_password(const std::string& password) override;
		void request_cash(double amount) override;
	};

	class Atm::NoCardState : public ATMState
	{
	private:
		AtmMachine* atm_;
	public:
		NoCardState(AtmMachine* atm);
		void insert_card() override;
		void eject_card() override;
		void insert_password(const std::string& password) override;
		void request_cash(double amount) override;
	};

	class Atm::NoCashState : public ATMState
	{
	private:
		AtmMachine* atm_;
	public:
		NoCashState(AtmMachine* atm);
		void insert_card() override;
		void eject_card() override;
		void insert_password(const std::string& password) override;
		void request_cash(double amount) override;
	};
	class Atm::ReadyState : public ATMState
	{
	private:
		AtmMachine* atm_;
	public:
		ReadyState(AtmMachine* atm);
		void insert_card() override;
		void eject_card() override;
		void insert_password(const std::string& password) override;
		void request_cash(double amount) override;
	};

#endif // !state_h
