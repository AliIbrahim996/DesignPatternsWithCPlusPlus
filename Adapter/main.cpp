#include "adapter.h"
#include<list>
int main(int argc, char** argv)
{
	std::string img = "https://../../demo.png";
	std::string text = "hello";
	std::string video = "https://../../demo.mp4";
	std::unique_ptr<Adapter::Instagram> inst = std::make_unique<Adapter::Instagram>();
	std::unique_ptr<Adapter::SocialAdapter> fb_adapter = std::make_unique<Adapter::FacebookAdapter>();
	std::unique_ptr<Adapter::SocialAdapter> inst_adapter = std::make_unique<Adapter::InstagramAdapter>(inst);
	std::list<std::unique_ptr<Adapter::SocialAdapter>> adapters;
	adapters.push_back(std::move(fb_adapter));
	adapters.push_back(std::move(inst_adapter));

	for(auto& adpter: adapters)
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
