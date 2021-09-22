#ifndef composite_h
	#define composite_h
#include<string>
#include<list>
#include<iostream>
namespace FileExample {
	class IFile
	{
	protected:
		std::string name_;
	public:
		IFile(const std::string& name);
		virtual void get_info() = 0;
		virtual void add(std::unique_ptr<IFile>& file) = 0;
	};

	class File : public IFile
	{
	public:
		File(const std::string& name);
		void get_info() override;
		void add(std::unique_ptr<IFile>& file) override;
	};

	class Directory : public IFile
	{
	private:
		std::list<std::unique_ptr<IFile>> file_list_;
	public:
		Directory(const std::string& name);
		void get_info() override;
		void add(std::unique_ptr<IFile>& file) override;
	};
}

namespace AlbumExample
{
	class Component
	{
	protected:
		std::string name_;
	public:
		Component(const std::string& name);
		virtual void display_info() = 0;
		virtual void add_component(std::unique_ptr<Component>& component) = 0;
	};

	class Song : public Component
	{
	public:
		Song(const std::string& name);
		void display_info() override;
		void add_component(std::unique_ptr<Component>& component) override;
	};

	class Album : public Component
	{
	private:
		std::list<std::unique_ptr<Component>> songs_;
	public:
		Album(const std::string& name);
		void display_info() override;
		void add_component(std::unique_ptr<Component>& component) override;
	};
}
#endif // !composite_h

