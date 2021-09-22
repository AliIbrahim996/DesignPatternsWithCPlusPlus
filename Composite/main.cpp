#include "composite.h"
using namespace FileExample;
using namespace AlbumExample;

int main(int argc, char** argv)
{
	std::unique_ptr<IFile> root =std::make_unique<Directory>("Lectures");
	std::unique_ptr<IFile> dp = std::make_unique<Directory>("Design patterns");

	std::unique_ptr<IFile> com_pdf = std::make_unique<File>("Composite.pdf");
	std::unique_ptr<IFile> ad_pdf = std::make_unique<File>("Adapter.pdf");
	std::unique_ptr<IFile> st_pdf = std::make_unique<File>("Strategy.pdf");
	std::unique_ptr<IFile> ex_pdf = std::make_unique<File>("exam.pdf");

	dp->add(com_pdf);
	dp->add(ad_pdf);
	dp->add(st_pdf);

	root->add(dp);
	root->add(ex_pdf);
	root->get_info();

	std::cout << "\n** Album example **\n";

	std::unique_ptr<Component> album = std::make_unique<Album>("Taylor Swift 1989");
	std::unique_ptr<Component> blank_space = std::make_unique<Song>("Blank Space");
	std::unique_ptr<Component> welcome_to_new_york = std::make_unique<Song>("Welcome To New York");
	album->add_component(blank_space);
	album->add_component(welcome_to_new_york);

	std::unique_ptr<Component> duo = std::make_unique<Album>("Taylor Duos");
	std::unique_ptr<Component> who_says = std::make_unique<Song>("Who says, Gomez");
	std::unique_ptr<Component> jen_from_the_block = std::make_unique<Song>("Jenny From the Block, Jay Lo");

	duo->add_component(who_says);
	duo->add_component(jen_from_the_block);
	album->add_component(duo);
	album->display_info();
	return 0;
}
