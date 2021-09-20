#include "state.h"

using namespace Atm;

int main(int argc, char** argv)
{
	AtmMachine* atm = new AtmMachine(15000);
	atm->insert_card();
	std::string password;
	std::cin >> password;
	atm->insert_password(password);
	double balance;
	std::cout << "How much money do you want?\n";
	std::cin >> balance;
	atm->request_cash(balance);

}
