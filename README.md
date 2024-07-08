# Olaf RPG

Work in Progress

---

## How to get it working (Windows)

1. [install Chocolatey](https://chocolatey.org/install)
2. install the **MinGW-w64** package by running this in an **ADMINISTRATOR!** terminal:
`choco install mingw`
- If this fails, check that you have installed chocolatey correctly, try restarting your computer.
3. To check if **MinGW-w64** installed correctly, open a new terminal and run:  
`g++ --version`  
You should get something like this:  
`g++.exe (x86_64-posix-seh-rev0, Built by MinGW-Builds project) 13.2.0`
4. install the **C/C++ Vscode extension** [here](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
5. [install git](https://git-scm.com/book/en/v2/Getting-Started-The-Command-Line) if you haven't already.  
6. run the following to test if everything was set up properly:
`python manage.py init build`