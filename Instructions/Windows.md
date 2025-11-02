# Build Instructions - Windows

## Prerequisites

- CMake (Version 3.22 or newer)
- Ninja
- Python 3
- Git
- Visual Studio 2022 with C++ desktop development selected
- Perl

## Pre-compilation steps - Add ninja to PATH
1. In your windows search bar type in "Edit the system enviroment variables" and open it.
2. System Properties menu will show up, click the button labeled "Enviroment Variables..."
3. Go to the "System variables" section and click Path
4. Click "Edit..."
5. Click "New" button
6. Add in the path to where you extracted ninja to.

## Building Qt -  Steps
1. Open terminal (Developer Command Prompt for VS 2022)
2. Run ``git clone https://github.com/qt/qt5 -b 5.15.17`` to clone Qt5 source code
3. Go to the directory of the cloned qt5's source code in terminal (``cd qt5``)
4. Run ``perl init-repository`` to download all dependencies of Qt5 (this will take a while)
5. After that is done, run ``nmake build`` (the compiling process will take a while)
6. After compiling, run ``nmake install`` to install Qt5 (typically in ``C:\Qt\Qt-5.15.17``)
7. Close terminal

## Building Qt - Post-Install
1. In your windows search bar type in "Edit the system enviroment variables" and open it.
2. System Properties menu will show up, click the button labeled "Enviroment Variables..."
3. Go to the "System variables" section and click Path
4. Click "Edit..."
5. Click "New" button
6. Add in INSTALLED_QT5_PATH (typically ``C:\Qt\Qt-5.15.17``)

## Configuring Visual Studio 2022
1. Launch Visual Studio 2022
2. Click "Continue without code"
3. At the top click "Extensions > Manage Extensions..."
4. Search Up "Qt Vs Tools"
5. Click on "Qt Visual Studio Tools" and then click "Install"
6. Close Visual Studio 2022 to start installing QT Vs Tools
7. After installing, launch Visual Studio 2022 again
8. Click "Extensions > Qt VS Tools > Qt Versions"
9. In the window click "Add"
10. Click the three dots near "Location"
11. Navigate to the path of Qt5 (typically ``C:\Qt\Qt-5.15.17``) and click the bin directory
12. Select qmake or qtpaths and click Open
13. After that click "Ok" in the Qt Versions window

## Building the app
1. Open terminal (Developer Command Prompt for VS 2022)
2. Change directory to the cloned source code of HTTAGEN ``cd (SRC_PATH)``
3. Create a "build" directory ``mkdir build`` and change to it (``cd build``)
4. Run ``cmake ..``  and wait until it finishes.
5. Open the build directory in Windows Explorer (``explorer .``)
6. open the httagen-gui solution file (``httagen-gui.sln``)
7. Select "Release" build instead of "Debug"
8. Click "Build > Build Solution"
9. Successful build should be in `(SRC_PATH)\build\Release`
10. In order to run this app on machines that don't have Qt5 installed run ``windeployqt --no-translations .``
