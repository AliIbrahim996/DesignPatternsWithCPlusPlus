#include "composite.h"
using namespace FileExample;

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
	return 0;
}
