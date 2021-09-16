#ifndef adapter_h
#define adapter_h
#include<string>
#include<memory>
#include<iostream>
namespace Adapter
{
	class SocialAdapter
	{
	public:
		virtual void post_image(std::string img) = 0;
		virtual void post_video(std::string video) = 0;
		virtual void post_text(std::string text) = 0;
	};

	class Instagram
	{
	public:
		void post_image(std::string img);
		void post_video(std::string video);
	};

	class InstagramAdapter : public SocialAdapter
	{
	private:
		Instagram* instagram_;
	public:
		InstagramAdapter(Instagram* inst);
		void post_image(std::string img) override;
		void post_video(std::string video) override;
		void post_text(std::string text) override;
	};

	class Facebook
	{
	public:
		void post_facebook_image(std::string img);
		void post_facebook_video(std::string video);
		void post_facebook_text(std::string text);
	};

	class FacebookAdapter : public SocialAdapter, public Facebook
	{
	public:
		void post_image(std::string img) override;
		void post_video(std::string video) override;
		void post_text(std::string text) override;
	};
}
#endif // !adapter_h
