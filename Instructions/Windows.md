# Build Instructions - Windows

## Follow instructions [here](https://doc.qt.io/qt-6/windows-building.html)

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
