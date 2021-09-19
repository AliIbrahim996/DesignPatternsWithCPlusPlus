#include "composite.h"
using namespace FileExample;
using namespace AlbumExample;

int main(int argc, char** argv)
{
	IFile* root = new Directory("Lectures");
	IFile* dp = new Directory("Design patterns");
	root->add(dp);
	dp->add(new File("Composite.pdf"));
	dp->add(new File("Adapter.pdf"));
	dp->add(new File("Strategy.pdf"));
	root->add(new File("exam.pdf"));
	root->get_info();

	std::cout << "\n** Album example **\n";

	Component* album = new Album("Taylor Swift 1989");
	album->add_component(new Song("Blank Space"));
	album->add_component(new Song("Welcome To New York"));

	Component* duo = new Album("Taylor Duos");

	duo->add_component(new Song("Who says, Gomez"));
	duo->add_component(new Song("Jenny From the Block, Jay Lo"));
	album->add_component(duo);
	album->display_info();
	return 0;
}
