# #TeamEo: Indie Studio

This is the repository for the Eo team's Indie Studio project.

## Compilation requirements
### Linux

On Linux (or any UNIX system), you have to make sure to have Irrlicht installed on your machine.
This can be tested by doing:
```bash
sudo updatedb && locate Irrlicht.so
```
This should tell you if you have the library and where it is.
It should be in one of the following directories to be found:
- /usr/local/lib
- /usr/lib

Irrlicht include files should also be found in one the following directories:
- /usr/local/include/irrlicht
- /usr/include/irrlicht

### Windows

On Windows, you need to make sure to have installed:
- Visual Studio Professional (version 15 or higher is preferred)
- DirectX (version 11 or higher is preferred)

Irrlicht is to be compiled manually, here are the steps:
- Download [Irrlicht 1.8.4](http://downloads.sourceforge.net/irrlicht/irrlicht-1.8.4.zip) or higher
- Extract it and go to the resulting directory
- Go to "source/Irrlicht/" and open "Irrlicht12.0.vcxproj" in Visual Studio
- In Visual Studio, in the top bar, replace "Debug" by "Release" and "x86" by "x64"
- Right-click on the bold "Irrlicht" in the Explorer and select "Properties"
- Go to "Configuration Properties" > "General" and pick:
    - your installed SDK in the SDK category
    - "Visual Studio 2017" for the platform toolchain category
- Click "Apply" then "OK"
- Right-click on the bold Irrlicht in the explorer and click on "Generate"

Irrlicht shall be compiling and if everything succeeds, you can continue to follow these steps:

- Go back to the Irrlicht base directory and copy "bin/", "lib/" and "include/"
- Paste them in the "cpp_indie_studio/libs/irrlicht/" folder

## Compilation

Once everything is ready, create a build/ folder (or empty it if it already exists) and execute the following commands:
```bash
cmake .. && cmake --build .
```

The final binary shall now be found in the bin/ folder.
