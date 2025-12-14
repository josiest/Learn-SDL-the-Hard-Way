# Installing SDL

In order to use SDL, you'll of course first need to install it on your computer. There are a number
of ways to do this, some of which you can read on the
[official install instructions](https://github.com/libsdl-org/SDL/blob/main/INSTALL.md). However, at the current time
of writing, it neglects to mention one of the most fundamental ways of installing in my opinion: through your package
manager.

If you're on Linux, I'm going to assume you know how to use a package manager. The typical package manager on a Mac is
`brew` - but it's third party, and you'll need to install it following their instructions. The default package manager
on Windows actually doesn't have SDL! So instead we'll also need to use a third party package manager. I recommend
using `pacman` from the MSYS2 environment.

## Installing SDL on Windows with MSYS2

Why do I recommend using MSYS2? Well, it's because it emulates working in Linux pretty well with relatively little
headache. You can find the [installation instructions here](https://www.msys2.org/). Once you have it installed the
typical process of installing a package goes

```shell
pacman -Syu # to update the package manager
pacman -Ss <search keyword> # to search for the package name
pacman -S <package name> # to install the package
```

For example, if you type

```shell
pacman -Ss SDL3
```
You'll get a list of available packages that have SDL3 in the name. MSYS2 has a lot of different backends, so you'll
need to choose which backend you use and stay consistent! I believe the default backend is ucrt64. So installing SDL3
in the default backend looks like

```shell
pacman -S mingw-w64-ucrt-x86_64-sdl3
```