from conans import ConanFile, CMake, tools

class Design_Patterns_Workspace(ConanFile):
    name = "Design_Patterns_Workspace"
    generators = "virtualenv"

    scm = {
        "type": "git",
        "subfolder": "Design_Patterns_Workspace",
        "url": "https://github.com/AliIbrahim996/DesignPatternsWithCPlusPlus.git",
        "revision": "develop" # current branch until merge.
     }

    def build_requirements(self):
        self.build_requires("cmake/3.23.2")
        self.build_requires("doxygen/1.9.4")
        self.build_requires("ninja/1.11.0")