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
		virtual void request_cash(const double& amount) = 0;
	};

	class Atm::AtmMachine
	{
	private:
		std::unique_ptr<HasCardState> has_card_;
		std::unique_ptr<NoCardState> no_card_;
		std::unique_ptr<NoCashState> no_cash_;
		std::unique_ptr<ReadyState> ready_;
		double total_balance_;
		std::unique_ptr<ATMState> current_state_;
	public:
		AtmMachine(double balance);
		void insert_card();
		void eject_card();
		void insert_password(const std::string& password);
		void request_cash(const double& amount);
		void set_balance(const double& balance);
		double& get_balance();
		void set_current_state(std::unique_ptr<ATMState>&  state);
		std::unique_ptr <ATMState> get_current_state();
		std::unique_ptr <ATMState> get_no_card_state();
		std::unique_ptr <ATMState> get_has_card_state();
		std::unique_ptr <ATMState> get_no_cash_state();
		std::unique_ptr <ATMState> get_ready_state();
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
		void request_cash(const double& amount) override;
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
		void request_cash(const double& amount) override;
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
		void request_cash(const double& amount) override;
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
		void request_cash(const double& amount) override;
	};

#endif // !state_h
