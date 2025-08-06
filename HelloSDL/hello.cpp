#include <SDL2/SDL.h>
#include <cstdint>
#include <string>

// We'll just do a few simple things in this example:
// - boot up SDL
// - create a window with a custom name
// - wait for a couple seconds then quit the program

// We'll need to initialize the SDL library to use it, but it's possible something may go wrong.
// This definition will clarify the logic of what to do when something does go wrong.
#define SDL_INIT_SUCCESS 0

int main(int argc, char * argv[])
{
    // These are arbitrary values we'll use to configure our program. Feel free to change them to your liking.
    // We've hard-coded them for the sake of simplicity, but in the future we may want to read them from a file.
    const std::string window_name = "Hello SDL2";
    const int window_width = 640;
    const int window_height = 480;
    const std::uint32_t program_quit_delay_ms = 2000; // 2000 ms = 2 sec

    // For the rest of this file, any time you see a function call that starts with "SDL_",
    // look up the function on https://wiki.libsdl.org and ask yourself these questions:
    // - What does the function do?
    // - How do the arguments to the function change the function's outcome?
    // - What does the function return and what can I do with that information?
    if (SDL_Init(SDL_INIT_VIDEO) != SDL_INIT_SUCCESS) {
        SDL_Log("Couldn't initialize SDL2: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    // Pop Quiz (SDL):
    // 1.a) If I wanted to use audio and a controller in addition to video, how would I initialize those?
    // 1.b) If we hadn't defined the macro SDL_INIT_SUCCESS earlier, the conditional expression would have been
    //      SDL_Init(SDL_INIT_VIDEO) != 0. Is it clear what role 0 plays? How might that expression be misread?

    SDL_Window * window = SDL_CreateWindow(window_name.c_str(),
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                           window_width, window_height,
                                           SDL_WINDOW_SHOWN);

    // Pop Quiz (SDL):
    // 2.a) How would you make the window appear centered on the screen?
    // 2.b) Why might I have chosen to put SDL_WINDOW_SHOWN in the last argument - does it need to be there?
    // 2.c) If you add other window flags, why would you keep or remove SDL_WINDOW_SHOWN?

    if (window == nullptr) {
        SDL_Log("Couldn't create a window in SDL2: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Delay(program_quit_delay_ms);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Pop Quiz (SDL and C++):
    // 3.a) Why do we need to call SDL_Quit() before we return EXIT_FAILURE if the window wasn't created?
    // 3.b) What happens if we remove the calls to SDL_DestroyWindow and SDL_Quit?

    return EXIT_SUCCESS;
}

// Answer Key:
// 1.a) SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD)
// 1.b) 0 is often used as a boolean value for false: you might incorrectly assume 0 means SDL didn't initialize
//
// 2.a) Use SDL_WINDOWPOS_CENTERED
// 2.b) SDL_WINDOW_SHOWN isn't needed, and is in fact ignored unless SDL_WINDOW_HIDDEN was previously set.
//      I add it here because it's unclear what the last argument does if you just pass a zero.
// 2.c) You may want to remove SDL_WINDOW_SHOWN if you pass other window flags because it's ignored.
//      However, you may want to keep the flag just to be explicit/descriptive.
//
// 3.a) SDL allocates resources when its subsystems are initialized.
//      These resources always need to be deallocated to prevent a memory leak.
// 3.b) Memory leak!
