import conans

class RG20_workspace_win_adtf3(conans.ConanFile):
    name = "Design_Patterns_Workspace"
    generators = "virtualenv"

    #https://docs.conan.io/en/latest/reference/conanfile/methods.html#build-requirements
    def build_requirements(self):
        self.build_requires("cmake/3.23.2")  # needed for cmake call of conan workspace
        self.build_requires("doxygen/1.9.4")
        self.build_requires("ninja/1.11.0")