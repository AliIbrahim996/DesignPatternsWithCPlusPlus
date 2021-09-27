#include "state.h"

using namespace Atm;

int main(int argc, char** argv)
{
	std::unique_ptr<AtmMachine> atm = std::make_unique<AtmMachine>(15000);
	atm->insert_card();
	std::string password;
	std::cin >> password;
	atm->insert_password(password);
	double balance;
	std::cout << "How much money do you want?\n";
	std::cin >> balance;
	atm->request_cash(balance);
	atm->insert_card();
}
