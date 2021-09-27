#include "state.h"

/*ATM Machine*/
Atm::AtmMachine::AtmMachine(double balance)
{
	this->total_balance_ = balance;
	this->has_card_ = std::make_unique<HasCardState>(this);
	this->no_card_ = std::make_unique<NoCardState>(this);
	this->no_cash_ = std::make_unique<NoCashState>(this);
	this->ready_ = std::make_unique<ReadyState>(this);
	this->current_state_ = this->no_card_.get();
}

void Atm::AtmMachine::insert_card()
{
	this->current_state_->insert_card();
}

void Atm::AtmMachine::eject_card()
{
	this->current_state_->eject_card();
}

void Atm::AtmMachine::insert_password(const std::string& password)
{
	this->current_state_->insert_password(password);
}

void Atm::AtmMachine::request_cash(double amount)
{
	this->current_state_->request_cash(amount);
}

void Atm::AtmMachine::set_balance(double balance)
{
	this-> total_balance_ = balance;
}

double Atm::AtmMachine::get_balance()
{
	return this->total_balance_;
}

void Atm::AtmMachine::set_current_state(ATMState* state)
{
	this->current_state_ = state;
}

Atm::ATMState* Atm::AtmMachine::get_current_state()
{
	// TODO: insert return statement here
	return this->current_state_;
}

Atm::ATMState*  Atm::AtmMachine::get_no_card_state()
{
	return this->no_card_.get();
}

Atm::ATMState* Atm::AtmMachine::get_has_card_state()
{
	return this->has_card_.get();
}

Atm::ATMState* Atm::AtmMachine::get_no_cash_state()
{
	return this->no_cash_.get();
}

Atm::ATMState* Atm::AtmMachine::get_ready_state()
{
	return this->ready_.get();
}
/*Has card state*/
Atm::HasCardState::HasCardState(AtmMachine* atm) : atm_(atm){}

void Atm::HasCardState::insert_card()
{
	std::cout << "There is a card already!\n";
}

void Atm::HasCardState::eject_card()
{
	std::cout << "Card ejected!!\n";
	this->atm_->set_current_state(this->atm_->get_no_card_state());
}

void Atm::HasCardState::insert_password(const std::string& password)
{
	if (password == "1234567")
	{
		std::cout << "Password correct!\n";
		this->atm_->set_current_state(this->atm_->get_ready_state());
	}
	else
	{
		std::cout << "Password wrong!\n";
	}
}

void Atm::HasCardState::request_cash(double amount)
{
	std::cout << "Enter your password first!\n";
}

/*No card state*/
Atm::NoCardState::NoCardState(AtmMachine* atm) : atm_(atm) {}

void Atm::NoCardState::insert_card()
{
	this->atm_->set_current_state(this->atm_->get_has_card_state());
	std::cout << "Enter your password!\n";
}

void Atm::NoCardState::eject_card()
{
	std::cout << "no card detected!!\n";
}

void Atm::NoCardState::insert_password(const std::string& password)
{
	std::cout << "Insert card first!!\n";
}

void Atm::NoCardState::request_cash(double amount)
{
	std::cout << "Insert card first!!\n";
}
/*No cash state*/
Atm::NoCashState::NoCashState(AtmMachine* atm) : atm_(atm) {}

void Atm::NoCashState::insert_card()
{
	std::cout << "no cash try again!!\n";
}

void Atm::NoCashState::eject_card()
{
	std::cout << "no card detected!!\n";
}

void Atm::NoCashState::insert_password(const std::string& password)
{
	std::cout << "no card detected!!\n";
}

void Atm::NoCashState::request_cash(double amount)
{
	std::cout << "no card detected!!\n";
}
/*Ready  state*/
Atm::ReadyState::ReadyState(AtmMachine* atm) : atm_(atm) {}

void Atm::ReadyState::insert_card()
{
	std::cout << "Card is already inserted!!\n";
}

void Atm::ReadyState::eject_card()
{
	std::cout << "Card ejected!!\n";
	this->atm_->set_current_state(this->atm_->get_no_card_state());
}

void Atm::ReadyState::insert_password(const std::string& password)
{
	std::cout << "Password is already inserted!!\n";
}

void Atm::ReadyState::request_cash(double amount)
{
	double balance = this->atm_->get_balance();
	if(balance >= amount)
	{
		std::cout << "Take your money!!\n";
		this->atm_->set_balance(balance - amount);
		balance = this->atm_->get_balance();
		this->eject_card();
		
		if(balance == 0)
		{
			this->atm_->set_current_state(this->atm_->get_no_cash_state());
		}
		std::cout << "Your total balance is: " << balance<<std::endl;
	}
	else
	{
		std::cout << "No enough money!\n please input a balance equal or less than " << balance <<"!\n";
	}
}
