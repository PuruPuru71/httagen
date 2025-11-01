# HTTP Authorization Token Generator (HTTAGEN)

## How to Compile
1. Install [Qt](https://www.qt.io/) 5.15.7 according to your distribution instructions.
2. Install [CMake](https://cmake.org/) according to your distribution instructions.
3. Create a directory called "build" inside the cloned source code.
4. Go into the newly created "build" directory using a Terminal
5. run "cmake .." to generate necessary files for compiling in the "build" directory
6. run "make" to compile the source code into a binary

## What Does it do?
This tool can be used to generate [HTTP Basic Authentication](https://en.wikipedia.org/wiki/Basic_access_authentication) tokens from provided username and password

## Credits
base64.hpp: base64 by Tobias Locker on [GitHub](https://github.com/tobiaslocker/base64)
