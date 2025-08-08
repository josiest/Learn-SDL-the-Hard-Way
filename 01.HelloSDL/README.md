# Installing SDL

In order to use SDL, you'll of course first need to install it on your computer. There are a number
of ways to do this, most of which can be learned from reading this page: https://wiki.libsdl.org/SDL2/Installation.

To review the knowledge you can find there, there are two main ways to install: through a package manager or through
building the library from source. Package managers are a great way to install a stable version of the library,
especially if you're using a Unix-like system. However, there are a number of reasons why you might want to build
from source.

- You may want to use a more recent version of the library than what's available through the package manager
- You may want more control over where and how the library is installed
- If you're on Windows, the native package manager doesn't offer SDL, and you may experience issues when relying on
  third-party package managers like `pacman` in the msys environment.

It's for these reasons I typically prefer to install SDL through the package manager on Linux, but on Windows I usually
build from source with cmake. There are a couple nuances to installing on Windows that I'd recommend that aren't
covered on the official wiki, so I'll go over them briefly here.

## Installing SDL on Windows

At a high level, my recommended workflow for installing SDL on Windows looks like this:

1. Clone the library to some local directory on your computer
2. Build the library with cmake, using Ninja as the generator
3. Install the library somewhere your development environment can use it

All of these steps assume you're familiar with building programs in cmake from the command line. In case you're not
familiar, let's take a moment to learn.

### Setting up the Terminal

1. While windows does come installed with a few different command line clients, I'd highly recommend installing
[git bash](https://git-scm.com/downloads). It has some limitations, but it sets up a really nice bash-like environment
and it's pretty stable and well-supported since git is so popular.
2. You'll need to install CMake and a C++ compiler. Both of these things can be installed through the package manager
   built into windows: `winget`.

   For the compiler there are a few options, but I'd recommend installing the Ninja build system. This will give you
   access to a couple different compiler options, as well as an excellent "generator" option when configuring SDL with
   cmake.


### Building and installing SDL

Once you have the terminal set up, the next step is to clone the SDL git project. The commands to do this are exactly 
the same as they are in the cmake section on the official installation wiki page linked above. However, the commands
for building and installing are going to be a little different on Windows.

In particular, when you're configuring the build for cmake, you'll likely want to give it a specific generator to
specify what toolsets you'll be using to build the library. I'd highly recommend using Ninja here. The command looks
like this:

```shell
cmake .. -DCMAKE_BUILD_TYPE=Release -G Ninja
```

Finally, when you're installing the library, you'll want to make sure that it's installed to a place your
development environment can access. By default, it will likely install to `C:/Program Files (x86)/SDL2`. This is
probably accessible enough, but if you're having trouble finding the SDL package when you build with cmake,
you might consider installing the  library somewhere specific by giving the install command a `--prefix` argument.

If you're using an IDE for example, you might install SDL to some directory you know the IDE will use to look for
external libraries.

Wherever you install SDL, there's a high likelihood it will require admin privileges to write to. Windows has no `sudo`
command, so you'll need to open the terminal "as administrator" in order to run the install command.