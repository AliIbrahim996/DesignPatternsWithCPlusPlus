<p align="center">
<h1 align ="center" >Design Patterns With C++</H1> 
</p>
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#Requirements">Requirements</a>
    </li>
    <li>
        <a href = "#Getting-start">Getting-start</a>
    </li>
    <li>
        <a href="#contact">Contact</a>
    </li>
  </ol>
</details>
# Requirements

1) [Python](https://www.python.org/downloads/ "Python download page")

2) [Visual Studio ( 2019 recomended )](https://visualstudio.microsoft.com/downloads/ "Visula studio download page")

3) [conan](https://docs.conan.io/en/latest/installation.html)

# Getting-start

**_This is the instruction you need to build and use the project._**
<br/>
* After you install python you need to install `conan`.
<br/>
* To install Conan using pip, you need Python>=3.6 distribution installed on your machine:
```bash
pip install conan
```
<br/>

* Create a conan profile:
```bash
conan profile new win_vc15_x64 --detect
```
* Go to your user profile `.conan/profiles` folder and then update the profile you creted with this settings:
```
[settings]
os=Windows
os_build=Windows
arch=x86_64
arch_build=x86_64
compiler=Visual Studio
compiler.version=16
os=Windows
build_type=Release

[options]
[build_requires]
[env]
```

1. ### Clone the repository

```bat
  git clone https://github.com/AliIbrahim996/DesignPatternsWithCPlusPlus.git DesignPattern
  cd DesignPattern
  cd vs
```
2. ### Run create_solution.bat.bat to configure and create the strcuture of the project

# Contact

 Ali ibrahim - ali.ibrahim.2@lit-co.net 
  <br/>
 gmail: allosheribraheem38@gmail.com
 outlook: eng.aliibrahim.96@outlook.coom
  <br/>
 LinkedIn: https://www.linkedin.com/in/ali-ibrahim-b978b4181/ 
  <br/>
 &copy; 2022

