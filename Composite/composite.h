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
		IFile(std::string name);
		virtual void get_info() = 0;
		virtual void add(IFile* file) = 0;
	};

	class File : public IFile
	{
	public:
		File(std::string name);
		void get_info() override;
		void add(IFile* file) override;
	};

	class Directory : public IFile
	{
	private:
		std::list<IFile*> file_list_;
	public:
		Directory(std::string name);
		void get_info() override;
		void add(IFile* file) override;
	};
}

namespace AlbumExample
{
	class Component
	{
	protected:
		std::string name;
	public:
		Component(std::string name);
		virtual void display_info() = 0;
		virtual void add_component(Component* component);
	};

	class Song : public Component
	{
	public:
		Song(std::string name);
		void display_info() override;
	};

	class Album : public Component
	{
	private:
		std::list<Component*> songs_;
	public:
		Album(std::string name);
		void display_info() override;
		void add_component(Component* component) override;
	};
}
#endif // !composite_h

