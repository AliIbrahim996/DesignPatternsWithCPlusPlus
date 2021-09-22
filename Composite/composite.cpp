#include "composite.h"

FileExample::IFile::IFile(const std::string& name)
{
	this->name_ = name;
}

FileExample::File::File(const std::string& name) : IFile(name){}

void FileExample::File::get_info()
{
	std::cout << " File: " << this->name_ <<std::endl;
}

void FileExample::File::add(std::unique_ptr<IFile>& file)
{
	throw std::runtime_error("this functionality is not available for files!\n");
}

FileExample::Directory::Directory(const std::string& name): IFile(name){}

void FileExample::Directory::get_info()
{
	std::cout <<"** Directory: " << this->name_ << " content:\n";
	
	for(auto& element:this->file_list_)
	{
		element->get_info();
	}
	std::cout << " End of directory "<< this->name_ << std::endl;
}

void FileExample::Directory::add(std::unique_ptr<IFile>& file)
{
	this->file_list_.push_back(std::move(file));
}

AlbumExample::Component::Component(const std::string& name)
{
	this->name_ = name;
}

AlbumExample::Song::Song(const std::string& name): Component(name){}

void AlbumExample::Song::display_info()
{
	std::cout << "Song: " << this->name_ << std::endl;
}

void AlbumExample::Song::add_component(std::unique_ptr<Component>& component)
{
	throw std::runtime_error("this operation is not supported!\n");
}

/*void AlbumExample::Album::display_info()
{
	
}*/

AlbumExample::Album::Album(const std::string& name) : Component(name){}

void AlbumExample::Album::display_info()
{
	std::cout << "Album: " << this->name_ << " {\n";
	for (auto& component : songs_)
	{
		component->display_info();
	}
	std::cout << "}\n";
}

void AlbumExample::Album::add_component(std::unique_ptr<Component>& component)
{
	this->songs_.push_back(std::move(component));
}
