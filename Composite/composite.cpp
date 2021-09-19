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

AlbumExample::Component::Component(std::string name)
{
	this->name = name;
}

void AlbumExample::Component::add_component(Component* component)
{
	throw std::runtime_error("Unsupported operation!\n");
}

AlbumExample::Song::Song(std::string name): Component(name){}

void AlbumExample::Song::display_info()
{
	std::cout << "Song: " << this->name << std::endl;
}

AlbumExample::Album::Album(std::string name) : Component(name){}

void AlbumExample::Album::display_info()
{
	std::cout << "Album: " << this->name << " {\n";
	for(Component* component: songs_)
	{
		component->display_info();
	}
	std::cout << "}\n";
}

void AlbumExample::Album::add_component(Component* component)
{
	this->songs_.push_back(component);
}
