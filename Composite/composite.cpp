#include "composite.h"

FileExample::IFile::IFile(std::string name)
{
	this->name_ = name;
}

FileExample::File::File(std::string name) : IFile(name){}

void FileExample::File::get_info()
{
	std::cout << " File: " << this->name_ <<std::endl;
}

void FileExample::File::add(IFile* file)
{
	throw std::runtime_error("this functionality is not available for files!\n");
}

FileExample::Directory::Directory(std::string name): IFile(name){}

void FileExample::Directory::get_info()
{
	std::cout <<"** Directory: " << this->name_ << " content:\n";
	
	for(IFile* element:this->file_list_)
	{
		element->get_info();
	}
	std::cout << " End of directory "<< this->name_ << std::endl;
}

void FileExample::Directory::add(IFile* file)
{
	this->file_list_.push_back(file);
}
