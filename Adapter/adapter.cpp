#include "adapter.h"


void Adapter::Instagram::post_image(std::string img)
{
	std::cout << "Instagram Image: " << img << std::endl;
}

void Adapter::Instagram::post_video(std::string video)
{
	std::cout << "Instagram Video: " << video << std::endl;
}


Adapter::InstagramAdapter::InstagramAdapter(Instagram* inst)
{
	this->instagram_ = std::move(inst);
}

void Adapter::InstagramAdapter::post_image(std::string img)
{
	this->instagram_->post_image(img);
}

void Adapter::InstagramAdapter::post_video(std::string video)
{
	this->instagram_->post_video(video);
}

void Adapter::InstagramAdapter::post_text(std::string text)
{
	throw std::runtime_error("post text is not supported in Instagram!\n");
}

void Adapter::Facebook::post_facebook_image(std::string img)
{
	std::cout << "Facebook Image: " << img << std::endl;
}

void Adapter::Facebook::post_facebook_video(std::string video)
{
	std::cout << "Facebook Video: " << video << std::endl;
}

void Adapter::Facebook::post_facebook_text(std::string text)
{
	std::cout << "Facebook text: " << text << std::endl;
}

void Adapter::FacebookAdapter::post_image(std::string img)
{
	post_facebook_image(img);
}


void Adapter::FacebookAdapter::post_video(std::string video)
{
	post_facebook_video(video);
}

void Adapter::FacebookAdapter::post_text(std::string text)
{
	post_facebook_text(text);
}
