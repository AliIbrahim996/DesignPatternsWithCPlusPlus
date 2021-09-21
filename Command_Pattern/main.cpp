#include "command.h"

using namespace CommandPattern;
void set_command(const std::unique_ptr<RemoteControl>& remote_control, std::unique_ptr<ICommand>& new_command)
{
	remote_control->set_command(new_command);
	remote_control->press_button();
}
int main(int argc, char** argv)
{
	std::unique_ptr<RemoteControl> remote_control = std::make_unique<RemoteControl>();
	std::unique_ptr<Light> light = std::make_unique<Light>();
	std::unique_ptr<TV> tv = std::make_unique<TV>();

	std::unique_ptr<ICommand> light_on = std::make_unique<LightOnCommand>(light);
	std::unique_ptr<ICommand> light_off = std::make_unique<LightOffCommand>(light);

	std::unique_ptr<ICommand> tv_on = std::make_unique<TVOnCommand>(tv);
	std::unique_ptr<ICommand> tv_off = std::make_unique<TVOffCommand>(tv);
	std::unique_ptr<ICommand> volume_up = std::make_unique<TvVolUpCommand>(tv);
	std::unique_ptr<ICommand> volume_down = std::make_unique<TvVolDownCommand>(tv);
	bool flag = true;
	std::cout << "**/\\ welcome **\n";
	while(flag)
	{
		std::cout << "Choose one off these commands:\n";
		std::cout << "1) To turn the TV on\n2) To turn the TV off\n";
		std::cout << "3) To turn the TV volume up\n4) To turn the TV volume down\n";
		std::cout << "5) To turn the light on\n6) To turn the light off\n7)to end the program\n";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1: set_command(remote_control, tv_on); break;
		case 2: set_command(remote_control, tv_off); break;
		case 3: set_command(remote_control, volume_up); break;
		case 4: set_command(remote_control, volume_down); break;
		case 5: set_command(remote_control, light_on); break;
		case 6: set_command(remote_control, light_off); break;
		case 7: flag= false; break;
		default:
			std::cout << "Choose only from the command list!\n";
			break;
		}
	}
	std::cout << "Finished!\n Thank you\n";
}
