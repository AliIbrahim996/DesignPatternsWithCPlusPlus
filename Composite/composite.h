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
#endif // !composite_h

