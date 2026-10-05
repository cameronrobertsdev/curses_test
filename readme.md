# NCurses Game

### A Game Made to learn more about the NCurses Library

Made by Cameron Roberts 2026

## Features

    - Gameplay
    - Terminal Based Graphics
    - Support for Computers(Some, not all of them)

## Building From Source

Here are some instructions for building the project from source. The project has
only been built on an Arch Linux Installation and some additional configuration will
likely be necessary to get it working on Windows or MacOS.

### Step 1:

Open a terminal and run the following command:

``` console
git clone https://github.com/cameronrobertsdev/curses_test
```

Navigate to the new directory and ensure you have CMake installed with:

``` console
CMake --version
```

If you don't have CMake, install it using your package manager. E.g.

``` console
sudo pacman -S CMake
```

``` powershell 
winget install CMake
```

etc.

### Step 2:

Configure CMake by running the following command:

``` console
CMake -B build -S. -G Ninja -DCMAKE_BUILD_TYPE=Release
```

The `-G` flag tells CMake what generator to use. If you omit this flag, CMake 
should use the default generator for your system. 

### Step 3:

Build the project by running the command:

`CMake --build build`

### Step 4:

Run the project from your terminal with:

`./build/src/curses_test`
