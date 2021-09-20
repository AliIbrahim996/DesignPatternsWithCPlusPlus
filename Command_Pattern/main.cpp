#include "command.h"

using namespace CommandPattern;
void set_command(RemoteControl* remote_control, ICommand* new_command)
{
	remote_control->set_command(new_command);
	remote_control->press_button();
}
int main(int argc, char** argv)
{
	RemoteControl* remote_control = new RemoteControl();
	Light* light = new Light();
	TV* tv = new TV();

	LightOnCommand* light_on = new LightOnCommand(light);
	LightOffCommand* light_off = new LightOffCommand(light);

	TVOnCommand* tv_on =  new TVOnCommand(tv);
	TVOffCommand* tv_off =  new TVOffCommand(tv);
	TvVolUpCommand* volume_up = new TvVolUpCommand(tv);
	TvVolDownCommand* volume_down = new TvVolDownCommand(tv);
	bool flag = true;
	std::cout << "**/\ welcome **\n";
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
