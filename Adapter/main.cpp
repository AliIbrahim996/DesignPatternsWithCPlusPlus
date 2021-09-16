#include "adapter.h"
#include<list>
int main(int argc, char** argv)
{
	std::string img = "https://../../demo.png";
	std::string text = "hello";
	std::string video = "https://../../demo.mp4";
	Adapter::Instagram* inst = new Adapter::Instagram;
	Adapter::SocialAdapter* fb_adapter = new Adapter::FacebookAdapter();
	Adapter::SocialAdapter* inst_adapter = new Adapter::InstagramAdapter(inst);
	std::list<Adapter::SocialAdapter*> adapters;
	adapters.push_back(fb_adapter);
	adapters.push_back(inst_adapter);

	for(Adapter::SocialAdapter* adpter: adapters)
	{
		adpter->post_image(img);
		std::cout << "=====================\n";
		adpter->post_video(video);
		std::cout << "=====================\n";
		try {
			adpter->post_text(text);
		}
		catch(std::exception& error)
		{
			std::cout << error.what();
		}
	}

	return 0;
}
